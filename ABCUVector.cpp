// Garret Gherardini
// CS-300 Project 2, Vector Data Structure
// 02.25.2024
// Professor Ostrowski

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include "fraction.c"
#include <string>;
std::vector<Course>;

using namespace std;

class Course {
public:
	string course;
	string courseId;
	string courseTitle;
	vector<string> preRequisite;
}

// data types consistent with courses in text file assigned to Course
struct Course;
	string course;
	string courseId;
	string courseTitle;
	vector<string> preRequisite;

	Course() = default;

// data imported from textFile to vector, utilize temp pointer
void loadVector(const string& textFile, vector<Course>& courses) {
	ifstream file(textFile);

	// when file is found 
	if (file.is_open()) {
		Course tempCourse;
		while (file >> tempCourse.courseId >> tempCourse.courseTitle) {
			string preRequisite;

			// push back utilized as information in temp pointer can be added into vector
			while (file >> preRequisite && preRequisite != "-1") {
				tempCourse.preRequisite.push_back(preRequisite); 
			}
			course.push_back(tempCourse);
			tempCourse.preRequisite.clear();
		}
		file.close();
		cout << "Courses have been imported." << endl;
	} 

	// if file not found, inform user to select proper file
	else {
		cout << "File not found." << endl;
	}
}

// when printing course information, format accordingly regardless of course type
void printCourseList(const vector<Course>& courses) {
	for (const Course& course : courses) {

		// if course ID begins with either CSCI or MATH followed by course ID and title, display as follows
		if (course.courseId.substr(0, 4) == "CSCI" || course.courseId.substr(0, 4) == "MATH") {
			cout << course.courseId << ", " << course.courseTitle << endl;
		}
	}
}

void printCourseInformation(const vector<Course>& courses, const string& courseNumber) {
	bool found = false;
	for (const Course& course : courses) {

		// if course ID found print the course title
		if (course.courseId == courseId) {
			found = true;
			cout << courseTitle << endl;

			// check if prerequisite exists for course, if so print prerequisite name, if none print "None listed."
			if (!course.preRequisite.empty()) {
				for (const string& preRequisite : course.preRequisite) {
					cout << preRequisite << endl;
				}
			else {
				cout << "None listed." << endl;
			}
			break;
			}
		}
		else (!found); {
			cout << "Course not found." << endl;
		}
	}
}

int main() {
	vector<Course> courses;
	string textFile;
	string course;
	string courseId;
	string courseTitle;
	vector<string> preRequisite;


	int choice;

	// user is displayed menu options
	cout << "1. Load Data Structure." << endl;
	cout << "2. Print Course List." << endl;
	cout << "3. Print Course." << endl;
	cout << "9. Exit" << endl;
	cout << " " << endl;

	// user is prompted to input selection
	cout << "What would you like to do? " << endl;
	cin >> choice;

	// utilize switch cases for menu option selections
	switch (choice) {
	case 1:
		// if option one selected, data structure is loaded
		if (1 == choice) {
			loadVector(textFile, courses);
			break;
		}

		// if invalid option selected, prompt displays invalid operation 
		else {
			cout << choice << " is not a valid option." << endl;
		}
	case 2:

		// if option two is selected, sample schedule is loaded
		if (2 == choice) {
			cout << "Here is a sample schedule:" << printCourseInformation << endl;
		}
		break;
	case 3:

		// if option three is selected, course information is printed and inludes prerequisite if  applicable
		if (3 == choice) {
			cout << courses.courseId << courses.courseName << courses.coursePreRequisite << endl;
		}
		break;
	case 9:

		// if option nine is selected, course planner exits 
		if (9 == choice) {
			cout << "Thank you for using the course planner!" << endl;
		}
		break;
	}
};
