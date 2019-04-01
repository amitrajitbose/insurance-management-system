/*
Insurance Management System

Author:
Amitrajit Bose
Sourav Kumar
Kirti Ojha
*/

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <fstream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
using namespace std;

class Policy
{
public:
    double healthInsurance( int age,int health_condition,int  policy_period,int  sum)
    {
        //returns total premium.
        
        //policy start date store
        
        double prem,ci_prem,tot_prem;
        
        
        int prem_age[6][5]= { {1802,2689,3362,4168,4572},
                            {2226,3213,4016,4980,5462},
                            {2286,3253,4116,4985,5862},
                            {4125, 5319,6648,8244,9042},
                            {5749,8681, 10852,13456,14758},
                            {13308,20097,25121,31150,34164}};
                            
        int ci_prem_age[6][5]={ {31,61,92,122,153},
                            {116,231,347,462,578},
                            {354,706,1062,1415,1769},
                            {776, 1552,2348,2911,3889},
                            {1279,2557,3836,5114,6383},
                            {2008,4040,6025,8050,10341}};
        
        double fit_age[10]={0,0,0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8};

        
        if(age<=17 )
        {
            prem=prem_age[0][sum-1];
            ci_prem=ci_prem_age[0][sum-1];
        }
        else if(age >=18 && age<=35 )
        {
            prem = prem_age[1][sum-1];
            ci_prem=ci_prem_age[1][sum-1];
        }
        else if(age >=36 && age<=49 )
        {
            prem = prem_age[2][sum-1];
            ci_prem=ci_prem_age[2][sum-1];
        }
        else if (age >=50 && age<=65 )
        {
            prem = prem_age[3][sum-1];
            ci_prem=ci_prem_age[3][sum-1];
        }
        else if(age >=66 && age<=75 )
        {
            prem = prem_age[4][sum-1];
            ci_prem=ci_prem_age[4][sum-1];
        }
        else if(age >=75 && age<=85 )
        {
            prem = prem_age[5][sum-1];
            ci_prem=ci_prem_age[5][sum-1];
        }
        else
            return 0.0;
        
        
        prem=prem-fit_age[health_condition]*prem;
        tot_prem=prem+ci_prem;
        
        //store total prem. deatils to show currentdate-startdate= months already paid. rem = (policy_period-monthspaid)
        
        cout<<"Your total premium is : "<<tot_prem<<"\t for a period of "<<policy_period<<" month(s) "<<endl;
        return tot_prem;
    }

    double lifeInsurance(int age)
    {
        //policy_period, age
        int policy_amount,term; //10 lakh to 1 crore
        double prem;
        int t=(60-age)*12;
        cout<<"Select one of the following term plans :"<<endl;
        cout<<"1 --> Monthly"<<endl;
        cout<<"2 --> Quaterly"<<endl;
        cout<<"3 --> Semi annually"<<endl;
        cout<<"4 --> Annually"<<endl;
        string termstring[4]={"monthly","quaterly","semi-annually","annually"};
        cin>>term;
        cout<<"Enter amount among the following ranges"<<endl;
        cout<<"10 lakh ......1 crore in digits"<<endl;
        cin>>policy_amount;
        if(term==1){
            prem = policy_amount/t;
        }
        else if(term==2){
            t=t/4;
            prem = policy_amount/(t);
        } 
        else if(term==3){
                t=t/6;
            prem = policy_amount/(t);
            
        }
        else if(term==4){
                t=t/12;
            prem = policy_amount/(t);
            
        }
        else{
            return 0.0;
        }
        cout<<"Your "<<termstring[term-1]<<" premium is : "<<prem<<"\t for a period of "<<t<<" times "<<termstring[term-1]<<endl;
        return prem;
    }

    double homeInsurance(int pp,int age){
        int house_age,sqft,cost_sqft;
        char own_rent,flat_bung;
        double tot_prem,prem;
        const double dep = 0.15;

        cout<<"Is your flat rented(r) or owned(o)?"<<endl;
        cin>>own_rent;
        if(own_rent=='r')
        {
            int content_price;
            cout<<"Enter total value of contents : "<<endl;
            cin>>content_price;
            tot_prem=content_price*11; 
        }

        else
        {
        cout<<"Do you own a flat(f) or bungalow(b)?"<<endl;
        cin>>flat_bung;
        
        cout<<"Age of flat/building?"<<endl;
        cin>>house_age; 
        if(house_age<=30)
        
        {
            
            if(flat_bung=='f' )
            {
                cout<<"Enter sqft area of flat : "<<endl; 
                cin>>sqft;
                cout<<"Enter cost of construction per sqft area of flat : "<<endl; 
                cin>>cost_sqft;
                tot_prem = sqft*cost_sqft-dep*house_age;
            }
            if(flat_bung=='b' )
            {
                cout<<"Enter built area : "<<endl; 
                cin>>sqft;
                cout<<"Enter cost of construction  "<<endl; 
                cin>>cost_sqft;
                tot_prem = sqft*cost_sqft-dep*house_age;
            }
        }
        else
        {
            cout<<"You do not qualify for home insurance."<<endl;
            return 0;
        }
        }
        int m;
        if (pp!=-9)
        {
        m=  (pp*12);
        prem = tot_prem/m;
        }
        else{
            m=((70-age)*12);
            prem = tot_prem/m;
        }
        
            cout<<"Your monthly  premium is : "<<prem<<"\t for a period of "<<m<<" months "<<endl;
        return prem;
    }

