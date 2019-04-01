#include <fstream>
#include <string.h>
#include <iostream>
using namespace std;
class Student
{
public:
	char   FullName[40];
	char   CompleteAddress[120];
	char   Gender;
	double Age;
	bool   LivesInASingleParentHome;
};

int main()
{
	Student one;
	strcpy(one.FullName, "Ernestine Waller");
	strcpy(one.CompleteAddress, "824 Larson Drv, Silver Spring, MD 20910");
	one.Gender = 'F';
	one.Age = 16.50;
	one.LivesInASingleParentHome = true;
	ofstream ofs("./data/fifthgrade.ros", ios::binary);
	ofs.write((char *)&one, sizeof(one));
	return 0;
}

