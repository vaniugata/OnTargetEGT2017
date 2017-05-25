#include "Student.h"
#include <sstream>

Student::Student(const std::string& firstName, const std::string& lastName,
		const std::string& gender, const std::string& birthday,
		const std::string& phoneNumber, const std::string& email, int course,
		const std::string& speciality, long int facultyNumber,
		const std::vector<Exam*>& exams)
{
	setFirstName(firstName);
	setLastName(lastName);
	setGender(gender);
	setPhoneNumber(phoneNumber);
	setBirthday(birthday);
	setEmail(email);
	setCourse(course);
	setSpeciality(speciality);
	setFacultyNumber(facultyNumber);
	setExams(exams);

}

const std::string& Student::getBirthday() const
{
	return _birthday;
}

int Student::getCourse() const
{
	return _course;
}

const std::string& Student::getEmail() const
{
	return _email;
}

long int Student::getFacultyNumber() const
{
	return _facultyNumber;
}

const std::string& Student::getFirstName() const
{
	return _firstName;
}

const std::string& Student::getGender() const
{
	return _gender;
}

const std::string& Student::getLastName() const
{
	return _lastName;
}

const std::string& Student::getPhoneNumber() const
{
	return _phoneNumber;
}

const std::string& Student::getSpeciality() const
{
	return _speciality;
}

const std::vector<Exam*>& Student::getExams() const
{
	return exams;
}

void Student::setBirthday(const std::string& birthday)
{
	_birthday = birthday;
}

void Student::setCourse(int course)
{
	_course = course;
}

void Student::setEmail(const std::string& email)
{
	_email = email;
}

void Student::setFacultyNumber(long int facultyNumber)
{
	_facultyNumber = facultyNumber;
}

void Student::setFirstName(const std::string& firstName)
{
	_firstName = firstName;
}

void Student::setGender(const std::string& gender)
{
	_gender = gender;
}

void Student::setLastName(const std::string& lastName)
{
	_lastName = lastName;
}

void Student::setPhoneNumber(const std::string& phoneNumber)
{
	_phoneNumber = phoneNumber;
}

void Student::setSpeciality(const std::string& speciality)
{
	_speciality = speciality;
}

void Student::setExams(const std::vector<Exam*>& exams)
{
	this->exams = exams;
}

Student::~Student()
{
	// TODO Auto-generated destructor stub
}

std::string Student::print() const
{
	std::stringstream result;
	result << getFirstName() << "\t" << getLastName() << "\n"
			<< getGender() << "\n"
			<< getBirthday() << "\n"
			<< getPhoneNumber() << "\n"
			<< getEmail() << "\n"
			<< getSpeciality() << "\n"
			<<getFacultyNumber() << "\n"
			 << "Exams:\n";

	std::vector<Exam*>::const_iterator exam;
	for (exam = getExams().begin();  exam != getExams().end(); exam++)
	{
		result << (*exam)->print();
	}
	return result.str();
}

void Student::addExam(Exam& exam)
{
	this->exams.push_back(&exam);
}
