#include "stdafx.h"
#include <iostream>
#include "EulersPhi.hpp"

double sine(double x) noexcept {
	static const double pi = 3.1415926535;
	uint64_t f = 1;
	double res = 0;
	double diff = 1;

	while (x < -pi || x > pi) {
		if (x > pi) {
			x -= 2 * pi;
		}
		else {
			x += 2 * pi;
		}
	}

	for (size_t n = 0; std::abs(diff) > 0.000001; n++) {
		if (n != 0) { f *= 2 * n * (2 * n + 1); }
		if (f > 0) { diff = pow(-1, n) * pow(x, 2 * n + 1) / f; }
		std::cout << diff << std::endl;
		res += diff;
	}
	return res;
}

int main() {
	// la::matrix<double> m = { { 1, 2, 3 },
	// 						 { 4, 5, 6 },
	// 						 { 7, 8, 9 } };
	// std::cout << m.transpose() << std::endl;
	
	// la::vector<double> v = { 1, 2, 3, 4, 5 };
	// std::cout << v << std::endl;

	// la::matrix<double> m1 = { { 1, 2, 3, 4, 5 },
	// 						  { 1, 2, 3, 4, 5 },
	// 						  { 1, 2, 3, 4, 5 },
	// 						  { 1, 2, 3, 4, 5 } };

	// la::matrix<double> m2 = { { 1, 2, 3, 5 },
	// 						  { 1, 2, 3, 5 },
	// 						  { 1, 2, 3, 5 },
	// 						  { 1, 2, 3, 5 },
	// 						  { 1, 2, 3, 5 },
	// 						  { 1, 2, 3, 5 },
	// 						  { 1, 2, 3, 5 } };

	// auto random = std::bind(std::uniform_int_distribution<int32_t>(1, 7), std::default_random_engine());
	// // la::matrix<double> test(4, 4);

	// // for (size_t i = 0; i < test.rows(); i++) {
	// // 	for (size_t j = 0; j < test.columns(); j++) {
	// // 		test(i, j) = random();
	// // 	}
	// // }

	// la::matrix<double> test(2, 2);
	// test(1, 0) = 1; test(0, 1) = 1;
	// std::cout << test << std::endl;
	// std::cout << test.det() << std::endl;

	// la::matrix<double> gauss = test.gauss();
	// // std::cout << gauss << std::endl;

	// double dete = 1;
	// for (size_t i = 0; i < gauss.columns(); i++) {
	// 	dete *= gauss(i, i);
	// }
	// std::cout << dete << std::endl;

	// std::cout << std::boolalpha;
	// std::cout << (la::complex(0.2, 0.6) == la::complex(0.2, 0.6)) << std::endl;
	// std::cout << (la::complex(0.6, -0.2) == la::complex(0.6, -0.2)) << std::endl;

	// la::matrix<double> m = { { 2, 0, 6, 0, 4 },
	//						 { 5, 3, 2, 2, 7 }, 
	//						 { 2, 5, 7, 5, 5 },
	//                         { 2, 0, 9, 2, 7 },
	//						 { 0, 0, 2, 8, 9 } };
	// std::cout << m.gauss() << std::endl;

	for (size_t i = 0; i < 10; i++) {
		for (size_t j = 0; j < 10; j++) {
			std::cout << phi(10 * i + j);
			if (j != 9) { std::cout << ", "; }
		}
		std::cout << std::endl;
	}

 	system("pause");
    return 0;
}
