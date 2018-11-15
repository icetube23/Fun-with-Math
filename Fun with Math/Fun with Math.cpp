#include "stdafx.h"
#include <iostream>
#include "reg.hpp"
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
	auto delta =
		[](size_t state, wchar_t a) {
		switch (state) {
		case 0:
			return size_t(a == '1');
		case 1:
			return size_t(a == '0');
		}
	};

	dea l_even(std::unordered_set<wchar_t>{ '0', '1' }, std::unordered_set<size_t>{ 0, 1 }, 0, delta, std::unordered_set<size_t>{ 0 });

	std::cout << std::boolalpha;
	std::cout << l_even(L"0") << std::endl;
	std::cout << l_even(L"1") << std::endl;
	std::cout << l_even(L"11") << std::endl;
	std::cout << l_even(L"111") << std::endl;
	std::cout << l_even(L"10") << std::endl;
	std::cout << l_even(L"110") << std::endl;
	std::cout << l_even(L"1110") << std::endl;
	std::cout << l_even(L"01") << std::endl;
	std::cout << l_even(L"011") << std::endl;
	std::cout << l_even(L"0111") << std::endl;
	std::cout << l_even(L"11a") << std::endl;

 	system("pause");
    return 0;
}
