// Fun with Math.cpp: Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include "fibonacci.hpp"
#include <windows.h>
#include <iostream>
#include <chrono>
#include <thread>

void fib_it_(int);
void fib_it_help(int, int);
void fib_(int);
void fib_help(int, int);

void fib_parallel() {
	std::thread threads[3];

	threads[0] = std::thread(fib_help, 10, 60);
	Sleep(2500);
	threads[1] = std::thread(fib_it_help, 10, 60);
	Sleep(2500);
	threads[2] = std::thread(fib_, 70);
	Sleep(2500);
	fib_it_(70);

	threads[0].join();
	threads[1].join();
	threads[2].join();

	std::cout << "Done /(0_0)'\ " << std::endl;
}

void fib_it_(int i) {
	auto begin = std::chrono::high_resolution_clock::now();
	std::cout << "Fibonacci(" << i << ") (iterative): " << fib_it(i) << std::flush;
	auto end = std::chrono::high_resolution_clock::now();
	int ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
	std::cout << " Milliseconds passed: " << ms << std::endl;
}

void fib_it_help(int begin, int end) {
	for (int i = begin; i <= end; i += 10) {
		auto begin = std::chrono::high_resolution_clock::now();
		std::cout << "Fibonacci(" << i << ") (iterative): " << fib_it(i) << std::flush;
		auto end = std::chrono::high_resolution_clock::now();
		int ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
		std::cout << " Milliseconds passed: " << ms << std::endl;
	}
}

void fib_(int i) {
	auto begin = std::chrono::high_resolution_clock::now();
	std::cout << "Fibonacci(" << i << ") (recursive): " << fib(i) << std::flush;
	auto end = std::chrono::high_resolution_clock::now();
	int ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
	std::cout << " Milliseconds passed: " << ms << std::endl;
}

void fib_help(int begin, int end) {
	for (int i = begin; i <= end; i += 10) {
		auto begin = std::chrono::high_resolution_clock::now();
		std::cout << "Fibonacci(" << i << ") (recursive): " << fib(i) << std::flush;
		auto end = std::chrono::high_resolution_clock::now();
		int ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
		std::cout << " Milliseconds passed: " << ms << std::endl;
	}
}


int main() {
	//fib_parallel();
	
	for (int i = 10; i <= 80; i += 10) {
		auto begin = std::chrono::high_resolution_clock::now();
		std::cout << "Fibonacci(" << i << ") (iterative): " << fib_it(i) << std::flush;
		auto end = std::chrono::high_resolution_clock::now();
		int ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
		std::cout << " Milliseconds passed: " << ms << std::endl;
	}
	

	system("pause");
    return 0;
}

