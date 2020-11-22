#include "TreeStatic.h"

TreeStatic::TreeStatic()
{

}

TreeStatic::~TreeStatic()
{
}

NodeStatic* TreeStatic::get_root()
{
	return &root;
}

void TreeStatic::print_tree()
{
	root.print_all_below();
}
