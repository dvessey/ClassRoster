#include "student.h"
#include "degree.h"

#include <iostream>
#include <string>

using namespace std;

// Initialize Default Constructor
Student::Student() {
	this->studentId = "";
	this->firstName = "";
	this->lastName = "";
	this->age = 0;
	this->emailAddress = "";
	this->daysInCourse = new int[3];
	for (int i = 0; i < 3; i++) {
		this->daysInCourse[i] = daysInCourse[0];
	}
	this->degreeProgram = NONE;
}


//	Initialize Constructor
Student::Student(string studentId, string firstName, string lastName, string emailAddress, int age, int daysInCourse[], DegreeProgram degreeProgram) {
	this->studentId = studentId;
	this->firstName = firstName;
	this->lastName = lastName;
	this->age = age;
	this->emailAddress = emailAddress;
	this->daysInCourse = new int[3];
	for (int i = 0; i < 3; i++) {
		this->daysInCourse[i] = daysInCourse[i];
	}
	this->degreeProgram = degreeProgram;
}



//	Deconstructor
Student::~Student() {
	delete[] daysInCourse;
}


//	Getter and Setter implimentations
string Student::GetStudentId() {
	return studentId;
}

string Student::GetFirstName() {
	return firstName;
}

string Student::GetLastName() {
	return lastName;
}

int Student::GetAge() {
	return age;
}

string Student::GetEmailAddress() {
	return emailAddress;
}

int* Student::GetDaysInCourse() {
	return daysInCourse;
}

DegreeProgram Student::GetDegreeProgram() {
	return degreeProgram;
}

void Student::SetStudentId(string studentId) {
	this->studentId = studentId;
}

void Student::SetFirstName(string firstName) {
	this->firstName = firstName;
}

void Student::SetLastName(string lastName) {
	this->lastName = lastName;
}

void Student::SetAge(int age) {
	this->age = age;
}

void Student::SetEmailAddress(string emailAddress) {
	this->emailAddress = emailAddress;
}

void Student::SetDaysInCourse(int daysInCourse[]) {
	for (int i = 0; i < 3; i++) {
		this->daysInCourse[i] = daysInCourse[i];
	}
}

void Student::SetDegreeProgram(DegreeProgram degreeProgram) {
	this->degreeProgram = degreeProgram;
}


//	Print student data member function
void Student::print() {
	cout << studentId << '\t' << "First name: " << firstName << '\t' << "Last name: " << lastName << '\t'
		<< "Email: " << emailAddress << '\t' << "Age: " << age << '\t' << "Days in course: {";

	for (int i = 0; i < 3; i++) {
		cout << daysInCourse[i] << (i < 2 ? "," : "");
		
	}

	//degreeProgramStrings is a parrallel string array found in degree.h to print out degree program enum
	cout << "} Degree Program: " << degreeProgramStrings[GetDegreeProgram()] << endl;

	return;
}