#include <iostream>


// functions prototypes
bool alloc_table_2_dim(int***, int, int);
bool dealloc_table_2_dim(int**, int);


using std::cout;
using std::endl;
using std::boolalpha;


const int SIZE_X = 5, SIZE_Y = 3;


int main()
{
	// create pi_table and initialize it
	int** array;
	// create array
	bool alloc_result = alloc_table_2_dim(&array, SIZE_X, SIZE_Y);
	// print result
	cout << "Create Array: " << boolalpha << alloc_result << endl;
	// destroy table
	bool dealloc_result = dealloc_table_2_dim(array, SIZE_X);
	cout << "Delete Array: " << boolalpha << dealloc_result;
	return 0;
}


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
			(*table)[i][j] = i + j;
		}
	}

	// print matrix
	for (int i = 0; i < size_x; i++)
	{
		cout << '[';
		for (int j = 0; j < size_y; j++)
		{
			cout << (*table)[i][j] << " ";
		}
		cout << ']' << endl;
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