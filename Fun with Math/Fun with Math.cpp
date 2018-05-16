// Fun with Math.cpp: Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include "LinearAlgebra.hpp"
#include <iostream>

int main() {
	la::Vector<float> ve(3);
	const la::Matrix<> ma(2, 4);

	for (int i = 0; i < ve.getDimension(); i++) {
		ve[i] = i + 1;
	}

	ve.normalize();

	std::cout << ve[0] << " " << ve[1] << " " << ve[2] << std::endl;
	std::cout << ve.getLength() << std::endl;
	std::cout << ma(2, 4) << std::endl;
	system("pause");
    return 0;
}

