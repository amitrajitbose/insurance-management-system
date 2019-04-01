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

#include "Policy.hpp"
#include "User.hpp"
#include "Utilities.hpp"

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
