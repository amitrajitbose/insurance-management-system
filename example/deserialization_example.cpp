#include <fstream>
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
	Student two;
	ifstream ifs("./data/fifthgrade.ros", ios::binary);
	ifs.read((char *)&two, sizeof(two));
	cout << "Student Information\n";
	cout << "Student Name: " << two.FullName << endl;
	cout << "Address:      " << two.CompleteAddress << endl;
	if( two.Gender == 'f' || two.Gender == 'F' )
		cout << "Gender:       Female" << endl;
	else if( two.Gender == 'm' || two.Gender == 'M' )
		cout << "Gender:       Male" << endl;
	else
		cout << "Gender:       Unknown" << endl;
	cout << "Age:          " << two.Age << endl;
	if( two.LivesInASingleParentHome == true )

		cout << "Lives in a single parent home" << endl;
	else

		cout << "Doesn't live in a single parent home" << endl;

	cout << "\n";
	return 0;
}

