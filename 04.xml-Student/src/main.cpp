#include "pugixml.hpp"
#include "University.h"
#include "Student.h"
#include <iostream>
#include <string>
using std::string;
#include <fstream>

int main()
{
	pugi::xml_document doc;
	if(! doc.load_file("students.xml"))
	{
		std::cerr << "can't open file students.xml\n";
	}

	pugi::xml_node students = doc.child("students");

	for(pugi::xml_node student = students.child("students:student"); student;
			student = student.next_sibling("students:student"))
	{
		//students data
				string firstName = student.child("students:firstName").text().as_string();
						string lastName =  student.child("students:lastName").text().as_string();
						string gender =  student.child("students:gender").text().as_string();
						string birthday =  student.child("students:birthdate").text().as_string();
						string phone =  student.child("students:phone").text().as_string();
						string email =  student.child("students:email").text().as_string();
						int course =  student.child("students:course").text().as_int();
						string specialty = student.child("students:specialty").text().as_string();
						long int facultyNum =  student.child("students:facultyNumber").text().as_uint();

		Student* studentObj = new Student(firstName, lastName, gender, birthday, phone, email, course, specialty,
				facultyNum);

		for(pugi::xml_node exams = student.child("exams:examList"); exams; exams = exams.next_sibling("exams:examList"))
		{
			//all exams
			for(pugi::xml_node exam = exams.child("exams:exam"); exam; exam = exam.next_sibling("exams:exam"))
			{
				//current exam data
				string examName = exam.child("exams:name").text().as_string();
				string lecturer = exam.child("exams:lecturer").text().as_string();
				float grade = exam.child("exams:grade").text().as_float();

				Exam* examObj = new Exam(examName, lecturer, grade);
				studentObj->addExam(*examObj);
			}
		}
		University::Add(*studentObj);
	}

	std::ofstream outputFile("output.txt", std::ios::out);
	University::writeToFile(outputFile);

	return 0;
}
