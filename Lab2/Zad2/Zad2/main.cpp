#include "Table.h"


int main()
{
	Table tab_0, tab_1;
	tab_0.set_size(6);
	tab_1.set_size(4);
	tab_0 = tab_1;
	// dzia�a, ale jest memory leak, bo nie dealokuj� "array"
	return 0;
}