#pragma once
#include <string>
using std::string;
class Table
{
private:
	string const DEFAULT_NAME = "Default Name";
	int const DEFAULT_LENGTH = 5;
	string name;
	int size;
	int* array = nullptr;
public:
	// constructors
	Table(string name, int array_size);
	Table();
	Table(const Table& other);
	// methods
	void print_info();
	void set_name(string new_name);
	bool set_size(int new_size);
	Table* clone();
	// destructor
	~Table();
};

