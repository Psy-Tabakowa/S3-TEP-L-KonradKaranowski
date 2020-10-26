#include <iostream>


int** allocateregularArray2D(int sizeX, int* sizesY)
{
	if (sizeX < 0)
	{
		return NULL;
	}
	
	if (sizesY == NULL)
	{
		return NULL;
	}

	for (int i = 0; i < sizeX; i++)
	{
		if (sizesY[i] < 0)
		{
			return NULL;
		}
	}

	int** array = new int* [sizeX];
	for (int i = 0; i < sizeX; i++)
	{
		array[i] = new int[sizesY[i]];
	}

	return array;
}


bool deallocateIrregularArray2D(int** array2D, int sizeX)
{
	if ((array2D == NULL) || (sizeX < 0))
	{
		return false;
	}

	for (int i = 0; i < sizeX; i++)
	{
		delete[] array2D[i];	
	}
	delete[] array2D;
	return true;
}