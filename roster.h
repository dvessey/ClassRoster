
#include <iostream>
#include <string>

#include "student.h"

using namespace std;

class Roster {
public:
	int numStudents; //total number of students

	//Constructors and Deconstructor
	Roster();
	Roster(int numStudents);
	~Roster();

	void parse(string rawString);
	void add(string studentId, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram); //add a student to the roster
	void remove(string studentId); //need to check if id exists, if not return an error
	void printAll(); // loop through all the students in classRosterArray and call the print() function for each student.
	void printAverageDaysInCourse(string studentId); //prints a student’s average number of days in the three courses. The student is identified by the studentId parameter.
	void printInvalidEmails(); // A valid email should include an at sign ('@') and period ('.') and should not include a space (' ').
	void printByDegreeProgram(DegreeProgram degreeProgram); //prints out student information for a degree program
	Student* getStudent(int index);

private:
	Student** classRosterArray;
	int index;

};