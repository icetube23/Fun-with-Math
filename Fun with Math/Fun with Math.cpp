#include "stdafx.h"
#include <iostream>
#include "EulersPhi.hpp"
#include "LinearAlgebra.hpp"


int main() {
	la::matrix<double> m = { { 1, 2, 3 },
							 { 4, 5, 6 }, 
	                         { 7, 8, 8 } };
	la::vector<double> v = { { 1, 2, 3 } };

	std::cout << m * m.invert() << std::endl;
	std::cout << std::endl;
	std::cout << v.unit() << std::endl;

 	system("pause");
    return 0;
}
