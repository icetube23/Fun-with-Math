#include "stdafx.h"
#include <iostream>
#include "EulersPhi.hpp"
#include "LinearAlgebra.hpp"


int main() {
	la::matrix<double> m(3, 4, 5);
	la::vector v(3, 3.4);

	std::cout << m << std::endl;
	std::cout << std::endl;
	std::cout << v << std::endl;

 	system("pause");
    return 0;
}
