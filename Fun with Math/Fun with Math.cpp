#include "stdafx.h"
#include "LinearAlgebra.hpp"
#include <iostream>

int main() {
	la::matrix<> m = la::matrix<>::IdentityMatrix(10);
	la::vector<> v(3, 3);
	v[1] = 100;

	std::cout << la::det(m) << std::endl;

	system("pause");
    return 0;
}
