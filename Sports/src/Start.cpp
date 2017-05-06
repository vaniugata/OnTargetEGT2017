
#include "Start.h"

Start::Start()
{
	_hour = 0.0f;
	_type = qualification;
}

Start::Start(Date& date, float hour, Discipline& discipline, TypeEnum type)
{
	setDate(date);
	setHour(hour);
	setDiscipline(discipline);
	setType(type);
}

const Date& Start::getDate() const
{
	return _date;
}

const Discipline& Start::getDiscipline() const
{
	return _discipline;
}

float Start::getHour() const
{
	return _hour;
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

void Start::setHour(float hour)
{
	_hour = hour;
}

void Start::setType(TypeEnum type)
{
	_type = type;
}

Start::~Start()
{
	// TODO Auto-generated destructor stub
}

void Start::addAthlete(Athlete& athlete)
{
	this->_athletes.push_back(&athlete);
}

void Start::qialification(float time)
{
	std::vector<Athlete*>::iterator athlete;

	for ( athlete = _athletes.begin(); athlete != _athletes.end(); athlete++)
	{
		if ( (*athlete)->getRecord() <= time)
		{
			this->_qualifiedAthletes.push_back(*athlete);
		}
	}
}
