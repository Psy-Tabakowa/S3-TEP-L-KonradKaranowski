#include "Tab.h"
#include <iostream>


Tab::Tab(const Tab& other)
{
	copy(other);
	std::cout << "Copy" << std::endl;
}

Tab::Tab(Tab&& other)
{
	tab = other.tab;
	size = other.size;
	other.tab = nullptr;
	other.size = 0;
	std::cout << "MOVE" << std::endl;

}

Tab::~Tab()
{
	if (tab != NULL)
	{
		delete tab;
	}
	std::cout << "Destroyed" << std::endl;
}

bool Tab::setSize(int newSize)
{
	return false;
}


Tab& Tab::operator=(const Tab& other)
{
	if (tab != NULL)
	{
		delete[] tab;
	}

	copy(other);
	std::cout << "op=" << std::endl;
	return *this;
}

Tab& Tab::operator=(Tab&& other)
{
	if (&other != this)
	{
		if (tab != NULL)
		{
			delete[] tab;
		}
		this->tab = other.tab;
		this->size = other.size;
		other.tab = nullptr;
		other.size = 0;
	}
	std::cout << "move op=" << std::endl;
	return (*this);
}

void Tab::copy(const Tab& other)
{
	tab = new int[other.size];
	size = other.size;

	for (int i = 0; i < other.size; i++)
	{
		tab[i] = other.tab[i];
	}
}
