#include "Race.h"

int Race::numOfQualifiedAthletes = 8;

Race::Race()
{

}

Race::~Race()
{
	// TODO Auto-generated destructor stub
}

const int Race::getNumOfQualifiedAthletes() const
{
	return numOfQualifiedAthletes;
}

void Race::qualifyForNextStart(Start& start, Start& qualification)
{
	for (int i = 0; i < numOfQualifiedAthletes; ++i)
	{
		int id = start.getAthletes().at(i)->getId();
		Athlete* athlete = start.getAthletes().at(i);
		qualification.addQualifiedAthelete(id, *athlete);
	}
}
