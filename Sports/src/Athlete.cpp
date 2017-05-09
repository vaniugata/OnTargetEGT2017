#include "Athlete.h"

Athlete::Athlete()
{
	this->_record = 0.0f;
	this->_id = 0.0f;
}

Athlete::Athlete(std::string firstName, std::string lastName, float record,
		std::string nationality, int id)
{
	setFirstName(firstName);
	setLastName(lastName);
	setRecord(record);
	setNationality(nationality);
	setId(id);
}

void Athlete::setFirstName(const std::string& firstName)
{
	_firstName = firstName;
}

void Athlete::setLastName(const std::string& lastName)
{
	_lastName = lastName;
}

void Athlete::setNationality(const std::string& nationality)
{
	_nationality = nationality;
}

const std::string& Athlete::getFirstName() const
{
	return _firstName;
}

const std::string& Athlete::getLastName() const
{
	return _lastName;
}

const std::string& Athlete::getNationatlity() const
{
	return _nationality;
}

int Athlete::getId() const
{
	return _id;
}

void Athlete::setId(int id)
{
	_id = id;
}

const std::string& Athlete::getNationality() const
{
	return _nationality;
}

float Athlete::getRecord() const
{
	return _record;
}

void Athlete::setRecord(float record)
{
	_record = record;
}

Athlete::~Athlete()
{
}

