#include <iostream>
using std::cout;
using std::endl;



int const VALUE_TO_ADD = 5;


void alloc_table_add_5(int);



int main()
{
	// call function
	alloc_table_add_5(4);
}


void alloc_table_add_5(int size)
{
	if (size < 0)
	{
		cout << "Invalid argument, array size cannot be less than 0" << endl;
		return;
	}
	// create new array
	int* table = new int[size];

	// fill values
	for (int i = 0; i < size; i++)
	{
		table[i] = i + VALUE_TO_ADD;
	}

	// print array
	cout << '[';
	for (int i = 0; i < size; i++)
	{
		cout << table[i] << " ";
	}
	cout << ']';

	// delete table
	delete[] table;
}