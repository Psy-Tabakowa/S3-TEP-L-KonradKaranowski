#include <iostream>
#include "Table.h"
#include "constans.h"


Table::Table(std::string& name, int array_size) : name(name), size(array_size)
{
	if (size < 0)
	{
		array = NULL;
	}
	else
	{
		array = new int[size];
	}
	std::cout << "Created with specified parameters: " << name << std::endl;
}

Table::Table() : name(DEFAULT_NAME), size(DEFAULT_LENGTH)
{
	if (size < 0) array = NULL;
	else  array = new int[size];
	std::cout << "Created with default parameters: " << name << std::endl;
}

Table::Table(const Table& other) : name(other.name + "_copy"), size(other.size)
{
	if (size < 0)
	{
		array = NULL;
	}
	else
	{
		array = new int[size];
		for (int i = 0; i < size; i++)
		{
			array[i] = other.array[i];
		}
	}
	std::cout << "Created copy: " << name << std::endl;
}

Table::~Table()
{
	if (array != NULL)
	{
		delete[] array;
	}
	std::cout << "Deleted object with name: " << name << std::endl;
}

void Table::print_info()
{
	std::cout << name << " " << size << " " << this << std::endl;
}

void Table::set_name(std::string& new_name)
{
	name = new_name;
}

bool Table::set_size(int new_size)
{
	if (new_size < 0)
	{
		std::cout << "Array size cannot be less than 0." << std::endl;
		return false;
	}
	size = new_size;
	delete[] array;
	array = new int[size];
	return true;
}


Table* Table::clone()
{
	return new Table(*this);
}