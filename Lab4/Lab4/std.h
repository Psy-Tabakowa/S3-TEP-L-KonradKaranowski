#pragma once
#include "NodeDynamic.h"
#include "TreeDynamic.h"


namespace std
{
	template <class T>
	void swap(NodeDynamic<T>& node1, NodeDynamic<T>& node2);
	template <class T>
	void swap(TreeDynamic<T>& tree1, TreeDynamic<T>& tree2);
}


#include "std.tpp"