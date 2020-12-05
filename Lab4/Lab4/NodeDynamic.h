#pragma once
#include <iostream>
#include <vector>


template <typename T> class NodeDynamic
{
private:
	T val;
	NodeDynamic* parent;
	std::vector<NodeDynamic<T>*> children;
	void print_children_below();
public:
	NodeDynamic();
	~NodeDynamic();
	void set_value(T new_val);
	int get_children_number();
	void add_new_child();
	void add_new_child(NodeDynamic<T>* child);
	bool remove_child(NodeDynamic<T>* child);
	NodeDynamic<T>* get_child(int child_offset);
	NodeDynamic<T>* get_parent();
	bool is_consistent();
	bool all_consistent();
	void print();
	void print_all_below();
};

#include "NodeDynamic.tpp"