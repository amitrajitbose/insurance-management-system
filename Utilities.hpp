void export_userprofile(string usertoken, User obj)
{
    string path = "./data/" + usertoken + "_userprofile.txt";
    string line;
    //create an output stream to write to the file
    //append the new lines to the end of the file

    /*
    FORMAT
    ------
    name
    email
    dob
    address
    contactNumber
    policycount
    */
    fstream myfileI;
    myfileI.open(path, fstream::app);
    if (myfileI.is_open())
    {
        myfileI << obj.name << endl << obj.email << endl << obj.dob << endl << obj.address << endl << obj.contactNumber << endl << obj.policycount << endl;
        myfileI.close();
    }
    else cout << "Unable to open file for writing";
}

User import_userprofile(string usertoken)
{
    User obj;
    string line;
    string path = "./data/" + usertoken + "_userprofile.txt";
    fstream myfileO;
    myfileO.open(path);
    if (myfileO.is_open())
    {
        getline (myfileO,line);
        obj.name = line;
        getline (myfileO,line);
        obj.email = line;
        getline (myfileO,line);
        obj.dob = line;
        getline (myfileO,line);
        obj.address = line;
        getline (myfileO,line);
        obj.contactNumber = line;
        getline (myfileO,line);
        obj.policycount = stoi(line);
        myfileO.close();
    }
    
    else cout << "Unable to open file for reading";
    return obj;

}

int authenticateUser(string email, string password)
{
    /*
    Takes a email and password string
    matches the email with the emails in AUTH.txt
    If found, compares the password
    Response : 1 for Success, 0 For Bad Access
    */
    
    fstream myfileO;
    string emailtmp, passtmp;
    myfileO.open("./data/AUTH.txt");
    if (myfileO.is_open())
    {
        while ( getline (myfileO,emailtmp) )
        {
            getline(myfileO, passtmp);
            if(emailtmp.compare(email)==0 and passtmp.compare(password)==0)
            {
                return 1; //authentication success
            }
        }
        myfileO.close();
        return 0;
    }
    
    else 
        cout << "Unable to open AUTH file for authentication";
}

string getUserToken(string email)
{
    fstream myfileO;
    string emailtmp;
    string usertoken;
    myfileO.open("./data/TOKEN.txt");
    if (myfileO.is_open())
    {
        while ( getline (myfileO,emailtmp) )
        {
            getline(myfileO, usertoken);
            if(emailtmp.compare(email)==0)
            {
                return usertoken; //authentication success
            }
        }
        myfileO.close();
        return 0;
    }
    else 
        cout << "Unable to open AUTH file for authentication";
}

int getRandomToken()
{
    // generates random 6 digit number
    return rand() % 900000 + 100000;
}

void login()
{
    // This method is called when user wants to login
    //Authentication
    string useremail, password;
    char ch;
    cout << "Enter Your Email: ";
    getline(cin, useremail);
    getline(cin, useremail);
    cout << "Enter Your Password: ";
    ////////////////////// OS LEVEL STDIN CONTROL - WOKRS FOR LINUX UNIX Systems
    termios oldt;
    tcgetattr(STDIN_FILENO, &oldt);
    termios newt = oldt;
    newt.c_lflag &= ~ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &newt); // disabling echo
    getline(cin, password);
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt); // enabling echo
    cout << "\n" ;
    //////////////////////
    if(authenticateUser(useremail, password)==1)
    {
        cout << "Login Successful" << endl;
        // After login activities
        string usertoken = getUserToken(useremail);
        User user = import_userprofile(usertoken); //load user details
        user.showDetails(); //show user details //TODO ACTIVE POLICIES DISPLAY
        cout << "Do You Want To Create A New Insurance Policy? [Y/N]";
        char newpchoice;
        cin >> newpchoice;
        if(newpchoice=='Y' or newpchoice=='y')
        {
            if(user.policycount < 3)
            {
                Policy policy;
                policy.createNewPolicy(stoi(usertoken));
            }
        }
    }
    else
    {
        cout << "Login Failed" << endl;
    }
}

void signup()
{
    // This module is called when user wants to sign up
    User userobj;
    cout << "----------------------------------------------\n";
    cout << "***** FILL UP THE USER REGISTRATION FORM *****\n";
    cout << "----------------------------------------------\n";
    cout << "Enter Your Name: ";
    getline(cin, userobj.name);
    getline(cin, userobj.name);
    cout << "Enter Valid Email: ";
    getline(cin, userobj.email);
    userobj.userToken = getRandomToken();
    cout << "Enter Alphanumeric Password: ";
    ////////////////////// OS LEVEL STDIN CONTROL - WOKRS FOR LINUX UNIX Systems
    termios oldt;
    tcgetattr(STDIN_FILENO, &oldt);
    termios newt = oldt;
    newt.c_lflag &= ~ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &newt); // disabling echo
    getline(cin, userobj.password);
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt); // enabling echo
    cout << "\n" ;
    /////////////////////
    cout << "Enter D.O.B [DDMMYYYY]: ";
    getline(cin, userobj.dob);
    cout << "Enter Address: ";
    getline(cin, userobj.address);
    cout << "Enter Contact Number: ";
    getline(cin, userobj.contactNumber);
    userobj.saveToAuthFile();
    userobj.saveToTokenFile();
    export_userprofile(to_string(userobj.userToken), userobj);
    cout << "REGISTRATION SUCCESSFUL. LOGIN AGAIN TO CONTINUE.\n";
}

void delay_buffer()
{
    // This module is called when closing the program, to generate a small pause
    int dummy = 0;
    for(int i=0;i<180000000;i++)
    {
        //just a time buffer, to make exit look real
        dummy = ~dummy;
    }
}