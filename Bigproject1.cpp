//----------------------------------------------------------
//                   Project 1
//------------------------------------------------------------
// Author: Jonathan Jimenez
// Date: 2/1/2018
// For: CS 215 - Spring 2018 - Lab 3 
// This program calculates temperature then states if it is a solid, liquid, or gas
// entered by the user
//-----------------------------------------------------------

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
int main() {
	string Student, X, x, E, B, A, C, D, Grade;
	cout << fixed << setprecision(2);
	double exams, ExamAvg, ProjAvg, LabAvg, AttnAvg, Overall, projects, labs, attendence_days, exam2, exam3, exam1, exam4, exam5, project1, project2, project3, project4, project5, lab1, lab2, lab3, lab4, lab5;
	cout << "---------------------------------------------------------------" << endl;
	cout << setw(5) << "                        GRADEBOOK PRO" << endl;
	cout << setw(10) << "                     By Jonathan Jimenez :)" << endl;
	cout << "---------------------------------------------------------------" << endl;
	cout << "" << endl;
	cout << "ENTER NUMBERS OF GRADED ITEMS SO FAR" << endl;
	cout << "Enter numbers of exams:                ";
		cin >> exams;
		if (exams > 5) {
			cout << "INVALID enter number between 0 and 5:  ";
			cin >> exams;
		}
	cout << "Enter numbers of projects:             ";
		cin >> projects;
		if (projects > 5) {
			cout << "INVALID enter number between 0 and 5:  ";
			cin >> projects;
		}
	cout << "Enter numbers of labs:                 ";
		cin >> labs;
		if (labs > 5) {
			cout << "INVALID enter number between 0 and 5:  ";
			cin >> labs;
		}
		cout << "Enter numbers of attendance_days:      ";
		cin >> attendence_days;
		if (attendence_days < 0) {
			cout << "INVALID enter number between 0 and 5:  ";
			cin >> attendence_days;
		}
		cout << "" << endl;
		cout << "ENTER STUDENT DATA" << endl;
		cout << "Enter student name (X to exit):       ";
		cin >> Student;
		if (Student == X)
		{
			system("pause");
			return 0;
	}
		if (exams == 1)
		{
			cout << "Enter Exam 1:        ";
			cin >> exam1;
		}
		if (exams == 2)
		{
			cout << "Enter Exam 1:        ";
			cin >> exam1;
			cout << "Enter Exam 2:        ";
			cin >> exam2;
		}
		if (exams == 3)
		{
			cout << "Enter Exam 1:        ";
			cin >> exam1;
			cout << "Enter Exam 2:        ";
			cin >> exam2;
			cout << "Enter Exam 3:        ";
			cin >> exam3;
		}
		if (exams == 4)
		{
			cout << "Enter Exam 1:        ";
			cin >> exam1;
			cout << "Enter Exam 2:        ";
			cin >> exam2;
			cout << "Enter Exam 3:        ";
			cin >> exam3;
			cout << "Enter Exam 4:        ";
			cin >> exam4;
		}
		if (exams == 5)
		{
			cout << "Enter Exam 1:        ";
			cin >> exam1;
			cout << "Enter Exam 2:        ";
			cin >> exam2;
			cout << "Enter Exam 3:        ";
			cin >> exam3;
			cout << "Enter Exam 4:        ";
			cin >> exam4;
			cout << "Enter Exam 5:        ";
			cin >> exam5;
		}
		if (projects == 1)
		{
			cout << "Enter project 1:     ";
			cin >> project1;
		}
		if (projects == 2)
		{
			cout << "Enter project 1:     ";
			cin >> project1;
			cout << "Enter project 2:     ";
			cin >> project2;
		}
		if (projects == 3)
		{
			cout << "Enter project 1:     ";
			cin >> project1;
			cout << "Enter project 2:     ";
			cin >> project2;
			cout << "Enter project 3:     ";
			cin >> project3;
		}
		if (projects == 4)
		{
			cout << "Enter project 1:     ";
			cin >> project1;
			cout << "Enter project 2:     ";
			cin >> project2;
			cout << "Enter project 3:     ";
			cin >> project3;
			cout << "Enter project 4:     ";
			cin >> project4;
		}
		if (projects == 5)
		{
			cout << "Enter project 1:     ";
			cin >> project1;
			cout << "Enter project 2:     ";
			cin >> project2;
			cout << "Enter project 3:     ";
			cin >> project3;
			cout << "Enter project 4:     ";
			cin >> project4;
			cout << "Enter project 5:     ";
			cin >> project5;
		}
		if (labs == 1)
		{
			cout << "Enter Lab 1:         ";
			cin >> lab1;
		}
		if (labs == 2)
		{
			cout << "Enter Lab 1:         ";
			cin >> lab1;
			cout << "Enter Lab 2:         ";
			cin >> lab2;
		}
		if (labs == 3)
		{
			cout << "Enter Lab 1:         ";
			cin >> lab1;
			cout << "Enter Lab 2:         ";
			cin >> lab2;
			cout << "Enter Lab 3:         ";
			cin >> lab3;
		}
		if (labs == 4)
		{
			cout << "Enter Lab 1:         ";
			cin >> lab1;
			cout << "Enter Lab 2:         ";
			cin >> lab2;
			cout << "Enter Lab 3:         ";
			cin >> lab3;
			cout << "Enter Lab 4:         ";
			cin >> lab4;
		}
		if (labs == 5)
		{
			cout << "Enter Lab 1:         ";
			cin >> lab1;
			cout << "Enter Lab 2:         ";
			cin >> lab2;
			cout << "Enter Lab 3:         ";
			cin >> lab3;
			cout << "Enter Lab 4:         ";
			cin >> lab4;
			cout << "Enter Lab 5:         ";
			cin >> lab5;
		}
		cout << "Enter Days Attended: ";
			cin >> attendence_days;

		cout << "--------------------------------------------------------------------" << endl;
		cout << "Grade Report for: " << Student << endl;
		cout << "--------------------------------------------------------------------" << endl;
		cout << "Exam Avg | Proj Avg | Lab Avg | Attn Avg | Overall | Grade |" << endl;
		cout << "--------------------------------------------------------------------" << endl;
		if (labs == 1)
		{
			ExamAvg = exam1;
		}
		if (labs == 2)
		{
			ExamAvg = (exam1+exam2)/2;
		}
		if (labs == 3)
		{
			ExamAvg = (exam1 + exam2+exam3) / 3;
		}
		if (labs == 4)
		{
			ExamAvg = (exam1 + exam2+exam3+exam4) / 4;
		}
		if (labs == 5)
		{
			ExamAvg = (exam1 + exam2+exam3+exam4+exam5) / 5;
		}
		if (projects == 1)
		{
			ProjAvg = (project1);
		}
		if (projects == 2)
		{
			ProjAvg = (project1+project2)/2;
		}
		if (projects == 3)
		{
			ProjAvg = (project1 + project2+ project3) / 3;
		}
		if (projects == 4)
		{
			ProjAvg = (project1 + project2 + project3+ project4) / 4;
		}
		if (projects == 5)
		{
			ProjAvg = (project1 + project2 + project3 + project4+ project5) / 5;
		}
		if (labs == 1)
		{
			LabAvg = (lab1);
		}
		if (labs == 2)
		{
			LabAvg = (lab1+lab2)/2;
		}
		if (labs == 3)
		{
			LabAvg = (lab1 + lab2+lab3) / 3;
		}
		if (labs == 4)
		{
			LabAvg = (lab1 + lab2 + lab3+ lab4) / 4;
		}
		if (labs == 5)
		{
			LabAvg = (lab1 + lab2 + lab3 + lab4+ lab5) / 5;
		}
		if (attendence_days > 0)
		{
			AttnAvg = (attendence_days*10);
		}
		Overall = ((ExamAvg*.4) + (ProjAvg*.3) + (LabAvg*.20) + (AttnAvg*.1));

		cout << ExamAvg << "      ";
		cout << ProjAvg << "        ";
		cout << LabAvg << "      ";
		cout << AttnAvg << "     ";
		cout << Overall << "      ";
		if (Overall < 60)
		{
			cout << "E"<<endl;
		}
		if (Overall >= 60 && Overall <= 69)
		{
			cout << "D"<<endl;
		}
		if (Overall >= 70 && Overall <= 79)
		{
			cout << "C"<<endl;
		}
		if (Overall >= 80 && Overall <= 89)
		{
			cout << "B"<<endl;
		}
		if (Overall >= 90)
		{
			cout << "A"<< endl;
		}
		cout << "---------------------------------------------------------------------" << endl;
		system("pause");
	return 0;
}