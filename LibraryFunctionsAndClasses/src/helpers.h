#include <string>
#include <iostream>
using std::cerr;
#include <locale>
using std::toupper;
#include <sstream>
#include <iomanip>
using std::setprecision;

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

std::string formatCurrency(const std::string& currency, double amount)
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




} // namespace: hepler
