#pragma once
#include <ostream>


class TestClass
{
public:
	friend std::ostream& operator<<(std::ostream& os, const TestClass& tc) { os << "TestClass"; return os; }
};