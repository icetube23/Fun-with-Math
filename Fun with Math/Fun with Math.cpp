// Fun with Math.cpp: Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include "LinearAlgebra.hpp"
#include <iostream>

int main() {
	la::Vector<int> ve(3);
	la::Matrix<int> ma(2, 4);

	for (int i = 0; i < ve.getDimension(); i++) {
		ve[i] = i + 1;
	}

	std::cout << ve.getLength() << std::endl;
	system("pause");
    return 0;
}

