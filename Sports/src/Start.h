#ifndef SRC_START_H_
#define SRC_START_H_

#include "Date.h"
#include "Discipline.h"
#include "Athlete.h"
#include <map>
#include <ostream>

enum TypeEnum {qualification,  quarterfinal, semifinal, final};

class Start
{
	friend std::ostream& operator << (std::ostream& output, Start& start);

private:
	Date _date;
	float _time;
	Discipline _discipline;
	std::map<int, Athlete*> _athletes;
	std::map<int, Athlete*> _qualifiedAthletes;
	TypeEnum _type;

public:
	Start();
	Start(Date& date, float hour, Discipline& discipline, TypeEnum type);
	virtual ~Start();

	//getters
	const Date& getDate() const;
	const Discipline& getDiscipline() const;
	float getTime() const;
	TypeEnum getType() const;

	//setters
	void setDate(const Date& date);
	void setDiscipline(const Discipline& discipline);
	void setTime(float hour);
	void setType(TypeEnum type);

	void addAthlete(int id, Athlete& athlete);

	void qualify(float time);
};

#endif /* SRC_START_H_ */
