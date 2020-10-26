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