#include "stdafx.h"
#include <iostream>
#include "EulersPhi.hpp"
#include "LinearAlgebra.hpp"


int main() {
	la::matrix<double> m(3, 4, 5);

	std::cout << m << std::endl;

 	system("pause");
    return 0;
}
