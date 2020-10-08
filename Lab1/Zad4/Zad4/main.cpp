#include <iostream>
#include <string>
#include "Table.h"
using namespace std;


// test functions
void test_procedures();
void test_dynamic_static_allocation();
// helper functions
void mod_tab(Table* table, int new_size);
void mod_tab(Table table, int new_size);
void show_lines();




int main()
{
	// testing procedures
	test_procedures();
	// testing static/dynamic and copy
	test_dynamic_static_allocation();
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
	Table table = Table();
	table.print_info();
	show_lines();
	cout << "Modify using object as argument" << endl;
	mod_tab(table, 10);
	table.print_info();
	show_lines();
	cout << "Modify using reference" << endl;
	mod_tab(&table, 10);
	table.print_info();
	show_lines();
}

void test_dynamic_static_allocation()
{
	show_lines();
	Table table1 = Table("Janusz", 15);
	Table* table2 = new Table(table1);
	Table* table3 = (*table2).clone();
	table1.print_info();
	(*table2).print_info();
	(*table3).print_info();
	show_lines();
	cout << "Change name table2 to Albert" << endl;
	cout << "Change name table3 to Zbigniew" << endl;
	table1.set_name("Albert");
	(*table3).set_name("Zbigniew");
	table1.print_info();
	(*table2).print_info();
	(*table3).print_info();
	show_lines();
	delete table2;
	delete table3;
}