#include "Table.h"
#include <iostream>
using std::cout;
using std::endl;


Table::Table(string name, int array_size)
{
	this->name = name;
	this->size = array_size;
	this->array = new int[this->size];
	cout << "Created with specified parameters: " << this->name << endl;
}

Table::Table()
{
	this->name = DEFAULT_NAME;
	this->size = DEFAULT_LENGTH;
	this->array = new int[this->size];
	cout << "Created with default parameters: " << this->name << endl;
}

Table::Table(const Table& other)
{
	this->name = other.name + "_copy";
	this->size = other.size;
	this->array = new int[this->size];
	for (int i = 0; i < this->size; i++)
	{
		array[i] = other.array[i];
	}
	cout << "Created copy: " << this->name << endl;
}

Table::~Table()
{
	delete[] this->array;
	cout << "Deleted object with name: " << this->name << endl;
}

void Table::print_info()
{
	cout << this->name << " " << this->size << " " << this << endl;
}

void Table::set_name(string new_name)
{
	this->name = new_name;
}

bool Table::set_size(int new_size)
{
	if (new_size < 0)
	{
		cout << "Array size cannot be less than 0." << endl;
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