#include "tests.h"
#include "MySmartPointer.h"
#include <iostream>
#include "Tab.h"
#include "Table.h"


void printDumbLine()
{
	for (int i = 0; i < 50; i++)
	{
		std::cout << '=';
	}
	std::cout << '\n';
}


void testTask12()
{
	MySmartPointer<int> ptr1(new int);
	*ptr1 = 2;
	MySmartPointer<int> ptr2 = ptr1;
	MySmartPointer<int> ptr3(ptr2);
	MySmartPointer<int> ptr4 = std::move(ptr3);
	MySmartPointer<int> ptr5(new int);
	MySmartPointer<int> ptr6 (nullptr);
	ptr5 = std::move(ptr2);
	ptr6 = ptr5;

	std::cout << "Pointer1: " << *ptr1 << std::endl;
	// std::cout << "Pointer2: " << *ptr2 << std::endl;
	// std::cout << "Pointer3: " << *ptr3 << std::endl;
	std::cout << "Pointer4: " << *ptr4 << std::endl;
	std::cout << "Pointer5: " << *ptr5 << std::endl;
	std::cout << "Pointer6: " << *ptr6 << std::endl;


	MySmartPointer<int>* dynamicPointer = new MySmartPointer<int>(new int);
	**dynamicPointer = 1234;
	std::cout << "Dynamic Pointer: " << **dynamicPointer << std::endl;
	delete dynamicPointer;
	printDumbLine();
}


void testTask3()
{
	/*
	RefCounter refCounter = RefCounter();
	MySmartPointer<RefCounter> dumbPointer(&refCounter);
	std::cout << "Jakis glupi pointer: " << dumbPointer->get() << std::endl;

	Ca³oœæ rozpadnie siê niczym polska gospodarka po pandemii. 
	Nie mo¿na zwalniaæ pamiêci zaalokowanej statycznie (delete usuwa pamiêæ ze sterty).
	*/
}


void testTask4()
{
	Tab tab1 = Tab();			// pierwszy obiekt
	std::cout << "Created copy of tab1" << std::endl;
	Tab tab2 = tab1;			// kopia
	std::cout << "Created copy of tab2" << std::endl;
	Tab tab3(tab2);				// kopia
	printDumbLine();
	
	std::cout << "Moved tab2 to tab4" << std::endl;
	Tab tab4(std::move(tab2));	// move semantics
	std::cout << "Tab2 after move tab2 -> tab4: " << tab2.getSize() << std::endl;
	std::cout << "Tab3 after move tab2 -> tab4: " << tab4.getSize() << std::endl;
	printDumbLine();

	std::cout << "Moved tab4 to tab5" << std::endl;
	Tab tab5((Tab&&)tab4);		// move wprost
	std::cout << "Tab4 after move tab4 -> tab5: " << tab4.getSize() << std::endl;
	std::cout << "Tab5 after move tab4 -> tab5: " << tab5.getSize() << std::endl;
	printDumbLine();

	std::cout << "Copied using assingment" << std::endl;
	Tab tab6;
	tab6 = tab5; // operator równoœci (PrzewoŸniczek wtf)
	std::cout << "Tab5 after tab6 = tab5: " << tab5.getSize() << std::endl;
	std::cout << "Tab6 after tab6 = tab5: " << tab6.getSize() << std::endl;
	printDumbLine();

	std::cout << "Moved usign move assingment" << std::endl;
	Tab tab7;
	tab7 = std::move(tab6);
	std::cout << "Tab6 after move tab6 -> tab7: " << tab6.getSize() << std::endl;
	std::cout << "Tab7 after move tab6 -> tab7: " << tab7.getSize() << std::endl;
	printDumbLine();
}

void testTask5()
{
	Table tab1, tab2, tab0;
	std::cout << "Concatenation using Table operator+(const Table& other): " << std::endl;
	Table tab3 = tab1 + tab2 + tab0;
	tab3.print_info();
	printDumbLine();

	Table tab5;
	std::cout << "Created using move constructor: " << std::endl;
	Table tab6 = Table(std::move(tab5));
	tab5.print();
	tab6.print();
	printDumbLine();


	std::cout << "Created using regular =: " << std::endl;
	Table tab7;
	tab7 = tab6;
	tab6.print();
	tab7.print();
	printDumbLine();

	std::cout << "Moved using move =: " << std::endl;
	Table tab8;
	tab8 = std::move(tab7);
	tab7.print();
	tab8.print();
}