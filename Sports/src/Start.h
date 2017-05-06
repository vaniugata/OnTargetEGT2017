/*
 * Start.h
 *
 *  Created on: May 5, 2017
 *      Author: vaniugata
 */

#ifndef SRC_START_H_
#define SRC_START_H_

#include "Date.h"
#include "Discipline.h"
#include "Athlete.h"
#include <vector>
#include <ostream>

enum TypeEnum {qualification,  quarterfinal, semifinal, final};

class Start
{
	friend std::ostream& operator << (std::ostream& output, Start& start);

private:
	Date _date;
	float _hour;
	Discipline _discipline;
	std::vector<Athlete*> _athletes;
	std::vector<Athlete*> _qualifiedAthletes;
	TypeEnum _type;

public:
	Start();
	Start(Date& date, float hour, Discipline& discipline, TypeEnum type);
	virtual ~Start();

	//getters
	const Date& getDate() const;
	const Discipline& getDiscipline() const;
	float getHour() const;
	TypeEnum getType() const;

	//setters
	void setDate(const Date& date);
	void setDiscipline(const Discipline& discipline);
	void setHour(float hour);
	void setType(TypeEnum type);

	void addAthlete(Athlete& athlete);

	void qialification(float time);
};

#endif /* SRC_START_H_ */
