// Fun with Math.cpp: Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include "LinearAlgebra.hpp"
#include <iostream>

int main() {
	la::Matrix<> m1(2, 2, 1);

	la::Matrix<> m2(2, 2, 3);


	la::Matrix<> m3 = m1 * m2;

	std::cout << m3.rows() << " " << m3.columns() << std::endl;
	std::cout << m3 << std::endl;

	system("pause");
    return 0;
}

