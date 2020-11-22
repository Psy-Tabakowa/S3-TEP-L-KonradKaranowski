#pragma once
#include "NodeStatic.h"


class TreeStatic
{
private:
	NodeStatic root;
public:
	TreeStatic();
	~TreeStatic();
	NodeStatic* get_root();
	void print_tree();
};