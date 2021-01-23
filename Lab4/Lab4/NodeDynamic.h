#pragma once
#include <iostream>
#include <vector>


template <typename T> class NodeDynamic
{
private:
	T val;
	NodeDynamic* parent;
	std::vector<NodeDynamic*> children;
	void print_children_below();
public:
	NodeDynamic();
	~NodeDynamic();
	void set_value(T new_val);
	int get_children_number();
	void set_parent(NodeDynamic* new_parent);
	void add_new_child();
	void add_new_child(NodeDynamic* child);
	bool remove_child(NodeDynamic* child);
	void change_parent_for_children(NodeDynamic* new_parent);
	std::vector<NodeDynamic*>& get_children();
	T get_value();
	NodeDynamic* get_child(int child_offset);
	NodeDynamic* get_parent();
	bool is_consistent();
	bool all_consistent();
	void print();
	void print_all_below();
};

#include "NodeDynamic.tpp"