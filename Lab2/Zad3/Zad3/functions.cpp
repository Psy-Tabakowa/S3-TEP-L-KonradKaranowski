#include <iostream>
#include <string>
#include "Table.h"



void test_copy()
{
	Table tab_0, tab_1;
	for (int i = 0; i < 8; i++)
	{
		tab_0.set_value_at(i, i);
		tab_1.set_value_at(i, 50 + i);
	}
	tab_0.set_size(6);
	tab_1.set_size(4);
	std::cout << "Current state of arrays: " << std::endl;
	tab_0.print();
	tab_1.print();

	tab_0 = tab_1;
	std::cout << "Arrays after operation: tab_0 = tab_1: " << std::endl;
	tab_0.print();
	tab_1.print();

	tab_1.set_value_at(2, 100);
	std::cout << "Arrays after setting tab1 third item to 100: " << std::endl;
	tab_0.print();
	tab_1.print();
}


void test_concatenation()
{
	Table tab_0, tab_1;
	for (int i = 0; i < 8; i++)
	{
		tab_0.set_value_at(i, i);
		tab_1.set_value_at(i, 50 + i);
	}
	std::cout << "Current state of arrays: " << std::endl;
	tab_0.print();
	tab_1.print();

	Table tab_2 = tab_0 + tab_1;
	std::cout << "Array after concatenation: " << std::endl;
	tab_2.print();
}


void test_concatenation_with_zeros()
{
	std::string str = "Name1";;
	Table tab1 = Table(str, 2);;
	Table tab2 = Table();;
	for (int i = 0; i < 8; i++)
	{
		tab2.set_value_at(i, i);
	}
	tab1.print();
	tab2.print();
	Table tab3 = tab1 + tab2;;
	std::cout << "Array after concatenation: " << std::endl;
	tab3.print();
}