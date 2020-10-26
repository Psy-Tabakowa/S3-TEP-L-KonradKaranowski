#include "Table.h"


int main()
{
	Table tab_0, tab_1;
	tab_0.set_size(6);
	tab_1.set_size(4);
	tab_0 = tab_1;
	// nie dzia³a, bo próbujê dwa razy dealokowaæ array
	return 0;
}