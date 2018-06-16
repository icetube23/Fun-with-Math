#include "stdafx.h"
#include "LinearAlgebra.hpp"
#include <iostream>
#include <chrono>

int main() {
	la::fields::complex z(5, 2);
	la::fields::complex z2(z + z);
	la::fields::module_ring<5> f(5);

	la::Matrix<la::fields::module_ring<2>> m(3, 3);

	std::cout << (f != 10) << std::endl;
	std::cout << f << std::endl;
	system("pause");
    return 0;
}
