#include <iostream>
#include "constants.h"


bool alloc_table_2_dim(int*** table, int size_x, int size_y)
{
	if ((size_x < 0) || (size_y) < 0)
	{
		return false;
	}
	*table = new int* [size_x];

	// create an array
	for (int i = 0; i < size_x; i++)
	{
		(*table)[i] = new int[size_y];
	}

	// fill with dummy values
	for (int i = 0; i < size_x; i++)
	{
		for (int j = 0; j < size_y; j++)
		{
			(*table)[i][j] = size_x - i + j;
		}
	}

	// print matrix
	for (int i = 0; i < size_x; i++)
	{
		std::cout << LEFT_SQUARE_BRACKET;
		for (int j = 0; j < size_y; j++)
		{
			std::cout << (*table)[i][j] << " ";
		}
		std::cout << RIGHT_SQUARE_BRACKET << std::endl;
	}
	return true;
}


bool dealloc_table_2_dim(int** table, int size_x)
{
	if (size_x < 0)
	{
		return false;
	}
	for (int i = 0; i < size_x; i++)
	{
		delete[] table[i];
	}
	delete[] table;
	return true;
}