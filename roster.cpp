#include <iostream>
#include <string>

#include "degree.h"
#include "roster.h"

using namespace std;

// Initialize Default Constructor
Roster::Roster() {
	this->numStudents = 0;
	this->classRosterArray = nullptr;
	this->index = -1;
}

// Initialize Constructor
Roster::Roster(int numStudents) {
	this->numStudents = numStudents;
	this->classRosterArray = new Student* [numStudents];
	this->index = -1;
}

// Deconstructor
Roster::~Roster() {
	delete[] classRosterArray;
}

// Parse StudentData[]
void Roster::parse(string rawString) {
	//Format of rawString to parse:
	/*const string studentData[] = {
	"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Damon,Vessey,dvessey@wgu.edu,31,3,10,15,SOFTWARE"
	};*/

	
	
	if (index < numStudents){
		index++;
	

		//Parse studentId from rawString
		size_t rightCharLocation = rawString.find(",");
		string studentId = rawString.substr(0, rightCharLocation);
		

		//Parse firstName from rawString
		size_t leftCharLocation = rightCharLocation + 1; //character immediately after the comma
		rightCharLocation = rawString.find(",", leftCharLocation);
		string firstName = rawString.substr(leftCharLocation, rightCharLocation - leftCharLocation);
		

		//Parse lastName from rawString
		leftCharLocation = rightCharLocation + 1; //character immediately after the comma
		rightCharLocation = rawString.find(",", leftCharLocation);
		string lastName = rawString.substr(leftCharLocation, rightCharLocation - leftCharLocation);

		//Parse emailAddress from rawString
		leftCharLocation = rightCharLocation + 1; //character immediately after the comma
		rightCharLocation = rawString.find(",", leftCharLocation);
		string emailAddress = rawString.substr(leftCharLocation, rightCharLocation - leftCharLocation);

		//Parse age and convert string to int from rawString
		leftCharLocation = rightCharLocation + 1; //character immediately after the comma
		rightCharLocation = rawString.find(",", leftCharLocation);
		int age = stoi(rawString.substr(leftCharLocation, rightCharLocation - leftCharLocation));

		//parse daysInCourse1 and convert string to int from rawString
		leftCharLocation = rightCharLocation + 1; //character immediately after the comma
		rightCharLocation = rawString.find(",", leftCharLocation);
		int daysInCourse1 = stoi(rawString.substr(leftCharLocation, rightCharLocation - leftCharLocation));

		//parse daysInCourse2 and convert string to int from rawString
		leftCharLocation = rightCharLocation + 1; //character immediately after the comma
		rightCharLocation = rawString.find(",", leftCharLocation);
		int daysInCourse2 = stoi(rawString.substr(leftCharLocation, rightCharLocation - leftCharLocation));

		//parse daysInCourse3 and convert string to int from rawString
		leftCharLocation = rightCharLocation + 1; //character immediately after the comma
		rightCharLocation = rawString.find(",", leftCharLocation);
		int daysInCourse3 = stoi(rawString.substr(leftCharLocation, rightCharLocation - leftCharLocation));

		//parse degree program from rawString
		leftCharLocation = rightCharLocation + 1; //character immediately after the comma
		DegreeProgram degreeProgram = DegreeProgram::NONE;

		int ENUM_ERR = 123456; //error code

		try {
			string theDegreeProgram = rawString.substr(leftCharLocation, rightCharLocation - leftCharLocation);
			if (theDegreeProgram == "SECURITY") { degreeProgram = DegreeProgram::SECURITY; }
			else if (theDegreeProgram == "NETWORK") { degreeProgram = DegreeProgram::NETWORK; }
			else if (theDegreeProgram == "SOFTWARE") { degreeProgram = DegreeProgram::SOFTWARE; }
			else if (theDegreeProgram == "NONE") { degreeProgram = DegreeProgram::NONE; }
			else throw ENUM_ERR;
			
		}
		catch (int e) {
			cout << "ERROR! Invalid Degree Program Enumeration!" << endl;
			cout << "Error Code: " << e << endl;
		}

		add(studentId, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);

	}
}

// Add days in course to an array to the parsed student in classRosterArray
void Roster::add(string studentId, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram){
	
	int daysInClass[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };

	classRosterArray[index] = new Student(studentId, firstName, lastName, emailAddress, age, daysInClass, degreeProgram);
}

// Print All Students
void Roster::printAll()
{
	for (int i = 0; i <= index; i++) {
		(this->classRosterArray)[i]->print();
	}
}

// Remove a student by id
void Roster::remove(string studentId)
{
	bool isNotFound = true;
	for (int i = 0; i <= index; i++) {
		if (classRosterArray[i]->GetStudentId() == studentId) {
			isNotFound = false;
			if (i < numStudents - 1) {
				Student* temp = classRosterArray[i];
				classRosterArray[i] = classRosterArray[numStudents - 1];
				classRosterArray[numStudents - 1] = temp;
			}
			index--;
			cout << studentId << " was successfully removed." << endl;
		}
	}
	if (isNotFound) {
		cout << "ERROR! Student with Id: " << studentId << " does not exist!";
	}
}

// Print All Students In A Given Degree Program
void Roster::printByDegreeProgram(DegreeProgram degreeProgram)
{
	for (int i = 0; i <= index; i++) {
		if (classRosterArray[i]->GetDegreeProgram() == degreeProgram) {
			classRosterArray[i]->print();
		}
	}
}

// Print All Invalid Emails
void Roster::printInvalidEmails() 
{
	bool isValid = true; //assume all email addresses are valid
	for (int i = 0; i <= index; i++) {
		string email = (classRosterArray[i]->GetEmailAddress());
		if (email.find('@') == string::npos || email.find(' ') != string::npos || email.find('.') == string::npos) {
			isValid = false;
			cout << classRosterArray[i]->GetEmailAddress() << endl;
		}
	}
	if (isValid) {
		cout << "NO INVALID EMAIL ADDRESSES." << endl;
	}
}

// Print Average Days in Course For Each Student
void Roster::printAverageDaysInCourse(string studentId) {
	cout << "Average days in course for student " << studentId << ": ";
	for (int i = 0; i <= index; i++) {
		if (classRosterArray[i]->GetStudentId() == studentId) {
			cout << (classRosterArray[i]->GetDaysInCourse()[0]
				+ classRosterArray[i]->GetDaysInCourse()[1]
				+ classRosterArray[i]->GetDaysInCourse()[2]) / 3 << endl;
		}
	}
}

// Used to get a student at a given index location in the array
Student* Roster::getStudent(int idx) {
	return classRosterArray[idx];
}


