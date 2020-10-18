#include <iostream>
#include "Table.h"


Table::Table(std::string& name, int array_size) : name(name), size(array_size)
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
	if (this->size < 0) this->array = NULL;
	else  this->array = new int[this->size];
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

void Table::set_name(std::string& new_name)
{
	this->name = new_name;
}

bool Table::set_size(int new_size)
{
	if (new_size < 0)
	{
		std::cout << "Array size cannot be less than 0." << std::endl;
		return false;
	}
	this->size = new_size;
	delete[] this->array;
	this->array = new int[this->size];
	return true;
}


Table* Table::clone()
{
	return new Table(*this);
}