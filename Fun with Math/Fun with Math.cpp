#include "stdafx.h"
#include <iostream>
#include "reg.hpp"
#include "EulersPhi.hpp"
#include "BigInteger.hpp"

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
	BigInteger i1(31);
	BigInteger i2(-32);
	BigInteger i3(32);
	BigInteger i4(256);
	BigInteger i5(127);
	BigInteger i6(-128);
	BigInteger i7(128);
	BigInteger i8((uint64_t)-1);

 	system("pause");
    return 0;
}
