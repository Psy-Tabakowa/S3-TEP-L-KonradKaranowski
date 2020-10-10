#include <iostream>
#include <string>
#include "Table.h"


// test functions
void test_procedures();
void test_dynamic_static_allocation();
void test_create_array_objects_static();
void test_create_array_objects_dynamic(int);
// helper functions
void mod_tab(Table* table, int new_size);
void mod_tab(Table table, int new_size);
void show_lines();


using namespace std;


int main()
{
	// testing procedures
	test_procedures();
	// testing static/dynamic and copy
	test_dynamic_static_allocation();
	// test creating objects in list
	test_create_array_objects_static();
	// test creating dynamic array
	test_create_array_objects_dynamic(5);
	return 0;
}


void mod_tab(Table* table, int new_size)
{
	(*table).set_size(new_size);
}

void mod_tab(Table table, int new_size)
{
	table.set_size(new_size);
}

void show_lines()
{
	for (int i = 0; i < 40; i++)
	{
		cout << '=';
	}
	cout << endl;
}

void test_procedures()
{
	show_lines();

	// create default table
	Table table = Table();

	// print informations
	table.print_info();

	show_lines();

	// modify using object
	cout << "Modify using object as argument" << endl;
	mod_tab(table, 10);
	table.print_info();

	show_lines();

	// modify using reference
	cout << "Modify using reference" << endl;
	mod_tab(&table, 10);
	table.print_info();
	show_lines();
}

void test_dynamic_static_allocation()
{
	show_lines();

	// create objects 
	Table table1 = Table("Janusz", 15);
	Table* table2 = new Table(table1);
	Table* table3 = (*table2).clone();

	// print info about objects
	table1.print_info();
	(*table2).print_info();
	(*table3).print_info();

	show_lines();

	// change object names
	cout << "Change name table2 to Albert" << endl;
	cout << "Change name table3 to Zbigniew" << endl;
	table1.set_name("Albert");
	(*table3).set_name("Zbigniew");

	// print info of objects
	table1.print_info();
	(*table2).print_info();
	(*table3).print_info();

	show_lines();

	// delete dynamic created objects
	delete table2;
	delete table3;
}


void test_create_array_objects_static()
{
	show_lines();

	cout << "Creating array of 5 objects 'Table' (static): " << endl;
	Table array[5];

	show_lines();

	cout << "Print array: " << endl;
	for (int i = 0; i < 5; i++)
	{
		array[i].print_info();
	}

	show_lines();
}


void test_create_array_objects_dynamic(int size)
{
	show_lines();

	cout << "Creating array of 5 objects 'Table' (dynamic): " << endl;
	Table** array = new Table* [size];

	for (int i=0; i<size; i++)
	{
		array[i] = new Table();
	}

	show_lines();

	for (int i = 0; i < size; i++)
	{
		(*array[i]).print_info();
	}

	show_lines();
	for (int i = 0; i < size; i++)
	{
		delete array[i];
	}
	delete[] array;
}