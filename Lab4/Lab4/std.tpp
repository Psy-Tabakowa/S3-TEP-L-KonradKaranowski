template <class T>
void std::swap(TreeDynamic<T>& tree1, TreeDynamic<T>& tree2)
{
	NodeDynamic<T>* temp = tree1.get_root();
	tree1.set_root(tree2.get_root());
	tree2.set_root(temp);
}


template <class T>
void std::swap(NodeDynamic<T>& node1, NodeDynamic<T>& node2)
{
	// wartoœæ
	T temp_val = node1.get_value();
	node1.set_value(node2.get_value());
	node2.set_value(temp_val);
	

	// dzieci
	std::swap(node1.get_children(), node2.get_children());
	

	// nowi rodzice
	node1.change_parent_for_children(&node1);
	node2.change_parent_for_children(&node2);

}