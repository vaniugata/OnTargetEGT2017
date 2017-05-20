#ifndef HELPERS_H
#define HELPERS_H

#include <string>
#include <iostream>

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


} // namespace: hepler
#endif
