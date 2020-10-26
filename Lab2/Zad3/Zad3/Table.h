#pragma once
#include <string>


class Table
{
private:
	std::string name;
	int size;
	int* array;
	Table(std::string& name, int array_size, int* array);
public:
	// constructors
	Table(std::string& name, int array_size);
	Table();
	Table(const Table& other);
	// destructor
	~Table();
	// methods
	void print_info();
	void print();
	Table operator+(const Table& other);
	void set_name(std::string& new_name);
	void set_value_at(int offset, int new_val);
	bool set_size(int new_size);
	Table* clone();
};