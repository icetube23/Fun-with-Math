#include "stdafx.h"
#include "LinearAlgebra.hpp"
#include <iostream>
#include <chrono>

int main() {
	la::matrix<double> m = { { 1, 2, 3 },
							 { 4, 5, 6 },
							 { 7, 8, 9 } };
	std::cout << m.transpose() << std::endl;
	
	la::vector<double> v = { 1, 2, 3, 4, 5 };
	std::cout << v << std::endl;

	la::matrix<double> m1 = { { 1, 2, 3, 4, 5 },
							  { 1, 2, 3, 4, 5 },
							  { 1, 2, 3, 4, 5 },
							  { 1, 2, 3, 4, 5 } };

	la::matrix<double> m2 = { { 1, 2, 3, 5 },
							  { 1, 2, 3, 5 },
							  { 1, 2, 3, 5 },
							  { 1, 2, 3, 5 },
							  { 1, 2, 3, 5 },
							  { 1, 2, 3, 5 },
							  { 1, 2, 3, 5 } };

	for (size_t i = 50; i < 1000; i += 50) {
		la::matrix<double> mm1(i, i);
		la::matrix<double> mm2(i, i);
		auto begin = std::chrono::steady_clock::now();
		mm2 * mm1;
		auto end = std::chrono::steady_clock::now();
		std::chrono::duration<double, std::milli> ms(end - begin);
		std::cout << "Time passed: " << ms.count() << "ms" << std::endl;
	}
 	system("pause");
    return 0;
}
