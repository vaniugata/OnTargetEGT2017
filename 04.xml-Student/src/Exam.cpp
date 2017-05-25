#include "Exam.h"
#include <sstream>

Exam::Exam(const std::string& name, const std::string& lecturer, float grade)
{
	setName(name);
	setLecturer(lecturer);
	setGrade(grade);
}

float Exam::getGrade() const
{
	return _grade;
}

const std::string& Exam::getLecturer() const
{
	return _lecturer;
}

void Exam::setGrade(float grade)
{
	_grade = grade;
}

void Exam::setLecturer(const std::string& lecturer)
{
	_lecturer = lecturer;
}

void Exam::setName(const std::string& name)
{
	_name = name;
}

const std::string& Exam::getName() const
{
	return _name;
}

Exam::~Exam()
{
	// TODO Auto-generated destructor stub
}

std::string Exam::print() const
{
	std::stringstream result;
	result << getName() << " " << getLecturer() << " " << getGrade() << "\n";


	return result.str();
}
