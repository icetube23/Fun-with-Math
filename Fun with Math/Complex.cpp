#include "stdafx.h"
#include "Complex.hpp"

namespace la::fields {
	Complex::Complex(double re) noexcept
		: m_real(re)
	{}

	Complex::Complex(double re, double im) noexcept
		: m_real(re), m_img(im)
	{}

	double Complex::real() const {
		return m_real;
	}

	double Complex::img() const {
		return m_img;
	}

	double Complex::abs() const {
		return std::sqrt(m_real * m_real + m_img * m_img);
	}

	Complex Complex::conjugate() const {
		return Complex(m_real, -m_img);
	}

	Complex Complex::operator*(double other) const {
		return Complex(m_real * other, m_img * other);
	}

	Complex Complex::operator*(const Complex &other) const {
		return Complex((m_real * other.m_real - m_img * other.m_img), (m_real * other.m_img + m_img * other.m_real));
	}

	Complex Complex::operator/(double other) const {
		return Complex(m_real / other, m_img / other);
	}

	Complex Complex::operator/(const Complex &other) const {
		Complex conj = other.conjugate();
		return (*this * conj) / (other * conj).m_real;
	}

	Complex Complex::operator+(double other) const {
		return Complex(m_real + other, m_img);
	}

	Complex Complex::operator+(const Complex &other) const {
		return Complex(m_real + other.m_real, m_img + other.m_img);
	}

	Complex Complex::operator-(double other) const {
		return Complex(m_real - other, m_img);
	}

	Complex Complex::operator-(const Complex &other) const {
		return Complex(m_real - other.m_real, m_img - other.m_img);
	}

	Complex& Complex::operator*=(double other) {
		*this = *this * other;
		return *this;
	}

	Complex& Complex::operator*=(const Complex &other) {
		*this = *this * other;
		return *this;
	}

	Complex& Complex::operator/=(double other) {
		*this = *this / other;
		return *this;
	}

	Complex& Complex::operator/=(const Complex &other) {
		*this = *this / other;
		return *this;
	}

	Complex& Complex::operator+=(double other) {
		*this = *this + other;
		return *this;
	}

	Complex& Complex::operator+=(const Complex &other) {
		*this = *this + other;
		return *this;
	}

	Complex& Complex::operator-=(double other) {
		*this = *this - other;
		return *this;
	}

	Complex& Complex::operator-=(const Complex &other) {
		*this = *this - other;
		return *this;
	}

	Complex& Complex::operator=(const Complex &other) {
		m_real = other.m_real;
		m_img = other.m_img;
		return *this;
	}

	Complex& Complex::operator=(Complex &&other) {
		m_real = other.m_real;
		m_img = other.m_img;
		return *this;
	}

	bool Complex::operator==(double other) const {
		return m_real == other && m_img == 0;
	}

	bool Complex::operator==(const Complex &other) const {
		return m_real == other.m_real && m_img == other.m_img;
	}

	bool Complex::operator!=(double other) const {
		return m_real != other || m_img != 0;
	}

	bool Complex::operator!=(const Complex &other) const {
		return m_real != other.m_real || m_img != other.m_img;
	}

	bool Complex::operator<(double other) const {
		return abs() < other;
	}

	bool Complex::operator<(const Complex &other) const {
		return abs() < other.abs();
	}

	bool Complex::operator>(double other) const {
		return abs() > other;
	}

	bool Complex::operator>(const Complex &other) const {
		return abs() > other.abs();
	}

	bool Complex::operator<=(double other) const {
		return abs() <= other;
	}

	bool Complex::operator<=(const Complex &other) const {
		return abs() <= other.abs();
	}

	bool Complex::operator>=(double other) const {
		return abs() >= other;
	}

	bool Complex::operator>=(const Complex &other) const {
		return abs() >= other.abs();
	}

	Complex operator*(double x, const Complex &z) {
		return Complex(x * z.real(), x * z.img());
	}

	Complex operator/(double x, const Complex &z) {
		return Complex(x, 0) / z;
	}

	Complex operator+(double x, const Complex &z) {
		return Complex(x + z.real(), z.img());
	}

	Complex operator-(double x, const Complex &z) {
		return Complex(x - z.real(), -z.img());
	}

	std::ostream & operator<<(std::ostream &os, const Complex &z) {
		os << z.real() << (z.img() < 0 ? " - " : " + ") << std::abs(z.img()) << "i";
		return os;
	}
}