// Fun with Math.cpp: Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include "LinearAlgebra.hpp"
#include <iostream>

int main() {
	la::Vector<> ve(5);
	ve[1] = 5;
	la::Vector<> ve2(ve);
	std::cout << ve2[1] << std::endl;
	la::Vector<> ve3 = ve + ve2;
	std::cout << ve3[1] << std::endl;
	ve3 = ve;
	std::cout << ve3[1] << std::endl;
	ve = ve2 + ve3;
	std::cout << ve[1] << std::endl;
	ve[2] = 5;
	std::cout << ve.getDimension() << std::endl;
	std::cout << ve.getLength() << std::endl;
	ve2[2] = 4;
	std::cout << ve[2] << std::endl;

	system("pause");
    return 0;
}

