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
    return 0;
}