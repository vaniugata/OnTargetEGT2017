#ifndef SRC_EXAM_H_
#define SRC_EXAM_H_

#include<string>

class Exam
{
private:
	std::string _name;
	std::string _lecturer;
	float _grade;

public:
	Exam(const std::string& name = "", const std::string& lecturer = "", float grade = 0.0f);
	virtual ~Exam();

	//getters
	float getGrade() const;
	const std::string& getLecturer() const;
	const std::string& getName() const;

	//setters
	void setGrade(float grade);
	void setLecturer(const std::string& lecturer);
	void setName(const std::string& name);

	std::string print() const;
};

#endif /* SRC_EXAM_H_ */
