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
            cout << "\n******* USER DETAILS *******" << endl;
            cout << "NAME ........ " << name << endl;
            cout << "PHONE ....... " << contactNumber << endl;
            cout << "EMAIL ....... " << email << endl;
            cout << "Press 1 To Show More Details Otherwise 0: ";
            int ch;
            cin >> ch;
            if(ch==1)
            {
                cout << "D.O.B ....... " << dob << endl;
                cout << "ADDRESS ..... " << address << endl;
                cout << "POLICIES .... " << policycount << endl;
            }
        }
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