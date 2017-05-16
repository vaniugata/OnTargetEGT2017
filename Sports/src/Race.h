#ifndef SRC_RACE_H_
#define SRC_RACE_H_

#include "Start.h"
#include <vector>
#include <map>

class Race
{
private:
	std::vector<Start*> _events;
	static int numOfQualifiedAthletes;


public:
	Race();
	virtual ~Race();

	const int getNumOfQualifiedAthletes() const;

	static void qualifyForNextStart(Start& start, Start& qualification);
};

#endif /* SRC_RACE_H_ */
