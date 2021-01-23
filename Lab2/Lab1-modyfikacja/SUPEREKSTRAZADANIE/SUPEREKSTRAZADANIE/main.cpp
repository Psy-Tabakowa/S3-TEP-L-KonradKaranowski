#include "prototypes.h"
#include <iostream>


int main()
{
	int* arr = new int[2];
	arr[0] = 5;
	arr[1] = 2;
	int** array = allocateregularArray2D(2, arr);
	bool b = deallocateIrregularArray2D(array, 2);
	std::cout << std::boolalpha << b;
	return 0;
}