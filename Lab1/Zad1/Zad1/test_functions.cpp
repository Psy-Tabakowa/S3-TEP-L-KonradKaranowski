#include <iostream>
#include "constants.h"


void alloc_table_add_5(int size)
{
	if (size < 0)
	{
		std::cout << INVALID_ARGUMENT_ERROR << std::endl;
		return;
	}

	int* table = new int[size];

	for (int i = 0; i < size; i++)
	{
		table[i] = i + VALUE_TO_ADD;
	}

	std::cout << LEFT_SQUARE_BRACKET;
	for (int i = 0; i < size; i++)
	{
		std::cout << table[i] << " ";
	}
	std::cout << RIGHT_SQUARE_BRACKET << std::endl;

	delete[] table;
}