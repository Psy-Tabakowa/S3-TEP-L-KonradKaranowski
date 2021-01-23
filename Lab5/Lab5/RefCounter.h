#pragma once


class RefCounter
{
private:
	int counter;
public:
	RefCounter() { counter = 0; };
	int add() { return (++counter); };
	int dec() { return (--counter); };
	int get() { return counter; };
};