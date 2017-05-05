/*
 * Discipline.cpp
 *
 *  Created on: May 3, 2017
 *      Author: vaniugata
 */

#include "Discipline.h"

Discipline::Discipline()
{
	this->_worldRecord = 0.0f;
	this->_currentCompetitionRecord = 0.0f;
}

Discipline::Discipline(std::string name, float worldRecord,	float currentCompetitionRecord)
{
	setName(name);
	setWorldRecord(worldRecord);
	setCurrentCompetitionRecord(currentCompetitionRecord);
}

float Discipline::getCurrentCompetitionRecord() const
{
	return _currentCompetitionRecord;
}

const std::string& Discipline::getName() const
{
	return _name;
}

float Discipline::getWorldRecord() const
{
	return _worldRecord;
}

void Discipline::setCurrentCompetitionRecord(float currentCompetitionRecord)
{
	_currentCompetitionRecord = currentCompetitionRecord;
}

void Discipline::setName(const std::string& name)
{
	_name = name;
}

void Discipline::setWorldRecord(float worldRecord)
{
	_worldRecord = worldRecord;
}

Discipline::~Discipline()
{
	// TODO Auto-generated destructor stub
}

