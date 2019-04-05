#include <iostream>
#include <ctime>
using namespace std;

int main()
{
    time_t now = time(0);
    tm *ltm = localtime(&now);
    int date[3];
    date[0] = ltm->tm_mday;
    date[1] = 1 + ltm->tm_mon;
    date[2] = 1900 + ltm->tm_year;
    cout << date[0] << endl;
    cout << date[1] << endl;
    cout << date[2] << endl;
    return 0;
}