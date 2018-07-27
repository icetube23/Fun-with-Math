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

	la::matrix<double> test = { { 1, 3, 8 },
								{ 4, 7, 9 },
								{ 2, 8, 4 } };

	std::cout << m2 * m1 << std::endl;

 	system("pause");
    return 0;
}
