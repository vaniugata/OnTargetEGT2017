/*
 * Athlete.cpp
 *
 *  Created on: May 3, 2017
 *      Author: vaniugata
 */

#include "Athlete.h"

Athlete::Athlete()
{
	this->_record = 0.0f;
}

Athlete::Athlete(std::string firstName, std::string lastName, float record,
		std::string nationality)
{
	setFirstName(firstName);
	setLastName(lastName);
	setRecord(record);
	setNationality(nationality);
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
	// TODO Auto-generated destructor stub
}

