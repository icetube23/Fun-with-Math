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

	la::Vector<> ve(2, 1);
	la::Vector<> ve2(ve);
	
	std::cout << (ve == ve2) << std::endl;

	system("pause");
    return 0;
}

