#include "stdafx.h"
#include "LinearAlgebra.hpp"
#include <iostream>

int main() {
	la::matrix m(10, 10);
	la::vector v(3, 100);

	for (size_t i = 0; i < m.entries(); i++) {
		m(i / m.rows(), i % m.columns()) = i + 1;
	}

	m = la::matrix::IdentityMatrix(10);

	la::matrix ri = la::matrix::ElementaryMatrix(10, 2, 8, 5);
	la::matrix rj = la::matrix::ElementaryMatrix(10, 5, 2, 3);
	m = ri * m;
	m *= rj;
	m *= 2;
	std::cout << m << std::endl;
	std::cout << m.det() << std::endl;

	system("pause");
    return 0;
}
