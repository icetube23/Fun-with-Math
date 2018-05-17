#pragma once
// #include "Vector.hpp"

namespace la {
	template<typename T = double>
	class Matrix {
	private:
		T * mEntries;
		size_t mRows;
		size_t mCols;

	public:
		// Constructors
		Matrix(size_t, size_t, T = 0);
		Matrix(const Matrix &);
		Matrix(Matrix &&);

		// Destructor
		~Matrix();

		// getter for the dimensions
		size_t rows() const;
		size_t columns() const;
		size_t entries() const;

		// Overloaded operators
		T operator()(int, int) const;
		T& operator()(int, int);
		Matrix operator*(const Matrix &) const;
		// Vector operator*(const Vector<T> &) const;
		Matrix operator*(const double &) const;
		Matrix operator/(const double &) const;
		Matrix operator+(const Matrix &) const;
		Matrix operator-(const Matrix &) const;
		Matrix& operator*=(const Matrix &);
		Matrix& operator*=(const double &);
		Matrix& operator/=(const double &);
		Matrix& operator+=(const Matrix &);
		Matrix& operator-=(const Matrix &);
		Matrix& operator=(const Matrix &);
		Matrix& operator=(Matrix &&);
		bool operator==(const Matrix &) const;
		bool operator!=(const Matrix &) const;
	};

	template<typename T>
	Matrix<T>::Matrix(size_t rows, size_t cols, T defVal)
		: mCols(cols), mRows(rows) {
		mEntries = new T[rows * cols];
		if (defVal != 0) {
			size_t dim = rows * cols;
			for (size_t i = 0; i < dim; i++) { mEntries[i] = defVal; }
		}
		else {
			memset(mEntries, 0, rows * cols * sizeof(T));
		}
	}

	template<typename T>
	Matrix<T>::Matrix(const Matrix<T> &other) {
		mRows = other.mRows;
		mCols = other.mCols;
		mEntries = new T[other.entries()];
		memcpy(mEntries, other.mEntries, other.entries() * sizeof(T));
	}

	template<typename T>
	Matrix<T>::Matrix(Matrix<T> &&other) {
		mRows = other.mRows;
		mCols = other.mCols;
		mEntries = other.mEntries;
		other.mEntries = nullptr;
	}

	template<typename T>
	Matrix<T>::~Matrix() {
		delete[] mEntries;
	}

	template<typename T>
	size_t Matrix<T>::rows() const {
		return mRows;
	}

	template<typename T>
	size_t Matrix<T>::columns() const {
		return mCols;
	}

	template<typename T>
	size_t Matrix<T>::entries() const {
		return mRows * mCols;
	}

	template<typename T>
	T Matrix<T>::operator()(int i, int j) const {
		if (i >= mRows || i < 0 || j >= mCols || j < 0) {
			throw std::out_of_range("Exceeded matrix range.");
		}
		return mEntries[i * mCols + j];
	}

	template<typename T>
	T& Matrix<T>::operator()(int i, int j) {
		if (i >= mRows || i < 0 || j >= mCols || j < 0) {
			throw std::out_of_range("Exceeded matrix range.");
		}
		return mEntries[i * mCols + j];
	}

	template<typename T>
	Matrix<T> Matrix<T>::operator*(const Matrix<T> &other) const {
		if (mCols != other.mRows) {
			throw std::runtime_error("Can not multiply by a matrix which rows does not \
				                      match the columns of the original matrix.");
		}

		Matrix<T> m(mRows, other.mCols);
		// Insert multiplication \(*-*)/
		return m;
	}

	/*
	template<typename T>
	Vector<T> Matrix<T>::operator*(const Vector<T> &other) const {
		if (mCols != other.mDimension) {
			throw std::runtime_error("Can not multiply by a vector which dimension does \
									  not match the columns of the matrix.");
		}

		Vector<T> v(mRows);
		v.mMatrix = *this * other.mMatrix;
		return v;
	}
	*/

	template<typename T>
	Matrix<T> Matrix<T>::operator*(const double &other) const {
		Matrix<T> m(mRows, mCols);
		for (size_t i = 0; i < this->entries(); i++) {
			m.mEntries[i] = mEntries[i] * other;
		}
		return m;
	}

	template<typename T>
	Matrix<T> Matrix<T>::operator/(const double &other) const {
		Matrix<T> m(mRows, mCols);
		for (size_t i = 0; i < this->entries(); i++) {
			m.mEntries[i] = mEntries[i] / other;
		}
		return m;
	}

	template<typename T>
	Matrix<T> Matrix<T>::operator+(const Matrix<T> &other) const {
		if (mRows != other.mRows || mCols != other.mCols) {
			throw std::runtime_error("Dimensions of matrices can not differ from each other.");
		}

		Matrix<T> m(mRows, mCols);
		for (size_t i = 0; i < this->entries(); i++) {
			m.mEntries[i] = mEntries[i] + other.mEntries[i];
		}
		return m;
	}

	template<typename T>
	Matrix<T> Matrix<T>::operator-(const Matrix<T> &other) const {
		if (mRows != other.mRows || mCols != other.mCols) {
			throw std::runtime_error("Dimensions of matrices can not differ from each other.");
		}

		Matrix<T> m(mRows, mCols);
		for (size_t i = 0; i < this->entries(); i++) {
			m.mEntries[i] = mEntries[i] - other.mEntries[i];
		}
		return m;
	}

	template<typename T>
	Matrix<T>& Matrix<T>::operator*=(const Matrix<T> &other) {
		*this = *this * other;
		return *this;
	}

	template<typename T>
	Matrix<T>& Matrix<T>::operator*=(const double &other) {
		*this = *this * other;
		return *this;
	}

	template<typename T>
	Matrix<T>& Matrix<T>::operator/=(const double &other) {
		*this = *this / other;
		return *this;
	}

	template<typename T>
	Matrix<T>& Matrix<T>::operator+=(const Matrix<T> &other) {
		*this = *this + other;
		return *this;
	}

	template<typename T>
	Matrix<T>& Matrix<T>::operator-=(const Matrix<T> &other) {
		*this = *this - other;
		return *this;
	}

	template<typename T>
	Matrix<T>& Matrix<T>::operator=(const Matrix<T> &other) {
		if (this != &other) {
			if (this->entries() != other.entries()) {
				delete[] mEntries;
				mEntries = new T[other.entries()];
			}
			mRows = other.mRows;
			mCols = other.mCols;
			memcpy(mEntries, other.mEntries, other.entries() * sizeof(T));
		}
		return *this;
	}

	template<typename T>
	Matrix<T>& Matrix<T>::operator=(Matrix<T> &&other) {
		if (this != &other) {
			delete[] mEntries;
			mEntries = other.mEntries;
			other.mEntries = nullptr;
			mRows = other.mRows;
			mCols = other.mCols;
		}
		return *this;
	}

	template<typename T>
	bool Matrix<T>::operator==(const Matrix &other) const {
		if (mRows != other.mRows || mCols != other.mCols) { return false; }
		for (size_t i = 0; i < other.entries(); i++) {
			if (mEntries[i] != other.mEntries[i]) {
				return false;
			}
		}
		return true;
	}

	template<typename T>
	bool Matrix<T>::operator!=(const Matrix &other) const {
		if (*this == other) { return false; }
		return true;
	}
}
