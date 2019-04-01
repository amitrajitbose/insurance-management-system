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
#include <fstream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
using namespace std;

class Policy
{
public:
    int type; //[0:Health, 1:Life, 2:Home]
    int amount; //insurance amount
    int date[8]; //date stored as DDMMYYYY format
    int term; //total time for maturity
    /*
    Please add more terms as per requirement
    */

    /*
    Add relevant methods here related to policies
    */

};

class User
{
public:
    string name;
    string email;
    int userToken; //this should be a private member later, will be randomly generated
    string password; //only alphanumeric, no special characters
    string address;
    string contactNumber;
    Policy policyRecord[50]; //a user can create maximum 50 policies
    //the above array store objects of Policy class

    /*
    Please add more terms as per requirement
    */

    /*
    Add relevant methods here related to policies
    */
    void showDetails(){}
    void newPolicy(){}
    void deletePolicy(){}
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
    cout << "Enter Your Email: ";
    getline(cin, useremail);
    getline(cin, useremail);
    cout << "Enter Your Password: ";
    getline(cin, password);
    //authenticateUser(useremail, password);
    
    if(authenticateUser(useremail, password)==1)
    {
        cout << "Login Successful" << endl;
        // After login activities
        
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
    cout << "Enter Your Name: ";
    getline(cin, userobj.name);
    getline(cin, userobj.name);
    cout << "Enter Valid Email: ";
    getline(cin, userobj.email);
    userobj.userToken = getRandomToken();
    cout << "Enter Alphanumeric Password: ";
    getline(cin, userobj.password);
    userobj.saveToAuthFile();
    userobj.saveToTokenFile();
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