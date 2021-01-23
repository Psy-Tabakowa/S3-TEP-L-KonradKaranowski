#include "tests.h"
#include "Matrix.h"

using namespace MyAlgebra;

void test_reading_file()
{
	Matrix<int> mat1 = Matrix<int>::read_txt("matint.txt");
	mat1.display();
}