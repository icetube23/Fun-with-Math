#include "stdafx.h"
#include "LinearAlgebra.hpp"
#include <iostream>
#include <chrono>
#include <cstring>

int main() {
	for (int j = 5; j < 13; j++) {
		la::matrix m(j, j);

		for (size_t i = 0; i < m.entries(); i++) {
			m(i / m.rows(), i % m.columns()) = rand() % m.entries();
		}

		auto begin = std::chrono::high_resolution_clock::now();
		m.det();
		auto end = std::chrono::high_resolution_clock::now();
		int ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
		std::cout << "det(" << j << "x" << j << ") Ms: " << ms << std::endl;
		std::cout << std::endl;
	}
	system("pause");
    return 0;
}
