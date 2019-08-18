#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

template<typename T>
class View
{
public:
	View(size_t nRows, size_t nCols, const T & initializer);
	View(size_t nRows, size_t nCols, const T && initializer);
	View(const View<T>& view);
	View(const View<T>&& view);
	~View();
	
	size_t getNRows() const;
	size_t getNCols() const;

	virtual T & at(size_t row, size_t col);
	virtual const T & at(size_t row, size_t col) const;

	virtual void print(std::ostream& os = std::cout) const;

	friend std::ostream& operator<<(std::ostream& os, const View& view) {
		os << '<' << view.getNRows() << ", " << view.getNCols() << "> = {";

		for (auto& cc : view.vec) {
			os << cc << ", ";
		}

		os << "}";

		return os;
	}

protected:
	// Takes the row and column coordinates of what would be a 2D array
	// and maps them to a single value of a 1D array
	// return row * this->nCols + col;
	size_t map(size_t row, size_t col) const;
	// Takes the coordinate of a 1D array and coverts it to the 
	// row coordinate of what would be a 2D array
	size_t getRowCoord(size_t coord) const;
	// Take the coordinate of a 1D array and converts it to the
	// col coordinate of what would be a 2D arr
	size_t getColCoord(size_t coord) const;

protected:
	// stores the number of rows in the view
	size_t nRows;
	// stores the number of cols in the view
	size_t nCols;
	// stores the characters to be displayed and their color
	std::vector<T> vec;
};

// ========================== CONSTRUCTORS ====================================

template<typename T>
View<T>::View(size_t nRows, size_t nCols, const T & initializer) :
	nRows(nRows),
	nCols(nCols),
	vec(nRows, nCols, initializer)
{
}

template<typename T>
View<T>::View(size_t nRows, size_t nCols, const T && initializer) :
	nRows(nRows),
	nCols(nCols),
	vec(nRows, nCols, initializer)
{
}

template<typename T>
View<T>::View(const View<T>& view) : 
	nRows(view.nRows),
	nCols(view.nCols),
	vec(nRows, nCols, initializer)
{
}

template<typename T>
View<T>::View(const View<T>&& view) :
	nRows(view.nRows),
	nCols(view.nCols),
	vec(nRows, nCols, initializer)
{
}

template<typename T>
View<T>::~View()
{
}

// ========================== ACCESSORS =======================================

template<typename T>
T& View<T>::at(size_t row, size_t col)
{
	// Make sure row and column are in bounds
	if (row >= nRows) {
		std::cerr << __func__ << " row = " << row << " is out of bounds."
			<< " nRows = " << this->nRows << std::endl;
		// Don't throw an exception, 
		// let vector exception handler deal with exceptions
	}
	if (col >= nCols) {
		std::cerr << __func__ << " col = " << col << " is out of bounds."
			<< "nCols = " << this->nCols << std::endl;
		// Don't throw an exception, 
		// let vector exception handler deal with exceptions
	}

	// At this point row and col are guarenteed to be inbounds
	return this->vec.at(this->map(row, col));
}

template<typename T>
const T& View<T>::at(size_t row, size_t col) const
{
	// Make sure row and column are in bounds
	if (row >= nRows) {
		std::cerr << __func__ << " row = " << row << " is out of bounds."
			<< " nRows = " << this->nRows << std::endl;
		// Don't throw an exception, 
		// let vector exception handler deal with exceptions
	}
	if (col >= nCols) {
		std::cerr << __func__ << " col = " << col << " is out of bounds."
			<< "nCols = " << this->nCols << std::endl;
		// Don't throw an exception, 
		// let vector exception handler deal with exceptions
	}

	// At this point row and col are guarenteed to be inbounds
	return this->vec.at(this->map(row, col));
}

template<typename T>
void View<T>::print(std::ostream& os) const
{
	for (size_t row = 0; row < this->nRows; row++) {
		for (size_t col = 0; col < this->nCols; col++) {
			os << this->vec[map(row, col)];
		}
		os << std::endl;
	}
	os << std::endl;
}

template<typename T>
inline size_t View<T>::getNRows() const
{
	return nRows;
}

template<typename T>
inline size_t View<T>::getNCols() const
{
	return nCols;
}

template<typename T>
size_t View<T>::map(size_t row, size_t col) const
{
	return row * this->nCols + col;
}

template<typename T>
size_t View<T>::getRowCoord(size_t coord) const
{
	return coord / this->nCols;
}

template<typename T>
size_t View<T>::getColCoord(size_t coord) const
{
	return coord % this->nCols;
}

