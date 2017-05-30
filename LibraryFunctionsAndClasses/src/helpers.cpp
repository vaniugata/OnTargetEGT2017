#include "helpers.h"

#include <iostream>
using std::cerr;
#include <locale>
using std::toupper;
#include <sstream>
using std::stringstream;
#include <iomanip>
using std::setprecision;
#include <math.h>


namespace helpers
{
std::string toupper(const std::string& input)
{
	std::string result;
	for (unsigned int i = 0; i < input.length(); ++i)
	{
		result += std::toupper(input[i]);
	}
	return result;
}

const std::string formatCurrency(const std::string& currency, double amount)
{
	std::string result;
	std::stringstream ss;
	if(currency.length() != 3)
	{
		std::cerr << "Invalid currency format!\n";
		return "";
	}

	ss << std::fixed << std::setprecision(9) << amount;

	ss >> result;
	result.append(" ");
	result.append(toupper(currency));

	return result;
}

double myRound(double d_number, int decimalPlaces)
{
	if(decimalPlaces < 0)
	{
		long long result = (long long)d_number;
		for (int i = 0; i < decimalPlaces * -1; ++i)
		{
			int rem = result % 10;
			if(rem >= 5)
			{
				result += 1;
			}

			result /= 10;
		}

		return (double)result;
	}

	double multiplicator = pow(10, decimalPlaces);
	return round(d_number * multiplicator) / multiplicator;
}

RealNumber devide(int devisible, int devider)
{
	RealNumber rn;
	rn.remainder = devisible % devider;
	rn.quotient = devisible / devider;

	return rn;
}

} // helpers


