#ifndef HELPERS_H
#define HELPERS_H

#include <string>
#include <iostream>
#include <cstdlib>
using std::rand;
#include <time.h>
using std::srand;

namespace helpers
{

std::string toupper(const std::string& input);
const std::string formatCurrency(const std::string& currency, double amount);

 template<typename T> void printArr(T* arr, int size)
{
	std::cout << "[";
	for (int i = 0; i < size; ++i)
	{
		std::cout << arr[i];

		if( i < size - 1)
			std::cout << ", ";
	}
	std::cout << "]";
}

template <typename T> void printMatrix(T** matrix, int rows, int cols)
{
	for (int i = 0; i < rows; ++i)
	{
		std::cout << "[";
		for (int j = 0; j < cols; ++j)
		{
			std::cout << matrix[i][j];
			if(j < cols - 1)
				std::cout << ", ";
		}
		std::cout << "]\n";
	}
}

double myRound(double d_number, int decimalPlaces);

struct RealNumber
{
	int quotient;
	int remainder;
};

RealNumber devide(int devisible, int devider);

template <typename T> T getRandFromRange(T from, T to)
{
	srand(time(NULL));

	T result = rand() % (to - from) + from;

	return result;
}

} // namespace: heplers
#endif
