#include "stdafx.h"
#include "LinearAlgebra.hpp"
#include <iostream>

int main() {
	la::matrix<> m(3, 3);
	la::vector<> v(3, 3);
	v[1] = 100;

	std::cout << v << std::endl;

	system("pause");
    return 0;
}
