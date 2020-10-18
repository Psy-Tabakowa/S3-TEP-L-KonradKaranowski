#include <iostream>
#include "Table.h"
#include "constants.h"


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
	for (int i = 0; i < LINE_LEN; i++)
	{
		std::cout << LINE_CHAR;
	}
	std::cout << std::endl;
}


void test_procedures()
{
	show_lines();

	// create default table
	Table table = Table(PROC_TAB_NAME, PROC_BASE_TAB_LEN);

	// print informations
	table.print_info();

	show_lines();

	// modify using object
	std::cout << PROC_MODIFY_AS_ARGUMENT << std::endl;
	mod_tab(table, PROC_NEW_TAB_LEN);
	table.print_info();

	show_lines();

	// modify using reference
	std::cout << PROC_MODIFY_AS_REFERENCE << std::endl;
	mod_tab(&table, PROC_NEW_TAB_LEN);
	table.print_info();
	show_lines();
}


void test_dynamic_static_allocation()
{
	show_lines();

	// create objects 
	Table table1 = Table(DYN_JANUSZ_NAME, DYN_JANUSZ_LEN);
	Table* table2 = new Table(table1);
	Table* table3 = (*table2).clone();

	// print info about objects
	table1.print_info();
	(*table2).print_info();
	(*table3).print_info();

	show_lines();

	// change object names
	std::cout << DYN_CHANGE_TAB_TO_ALBERT << std::endl;
	std::cout << DYN_CHANGE_TAB_TO_ZBIGNIEW << std::endl;
	std::string albert = DYN_ALBERT_NAME;
	std::string zbigniew = DYN_ZBIGNIEW_NAME;
	table1.set_name(albert);
	(*table3).set_name(zbigniew);

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

	std::cout << ARR_STAT_CREATE_INFO << std::endl;
	Table array[ARR_STAT_SIZE];

	show_lines();

	for (int i = 0; i < ARR_STAT_SIZE; i++)
	{
		array[i].print_info();
	}

	show_lines();
}


void test_create_array_objects_dynamic(int size)
{
	show_lines();

	std::cout << ARR_DYN_CREATE_INFO << std::endl;
	Table** array = new Table * [size];

	for (int i = 0; i < size; i++)
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