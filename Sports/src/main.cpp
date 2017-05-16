/*Да се направи приложение "Съзтезание по лека атлетика".
Имаме атлети (име, фамилия, най-добро постижение, националност),
дисциплини (име, световен рекорд, рекорд на съзтезанието),
стартове (дата, час, дисциплина, участници в старта, тип (квалификация, четвъртфинал, полуфинал, финал))

След всеки старт трябва да се пази информация за постиженията на атлетите и съответно кой продължава напред.
Накрая да се изведе крайно класиране.

Да има търсене по име на атлет, по име на дисциплина (да се извеждат всички стартове и атлети за тази дисциплина в съзтезанието).
Да се изведе класиране по медали по държави. */

#include <iostream>
#include "Start.h"

int main()
{
	Discipline* discipline = new Discipline("Running 500m", 1.12f, 1.01f);
	Start* qualificationStart = new Start(*new Date(7, 5, 2017), 12.30f, *discipline, qualification);
	Start* quarterfinalStart = new Start(*new Date(12, 4, 2017), 22.45f, *discipline, quarterfinal);

	Athlete* a1 = new Athlete(1, "Petur", "Stoqnov", 12.4f, "Nejer");
	Athlete* a2 = new Athlete(2, "Aleksander", "Povetkin", 12.5f, "Ukraine");
	Athlete* a3 = new Athlete(3, "Mitko", "Shtangata", 10.5f, "Bulgaria");

	qualificationStart->addAthlete(a1->getId(), *a1);
	qualificationStart->addAthlete(a2->getId(), *a2);
	qualificationStart->addAthlete(a3->getId(), *a3);

	std::cout << *qualificationStart;

	return 0;
}

