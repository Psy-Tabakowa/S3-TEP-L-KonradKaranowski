#pragma once
#include "NodeDynamic.h"


class TreeDynamic
{
private:
	NodeDynamic* root;
public:
	TreeDynamic();
	~TreeDynamic();
	NodeDynamic* get_root();
	void print_tree();
	bool move_subtree(NodeDynamic* parent_node, NodeDynamic* new_child_node);
};