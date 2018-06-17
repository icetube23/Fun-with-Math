#include "stdafx.h"
#include "LinearAlgebra.hpp"
#include <iostream>
#include <chrono>

int main() {
	la::fields::complex z(5, 2);
	la::fields::complex z3(z + z);
	la::fields::module_ring<5> f(5);

	la::Matrix<double> m(3, 3);

	la::Vector<la::fields::module_ring<3>> v(3, 4);
	std::cout << v << std::endl;

	system("pause");
    return 0;
}
