#ifndef SRC_DISCIPLINE_H_
#define SRC_DISCIPLINE_H_

#include <string>

class Discipline
{
private:
	std::string _name;
	float _worldRecord;
	float _currentCompetitionRecord;

public:
	Discipline();
	Discipline(std::string name, float worldRecord, float currentCompetitionRecord);
	virtual ~Discipline();

	//getters
	float getCurrentCompetitionRecord() const;
	const std::string& getName() const;
	float getWorldRecord() const;

	//setters
	void setCurrentCompetitionRecord(float currentCompetitionRecord);
	void setName(const std::string& name);
	void setWorldRecord(float worldRecord);
};

#endif /* SRC_DISCIPLINE_H_ */
