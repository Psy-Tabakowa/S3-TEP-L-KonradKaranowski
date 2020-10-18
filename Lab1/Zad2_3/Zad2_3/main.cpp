#include <iostream>
#include "main_constants.h"
#include "prototypes.h"


int main()
{
	// create pi_table and initialize it
	int** array;
	// create array
	bool alloc_result = alloc_table_2_dim(&array, SIZE_X, SIZE_Y);
	// print result
	std::cout << CREATE_ARRAY_INFO << std::boolalpha << alloc_result << std::endl;
	// destroy table
	bool dealloc_result = dealloc_table_2_dim(array, SIZE_X);
	// print result
	std::cout << DELETE_ARRAY_INFO << std::boolalpha << dealloc_result;
	return 0;
}