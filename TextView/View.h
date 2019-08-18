#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

template<typename T>
class View
{
public:
	View(size_t nRows, size_t nCols);
	View(const View<T>& view);
	~View();
	
	size_t getNRows() const;
	size_t getNCols() const;

	friend std::ostream& operator<<(std::ostream& os, const View& view) {
		os << '<' << view.getNRows() << ", " << view.getNCols() << "> = {";

		for (auto& cc : view.vec) {
			os << cc << ", ";
		}

		os << "}";

		return os;
	}

protected:
public:
	// Takes the row and column coordinates of what would be a 2D array
	// and maps them to a single value of a 1D array
	// return row * this->nCols + col;
	size_t map(size_t row, size_t col) const;
	// Takes the coordinate of a 1D array and coverts it to the 
	// row coordinate of what would be a 2D array
	size_t getRow(size_t coord) const;
	// Take the coordinate of a 1D array and converts it to the
	// col coordinate of what would be a 2D arr
	size_t getCol(size_t coord) const;

protected:
public:
	// stores the number of rows in the view
	size_t nRows;
	// stores the number of cols in the view
	size_t nCols;
};

template<typename T>
View<T>::View(size_t nRows, size_t nCols) :
	nRows(nRows),
	nCols(nCols)
{
}

template<typename T>
View<T>::View(const View<T>& view) : 
	nRows(view.nRows),
	nCols(view.nCols)
{
}

template<typename T>
View<T>::~View()
{
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
size_t View<T>::getRow(size_t coord) const
{
	return coord / this->nCols;
}

template<typename T>
size_t View<T>::getCol(size_t coord) const
{
	return coord % this->nCols;
}
