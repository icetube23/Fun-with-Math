// Fun with Math.cpp: Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include "LinearAlgebra.hpp"
#include <iostream>

int main() {
	la::Matrix<> m1(2, 4);

	std::cout << "Gleich kommt copy:" << std::endl;
	la::Matrix<> m2(m1);

	std::cout << "Gleich kommt move:" << std::endl;
	la::Matrix<> m3 = m1 + m2;

	std::cout << "Gleich kommt assignment:" << std::endl;
	m3 = m1;

	std::cout << "Gleich kommt move assignment:" << std::endl;
	m1 = m2 + m3;

	system("pause");
    return 0;
}

