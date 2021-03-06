#include "stdafx.h"
#include <iostream>
#include "Primes.hpp"
#include "EulersPhi.hpp"
#include "LinearAlgebra.hpp"


int main() {
	la::matrix<double> m = { { 1, 2, 3 },
							 { 4, 5, 6 }, 
	                         { 7, 8, 8 } };
	la::vector<double> v = { { 1, 2, 3 } };
	la::matrix<la::complex> mc = { { la::complex(1, 2), la::complex(1, 0),la::complex(2, 2) },
								   { la::complex(1, 0), la::complex(2, 3),la::complex(0, 0) }, 
								   { la::complex(3, 2), la::complex(-1, 0),la::complex(2, 4) } 
								 };

	std::cout << m * m.invert() << std::endl;
	std::cout << std::endl;
	std::cout << v * m << std::endl;
	std::cout << mc << std::endl;
	std::cout << mc.determinant() << std::endl;
	std::cout << mc.gauss() << std::endl;
	std::cout << mc.gauss_jordan() << std::endl;
	std::cout << mc.invert() << std::endl;
	std::cout << mc * mc.invert() << std::endl;
	std::cout << la::vector<double>({ { 2, 3 } }).orthogonal(la::vector<double>({ { -3, 2 } })) << std::endl;

 	system("pause");
    return 0;
}
