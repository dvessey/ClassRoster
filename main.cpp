#include "student.h"
#include "roster.h"
#include "degree.h"

#include <iostream>
#include <string>

using namespace std;

int main()
{
	cout << "\t\t#########################################################" << endl;
	cout << "\t\t#" << '\t' << "C867: Scripting and Programming Applications" << "\t#" << endl;
	cout << "\t\t#" << '\t' << "Written in C++" << "\t\t\t\t\t#" << endl;
	cout << "\t\t#" << '\t' << "ID: 003424385" << "\t\t\t\t\t#" << endl;
	cout << "\t\t#" << '\t' << "Damon Vessey" << "\t\t\t\t\t#" << endl;
	cout << "\t\t#########################################################" << endl << endl;

	//Input for the program that will need parsed by comma's
	//each line represents a student object that will later be addeded to the classRosterArray
	const string studentData[] = {
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Damon,Vessey,dvessey@wgu.edu,31,3,10,15,SOFTWARE"
	};
	
	const int numStudents = 5;

	Roster* classRoster = new Roster(numStudents);

	for (int i = 0; i < numStudents; i++) {
		classRoster->parse(studentData[i]);
	}

	
	cout << "Students in Roster: " << endl;
	classRoster->printAll();
	cout << endl;

	cout << "Printing invalid emails:" << endl;
	classRoster->printInvalidEmails();
	cout << endl;

	cout << "Average number of days to complete a course for each student: " << endl;
	for (int i = 0; i < numStudents; i++) {
		classRoster->printAverageDaysInCourse(classRoster->getStudent(i)->GetStudentId());
	}
	cout << endl;

	cout << "Printing all students in software development:" << endl;
	classRoster->printByDegreeProgram(SOFTWARE);
	cout << endl;

	cout << "Remove Student A3:" << endl;
	classRoster->remove("A3");
	cout << endl;

	cout << "Reprint all students after removing A3:" << endl;
	classRoster->printAll();
	cout << endl;

	cout << "Trying to remove A3 again:" << endl;
	classRoster->remove("A3");

	cout << endl << endl << endl << endl;

	return 0;


}
