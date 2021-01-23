#include <iostream>
#include "Table.h"


Table::Table(std::string& name, int array_size) :
	name(name),
	size(array_size <= 0 ? 0 : array_size)
{
	if (size == 0)
	{
		array = nullptr;
	}
	else
	{
		array = new int[size];
	}
	std::cout << "Created with specified parameters: " << array << std::endl;
}

Table::Table(Table&& other) :
	name(other.name),
	array(other.array),
	size(other.size)
{
	other.array = nullptr;
	other.size = 0;
	std::cout << "Moved object with array: " << array << std::endl;
}

Table::Table() :
	name("The Table of Destiny"),
	size(4)
{
	if (size == 0)
	{
		array = nullptr;
	}
	else
	{
		array = new int[size];
		for (int i = 0; i < size; i++)
		{
			array[i] = 0;
		}
	}
	std::cout << "Created with default parameters: " << array << std::endl;
}

Table::Table(const Table& other) :
	name(other.name + "_copy"),
	size(other.size)
{
	if (size == 0)
	{
		array = nullptr;
	}
	else
	{
		array = new int[size];
		for (int i = 0; i < size; i++)
		{
			array[i] = other.array[i];
		}
	}
	std::cout << "Created copy: " << array << std::endl;
}

Table::Table(std::string& name, int array_size, int* array) :
	name(name + "_concated"),
	size(array_size),
	array(array)
{
	std::cout << "Created using concatenation: " << array << std::endl;
}

Table::~Table()
{
	delete[] array;
	std::cout << "Deleted object: " << array << std::endl;
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
		std::cout << "Array size has to be positive." << std::endl;
		return false;
	}
	int* new_array = new int[new_size];
	if (array != nullptr)
	{
		for (int i = 0; i < std::min(size, new_size); i++)
		{
			new_array[i] = array[i];
		}
		delete[] array;
	}
	size = new_size;
	array = new_array;
	return true;
}

void Table::set_value_at(int offset, int new_value)
{
	if ((offset >= size) || (offset < 0))
	{
		std::cout << "Offset has to be lesser than array size and greater than -1" << std::endl;
		return;
	}
	array[offset] = new_value;
}

void Table::print()
{
	std::cout << "Array with pointer: " << array << " and size: " << size << std::endl;
	std::cout << '[';
	if (array == nullptr)
	{
		std::cout << "NULL";
	}
	else
	{
		for (int i = 0; i < size; i++)
		{
			std::cout << array[i] << ' ';
		}
	}
	std::cout << ']' << std::endl;
}


Table* Table::clone()
{
	return new Table(*this);
}


Table Table::operator+(const Table& other)
{
	int new_size = size + other.size;
	int* new_array;
	if (new_size == 0)
	{
		new_array = nullptr;
	}
	else
	{
		new_array = new int[new_size];
		for (int i = 0; i < size; i++)
		{
			new_array[i] = array[i];
		}
		for (int i = 0; i < other.size; i++)
		{
			new_array[i + size] = other.array[i];
		}
	}
	return Table(name, new_size, new_array);
}

Table& Table::operator=(const Table& other)
{
	std::cout << "op=" << std::endl;
	if (&other != this)
	{
		delete[] array;
		std::cout << "Deleted array: " << array << std::endl;
		int* new_array;
		if (other.size == 0)
		{
			new_array = nullptr;
		}
		else
		{
			new_array = new int[other.size];
			for (int i = 0; i < other.size; i++)
			{
				new_array[i] = other.array[i];
			}
		}
		std::cout << "New array: " << new_array << std::endl;
		array = new_array;
		name = other.name + "_=";
		size = other.size;
	}
	return *this;
}

Table& Table::operator=(Table&& other)
{
	if (&other != this)
	{
		delete[] array;
		std::cout << "Deleted array: " << array << std::endl;
		array = other.array;
		size = other.size;
		other.array = nullptr;
		other.size = 0;
	}
	std::cout << "move op=" << std::endl;
	return *this;
}
