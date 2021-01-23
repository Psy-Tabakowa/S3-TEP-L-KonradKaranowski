#include "tests.h"

void test_reading_file()
{
	Matrix<int> mat1 = read_txt<int>("matint.txt");
	mat1.display();
}