    int createNewPolicy(int user_token)
    {
        //if(details exist for user_token)
        //display details 
        int age,health_condition,policy_period,sum;
        
        bool flag = true;
        int policy_choice,total_premium;
        cout<<"Enter choice of policy."<<endl;
        cout<<"1 --> Health"<<endl;
        cout<<"2 --> Life"<<endl;
        cout<<"3 --> Home"<<endl;
        cout<<"Choice :";
        cin>>policy_choice;

        cout << "Enter Age Of Applicant: " << endl;
        cin>>age;
        if(age>=86 && policy_choice==1)
            {
                cout<<"You do not qualify for health insurance."<<endl; 
                return 0;
            }
        if(age>=51 && policy_choice==2)
            {
                cout<<"You do not qualify for life insurance."<<endl;   
                return 0;
            }
        if(age>=71 && policy_choice==3)
            {
                cout<<"You do not qualify for home insurance."<<endl;   
                return 0;
            }
        
            
        while(flag)
        {
            switch(policy_choice)
            {
                case 1: 
                    
                    cout<<"Enter health condition (0 to 10)  10 being the fittest."<<endl;
                    cin>>health_condition;
            
                    cout<<"Enter Policy period in months "<<endl;
                    cin>>policy_period;
                    cout<<"Sum Chart : "<<endl;
                    cout<<"1 lakh , 2 lakh , 3 lakh ,4 lakh ,5 lakh"<<endl; 
                    cout<<"Enter sum insured"<<endl;
                    cin>>sum;
             
                    cout<<"CRITICAL ILLNESS RIDER = 100!"<<endl;
                    total_premium=healthInsurance(age,health_condition,policy_period,sum);
                    
                    flag=false;
                    break;
                    
                    
                case 2:  total_premium=lifeInsurance(age);
                
                    flag=false;
                    break;
                    
                case 3:
                        cout<<"Enter Policy period in years or enter -9 for indefinite policy period "<<endl;
                        cin>>policy_period;
                        total_premium = homeInsurance(policy_period,age);
                        flag=false;
                        break;
                    
                default:
                    cout<<"Does not exist.Try again.";
            }
        }
    }
};

class User
{
    public:
        string name; //user's full name
        string email; //user's email
        int userToken; //this should be a private member later, will be randomly generated
        string password; //only alphanumeric, no special characters
        string dob; //date of birth
        string address; //address
        string contactNumber; //contact
        string policyRecord[10]; //a user can create maximum 10 policies
        int policycount = 0;
        //the above array store objects of Policy class

        void showDetails(){
            cout << "***** USER DETAILS *****" << endl;
            cout << "NAME ........ " << name << endl;
        }
        void newPolicy(){}
        void saveToAuthFile(){
            /*
            Takes in email and password
            and stores them in AUTH.txt file
            */
            fstream myfile;
            myfile.open("./data/AUTH.txt", fstream::app);
            if (myfile.is_open())
            {
                myfile << email; // not sure if it will work!
                myfile << "\n";
                myfile << password; //not sure if it will work!
                myfile << "\n";
                myfile.close();
            }
            else cout << "Unable to open AUTH file for saving";
        }
        void saveToTokenFile(){
            /*
            Takes in email and token
            and stores them in TOKEN.txt file
            */
            fstream myfile;
            myfile.open("./data/TOKEN.txt", fstream::app);
            if (myfile.is_open())
            {
                myfile << email; // not sure if it will work!
                myfile << "\n";
                myfile << userToken; //not sure if it will work!
                myfile << "\n";
                myfile.close();
            }
            else cout << "Unable to open TOKEN file for saving";
        }
};

void export_userobject(string usertoken, User obj)
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
    number of policies
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

User import_userobject(string usertoken)
{
    User obj;
    string path = "./data/" + usertoken + ".ros";
    ifstream ifs(path, ios::binary);
    cout << sizeof(obj) << endl;
    ifs.read((char *)&obj, sizeof(obj));
    cout << obj.name << "...\n";
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
        User user = import_userobject(usertoken);
        
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
    export_userobject(to_string(userobj.userToken), userobj);
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

int main()
{
    srand (time(NULL));
    std::ios::sync_with_stdio(true);
    cout << "------------------------------------------------------" << endl;
    cout << "*** Welcome To The Insurance Management System App ***" << endl;
    cout << "------------------------------------------------------" << endl;
    int flag=1;
    while(flag)
    {
        string choice1;
        cout << "\nPress [L / l] To Login\nPress [S / s] To Signup\nPress [X / x] To Exit\nEnter Choice: ";
        cin >> choice1;
        if(choice1.size()>1)
            cout << "Invalid Option. Enter Only One Character!\n";
        else
        {
            char choice = choice1[0];
            switch(choice)
            {
                case 'L':
                case 'l':
                    login();
                    break;

                case 'S':
                case 's':
                    signup();
                    break;

                case 'X':
                case 'x':
                    cout << "\nClosing Application..." << endl;
                    delay_buffer();
                    flag = 0;
                    cout << "Exit Successful !" << endl;
                    break;

                default:
                    cout << "Is that you? Sorry. Invalid Option! ..." << endl;
            } //switch
        } //else
    } //while
} //main
