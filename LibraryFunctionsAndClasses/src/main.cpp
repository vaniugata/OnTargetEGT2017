#include "helpers.h"
#include <iostream>

int main()
{
	int rows, cols;
	std::cin >> rows >> cols;

	int** matrix = new int*[rows];
	for (int i = 0; i < rows; ++i)
	{
		matrix[i] = new int[cols];
	}

	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			std::cin >> matrix[i][j];
		}
	}

	helpers::printMatrix(matrix, rows, cols);

	return 0;
}
