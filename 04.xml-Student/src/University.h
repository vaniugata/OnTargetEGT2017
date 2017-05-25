#ifndef SRC_UNIVERSITY_H_
#define SRC_UNIVERSITY_H_

#include "Student.h"
#include <vector>

class University
{
private:
	static std::vector<Student*> _students;

public:
	University();
	virtual ~University();

	static void Add(Student& student);
	static std::vector<Student*>& getStudents();
	static void writeToFile(std::ofstream& outputFile);

};

#endif /* SRC_UNIVERSITY_H_ */
