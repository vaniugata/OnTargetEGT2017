#ifndef SRC_STUDENT_H_
#define SRC_STUDENT_H_

#include <string>
#include <vector>
#include "Exam.h"

class Student
{
private:
	std::string _firstName;
	std::string _lastName;
	std::string _gender;
	std::string _birthday;
	std::string _phoneNumber;
	std::string _email;
	int _course;
	std::string _speciality;
	long int _facultyNumber;
	std::vector<Exam*> exams;

public:
	Student(const std::string& _firstName = "",
	const std::string& lastName = "",
	const std::string& gender = "",
	const std::string& birthday = "",
	const std::string& phoneNumber = "",
	const std::string& email = "",
	int course = 1,
	const std::string& speciality = "",
	long int facultyNumber = 1,
	const std::vector<Exam*>& exams = std::vector<Exam*>() );

	virtual ~Student();

	//getters
	const std::string& getBirthday() const;
	int getCourse() const;
	const std::string& getEmail() const;
	long int getFacultyNumber() const;
	const std::string& getFirstName() const;
	const std::string& getGender() const;
	const std::string& getLastName() const;
	const std::string& getPhoneNumber() const;
	const std::string& getSpeciality() const;
	const std::vector<Exam*>& getExams() const;

	//setters
	void setBirthday(const std::string& birthday);
	void setCourse(int course);
	void setEmail(const std::string& email);
	void setFacultyNumber(long int facultyNumber);
	void setFirstName(const std::string& firstName);
	void setGender(const std::string& gender);
	void setLastName(const std::string& lastName);
	void setPhoneNumber(const std::string& phoneNumber);
	void setSpeciality(const std::string& speciality);
	void setExams(const std::vector<Exam*>& exams);

	std::string print() const;
	void addExam(Exam& exam);

};

#endif /* SRC_STUDENT_H_ */
