/*
 * University.cpp
 *
 *  Created on: May 25, 2017
 *      Author: vaniugata
 */

#include "University.h"
#include <iostream>
#include <fstream>

std::vector<Student*> University::_students;

University::University()
{
	// TODO Auto-generated constructor stub

}

University::~University()
{
	// TODO Auto-generated destructor stub
}

 std::vector<Student*>& University::getStudents()
{
	return _students;
}

void University::Add(Student& student)
{
	_students.push_back(&student);
}

void University::writeToFile(std::ofstream& outputFile)
{
	if(! outputFile)
	{
		std::cerr << "Can't open output file.\n";
		return;
	}

	std::vector<Student*>::iterator student;
	for(student = University::getStudents().begin();
			student != University::getStudents().end(); student++)
	{
		outputFile << (*student)->print();
		outputFile << "=========================================================\n";
	}
}
