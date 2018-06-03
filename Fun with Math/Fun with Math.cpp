#include "stdafx.h"
#include "LinearAlgebra.hpp"
#include <iostream>

int main() {
	la::matrix m(10, 10);
	la::vector v(3, 100);

	for (size_t i = 0; i < m.entries(); i++) {
		m(i / m.rows(), i % m.columns()) = rand() % 1000;
	}

	std::cout << m << std::endl;
	std::cout << la::det(m) << std::endl;

	system("pause");
    return 0;
}
