
#include "Start.h"
#include <iostream>

Start::Start()
{
	_time = 0.0f;
	_type = qualification;
}

Start::Start(Date& date, float hour, Discipline& discipline, TypeEnum type)
{
	setDate(date);
	setTime(hour);
	setDiscipline(discipline);
	setType(type);
}

Start::~Start()
{
}

const Date& Start::getDate() const
{
	return _date;
}

const Discipline& Start::getDiscipline() const
{
	return _discipline;
}

float Start::getTime() const
{
	return _time;
}

TypeEnum Start::getType() const
{
	return _type;
}

void Start::setDate(const Date& date)
{
	_date = date;
}

void Start::setDiscipline(const Discipline& discipline)
{
	_discipline = discipline;
}

void Start::setTime(float hour)
{
	_time = hour;
}

void Start::setType(TypeEnum type)
{
	_type = type;
}


void Start::addAthlete(int id, Athlete& athlete)
{
	std::cout << &athlete;
	this->_athletes[id] = &athlete;
}

void Start::qualify(float time)
{
	//TOOD: REFACTOR THIS
}

std::ostream& operator << (std::ostream& output, Start& start)
{
	output << "Event info:\n";
	output << "Date: " << start._date.toString() << " Time: " << start._time << "\n";
	output << "Discipline: " << start._discipline.getName() <<
			" Current record: " << start._discipline.getCurrentCompetitionRecord() << "\n";

	output << "Competitors:\n";

	std::map<int,Athlete*>::iterator athlete;
	for ( athlete = start._athletes.begin(); athlete != start._athletes.end(); athlete++)
		{
			output << athlete->second->getFirstName() << " "

					<< athlete->second->getLastName() <<
					" Record: "	<< athlete->second->getRecord()
					<< " " << athlete->second->getNationatlity() << "\n";
		}
	output << "Finalists:\n";
	for ( athlete = start._qualifiedAthletes.begin(); athlete != start._qualifiedAthletes.end(); athlete++)
			{
				output << athlete->second->getFirstName() << " "
						<< athlete->second->getLastName() <<
						" Record: "	<< athlete->second->getRecord()
						<< " " << athlete->second->getNationatlity() << "\n";
			}

	return output;
}
