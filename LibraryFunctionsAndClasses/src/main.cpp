#include "helpers.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <math.h>
using namespace helpers;

int main()
{
	RealNumber rn;
	rn = helpers::devide(5,2);
	std::cout << rn.quotient << "," << rn.remainder;

	return 0;
}
