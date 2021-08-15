#ifndef STUDENT_H
#define STUDENT_H

#include "degree.h"
#include <iostream>
#include <string>

using namespace std;

class Student {
public:
	//Constructor and Deconstructor
	Student();
	Student(string studentId, string firstName, string lastName, string emailAddresss, int age, int daysInCourse[], DegreeProgram degreeProgram);
	~Student();

	//Getters and Setters
	void SetStudentId(string studentId);
	string GetStudentId();
	void SetFirstName(string firstName);
	string GetFirstName();
	void SetLastName(string lastName);
	string GetLastName();
	void SetEmailAddress(string emailAddress);
	string GetEmailAddress();
	void SetAge(int age);
	int GetAge();
	void SetDaysInCourse(int daysInCourse[]);
	int* GetDaysInCourse();
	DegreeProgram GetDegreeProgram();
	void SetDegreeProgram(DegreeProgram degreeProgram);

	//print student data member function
	void print();
	
	//variables only to be accessible through public getters and setters above
private:
	string studentId;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int* daysInCourse;
	DegreeProgram degreeProgram;
};

#endif