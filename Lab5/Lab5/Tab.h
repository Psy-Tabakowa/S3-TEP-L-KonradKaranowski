#pragma once
#include <iostream>


class Tab
{
	int* tab;
	int size;
	void copy(const Tab& other);
public:
	Tab() { tab = new int[10]; size = 10; }
	Tab(const Tab& other);
	Tab(Tab&& other);
	Tab& operator=(const Tab& other);
	Tab& operator=(Tab&& other);
	~Tab();
	bool setSize(int newSize);
	int getSize() { return size; };
};