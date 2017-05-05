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

enum TypeEnum {qualification,  quarterfinal, semifinal, final};

class Start
{
private:
	Date _date;
	float _hour;
	Discipline _discipline;
	std::vector<Athlete*> _athletes;
	TypeEnum _type;

public:
	Start();
	virtual ~Start();
};

#endif /* SRC_START_H_ */
