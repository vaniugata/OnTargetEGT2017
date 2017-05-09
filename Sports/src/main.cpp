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
	Start* start = new Start(*new Date(7, 5, 2017), 12.30f, *discipline, qualification);

	Athlete* a1 = new Athlete("Petur", "Stoqnov", 12.4f, "Nejer", 1);
	Athlete* a2 = new Athlete("Aleksander", "Povetkin", 12.5f, "Ukraine", 1);
	Athlete* a3 = new Athlete("Mitko", "Shtangata", 10.5f, "Bulgaria", 1);

	start->addAthlete(1, *a1);
	start->addAthlete(2, *a2);
	start->addAthlete(3, *a3);
	start->qualify(12.4f);

	std::cout << *start;

	return 0;
}

