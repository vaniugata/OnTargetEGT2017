#include "helpers.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <math.h>
using namespace helpers;

int main()
{

	double n = 1234.5678;
	std::cout << std::setprecision(10) << helpers::myRound(n, -1);

	return 0;
}
