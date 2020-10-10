#include <iostream>


// functions prototypes
void alloc_table_add_5(int);


using std::cout;
using std::endl;



int const VALUE_TO_ADD = 5;



int main()
{
	alloc_table_add_5(4);
}


void alloc_table_add_5(int size)
{
	if (size < 0)
	{
		cout << "Invalid argument, array size cannot be less than 0" << endl;
		return;
	}

	int* table = new int[size];

	for (int i = 0; i < size; i++)
	{
		table[i] = i + VALUE_TO_ADD;
	}

	cout << '[';
	for (int i = 0; i < size; i++)
	{
		cout << table[i] << " ";
	}
	cout << ']';

	delete[] table;
}