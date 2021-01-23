#pragma once
#include "NodeDynamic.h"


template <typename T> class TreeDynamic
{
private:
	NodeDynamic<T>* root;
public:
	TreeDynamic();
	~TreeDynamic();
	NodeDynamic<T>* get_root();
	void set_root(NodeDynamic<T>* root);
	bool is_consistent();
	void print_tree();
	bool move_subtree(NodeDynamic<T>* parent_node, NodeDynamic<T>* new_child_node);
};

#include "TreeDynamic.tpp"