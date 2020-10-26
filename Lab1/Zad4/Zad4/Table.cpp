#include <iostream>
#include "Table.h"


Table::Table(const std::string& name, int array_size) : name(name), size(array_size)
{
	if (this->size < 0)
	{
		this->array = NULL;
	}
	else
	{
		this->array = new int[this->size];
	}
	std::cout << "Created with specified parameters: " << this->name << std::endl;
}

Table::Table() : name(DEFAULT_NAME), size(DEFAULT_LENGTH)
{
	if (this->size < 0)
	{
		this->array = NULL;
	}
	else
	{
		this->array = new int[this->size];
	}
	std::cout << "Created with default parameters: " << this->name << std::endl;
}

Table::Table(const Table& other) : name(other.name + "_copy"), size(other.size)
{
	if (this->size < 0)
	{
		this->array = NULL;
	}
	else
	{
		this->array = new int[this->size];
		for (int i = 0; i < this->size; i++)
		{
			array[i] = other.array[i];
		}
	}
	std::cout << "Created copy: " << this->name << std::endl;
}

Table::~Table()
{
	if (this->array != NULL)
	{
		delete[] this->array;
	}
	std::cout << "Deleted object with name: " << this->name << std::endl;
}

void Table::print_info()
{
	std::cout << this->name << " " << this->size << " " << this << std::endl;
}

void Table::set_name(const std::string& new_name)
{
	this->name = new_name;
}

bool Table::set_size(int new_size)
{
	if (new_size <= 0)
	{
		std::cout << "Array size has to be positive." << std::endl;
		return false;
	}
	int* new_array = new int[new_size];
	if (array != NULL)
	{
		for (int i = 0; i < std::min(size, new_size); i++)
		{
			new_array[i] = array[i];
		}
		delete[] array;
	}
	array = new_array;
	return true;
}

Table* Table::clone()
{
	return new Table(*this);
}