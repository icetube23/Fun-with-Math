// Fun with Math.cpp: Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include "LinearAlgebra.hpp"
#include <iostream>

int main() {
	la::Matrix<> m1(1, 2);
	for (size_t i = 0; i < m1.rows(); i++) {
		for (size_t j = 0; j < m1.columns(); j++) {
			m1(i, j) = 1;
		}
	}
	la::Matrix<> m2(2, 3);
	for (size_t i = 0; i < m2.rows(); i++) {
		for (size_t j = 0; j < m2.columns(); j++) {
			m2(i, j) = 1;
		}
	}

	la::Matrix<> m3 = m1 * m2;

	std::cout << m3.rows() << " " << m3.columns() << std::endl;
	for (size_t i = 0; i < m3.rows(); i++) {
		for (size_t j = 0; j < m3.columns(); j++) {
			std::cout << m3(i, j) << " " << std::flush;
		}
	}

	system("pause");
    return 0;
}

