//============================================================================
// Name Garret Gherardini       : CS300Project2.cpp
// Author      : ggherardini
// Version     : 1.7
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

// Course class is created to manage variables enabling reusable code
class Course {
public:
	string number;
	string title;
	vector<string> preRequisite;

	Course(string number, string title, vector<string> preRequisite);
};

// TreeNode class is created to manage variables enabling reusable code
class TreeNode {
public:
	Course course;
	Treenode* leftChild;
	Treenode* rightChild;
	TreeNode(Course c) : course(c), leftChild(nullptr), rightChild(nullptr) {}
};