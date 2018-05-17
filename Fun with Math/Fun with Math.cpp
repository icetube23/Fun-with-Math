// Fun with Math.cpp: Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include "LinearAlgebra.hpp"
#include <iostream>

int main() {
	la::Matrix<> m1(2, 4);
	const la::Matrix<> m2(2, 4);
	la::Matrix<> m3(2, 3, 1);
	m1 += m2;
	std::cout << m3(1, 1) << std::endl;
	m3 *= 5;
	std::cout << m3(1, 1) << std::endl;
	m3 /= 3;
	std::cout << m3(1, 1) << std::endl;
	la::Vector<> ve(2, 1);
	la::Vector<> ve2(ve);
	std::cout << ve[0] << std::endl;
	ve *= 5;
	std::cout << ve[0] << std::endl;

	ve /= 3;

	std::cout << ve[0] << std::endl;
	
	std::cout << (ve == ve2) << std::endl;

	system("pause");
    return 0;
}

