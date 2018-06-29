#include "stdafx.h"
#include "LinearAlgebra.hpp"
#include <iostream>
#include <chrono>

int main() {
	la::matrix<double> m = { {  1,  2,  3,  4,  5 },
							 {  6,  7,  8,  9, 10 },
							 { 11, 12, 13, 14, 15 } };
	std::cout << m.transpose() << std::endl;
	
	la::vector<double> v = { 1, 2, 3, 4, 5 };
	std::cout << v << std::endl;

	system("pause");
    return 0;
}
