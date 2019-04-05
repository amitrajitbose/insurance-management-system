#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    cout << "Enter String: ";
    string ss;
    getline(cin,ss);
    cout << ss << endl;
    cout << ss.compare("hello") << endl;

    int ar[3];
    cout << "ENTER DD MM YYYY : ";
    cin >> ar[0];
    cin >> ar[1];
    cin >> ar[2];
    cout << ar[0] << endl << ar[1] << endl << ar[2] << endl;
    return 0;
}