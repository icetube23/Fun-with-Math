// Fun with Math.cpp: Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include "LinearAlgebra.hpp"
#include <iostream>
#include <chrono>

#define SIZE 10000

int main() {
	la::Matrix<> m1(2, 2, 1);

	la::Matrix<> m2(2, 2, 3);

	la::Matrix<> m3 = m1 * m2;

	// std::cout << m3.rows() << " " << m3.columns() << std::endl;
	// std::cout << m3 << std::endl;

	la::Vector<> v1(3, 1);
	la::Matrix<> m4(2, 3, 2);
	la::Vector<> v2 = m4 * v1;

	// std::cout << v2.getDimension() << std::endl;
	// for (size_t i = 0; i < v2.getDimension(); i++) {
	//	std::cout << v2[i] << std::endl;
	// }

	la::Matrix<> ma1(SIZE, SIZE, 5);
	la::Matrix<> ma2(SIZE, SIZE, 6);
	std::cout << "Begin multiplication of two " << SIZE << "x" << SIZE << " matrices" << std::endl;
	auto begin = std::chrono::high_resolution_clock::now();
	la::Matrix<> ma3 = ma1 * ma2;
	auto end = std::chrono::high_resolution_clock::now();
	int ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
	std::cout << "Ms passed: " << ms << std::endl;
	system("pause");
    return 0;
}