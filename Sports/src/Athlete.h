#ifndef SRC_ATHLETE_H_
#define SRC_ATHLETE_H_

#include <string>

class Athlete
{
private:
	std::string _firstName;
	std::string _lastName;
	float _record;
	std::string _nationality;

public:
	Athlete();
	Athlete(std::string firstName, std::string lastName, float record, std::string nationality);
	virtual ~Athlete();

	//setters
	void setFirstName(const std::string& firstName);
	void setLastName(const std::string& lastName);
	void setNationality(const std::string& nationality);
	void setRecord(float record);

	//getters
	const std::string& getFirstName() const;
	const std::string& getLastName() const;
	const std::string& getNationatlity() const;
	float getRecord() const;


};

#endif /* SRC_ATHLETE_H_ */
