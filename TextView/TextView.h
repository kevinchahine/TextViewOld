#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

#include "ColoredChar.h"

// class TextView: 
//
//	PURPOSE: stores an 2D array of characters and colors
//		to be printed to the console.
// 
// Elements in the array can be manipulated at any time but the
// size of the array is fixed once constructed.
//
// TextView is implemented as a template so that both char and wchar_t
// can be used.
// char is used for 8-bit ascii characters
// wchar_t is used for 16-bit unicode characters
// When printing to the console, make sure your console is set to use the
//	the characters of your TextView
// 
// When constructing a TextView, determine the datatype of the characters
// as follows:
//  TextView<char> view1;		// <-- TextView of ascii characters
//  TextView<wchar_t> view2;	// <-- TextView of unicode characters
//class Mutation<T>;

template<typename T>
class TextView
{
public:
	TextView(size_t nRows, size_t nCols, const ColoredChar<T>& initializer);
	TextView(size_t nRows, size_t nCols, const ColoredChar<T>&& initializer = ColoredChar<T>());
	TextView(const TextView& view);
	TextView(const TextView&& view);
	~TextView();

	//void apply(Mutation * mutation);

	size_t getNRows() const;
	size_t getNCols() const;

	ColoredChar<T>& at(size_t row, size_t col);
	const ColoredChar<T>& at(size_t row, size_t col) const;

	void printInColorTo(std::ostream& os) const;
	void print(std::ostream& os = std::cout) const;

	friend std::ostream& operator<<(std::ostream& os, const TextView& view) {
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
	// stores the characters to be displayed and their color
	std::vector<ColoredChar<T>> vec;
};

template<typename T>
TextView<T>::TextView(size_t nRows, size_t nCols, const ColoredChar<T>& initializer) :
	nRows(nRows),
	nCols(nCols),
	vec(nRows* nCols, initializer)
{
}

template<typename T>
TextView<T>::TextView(size_t nRows, size_t nCols, const ColoredChar<T>&& initializer) :
	nRows(nRows),
	nCols(nCols),
	vec(nRows* nCols, initializer)
{
}

template<typename T>
TextView<T>::TextView(const TextView& view) :
	nRows(view.nRows),
	nCols(view.nCols),
	vec(view.vec)
{}

template<typename T>
TextView<T>::TextView(const TextView&& view) :
	nRows(view.nRows),
	nCols(view.nCols),
	vec(view.vec)
{}

template<typename T>
TextView<T>::~TextView()
{
}

//template<typename T>
//inline void TextView<T>::apply(Mutation * mutation)
//{
//	std::cout << typeid(*mutation).raw_name() << std::endl;
//	mutation->applyTo(static_cast<TextView<char>>(*this));
//}

template<typename T>
inline size_t TextView<T>::getNRows() const
{
	return nRows;
}

template<typename T>
inline size_t TextView<T>::getNCols() const
{
	return nCols;
}

template<typename T>
ColoredChar<T>& TextView<T>::at(size_t row, size_t col)
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
const ColoredChar<T>& TextView<T>::at(size_t row, size_t col) const
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
void TextView<T>::printInColorTo(std::ostream& os) const
{
	//std::HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	
	//CONSOLE_SCREEN_BUFFER_INFO info;
	//if (!GetConsoleScreenBufferInfo(console, &info)) {
	//	std::cerr << __func__ << " line " << __LINE__ << std::endl;
	//	return false;
	//}
	
	for (size_t row = 0; row < this->nRows; row++) {
		//char startColor = info.wAttributes;
		//char prevColor = startColor;

		for (size_t col = 0; col < this->nCols; col++) {
			os << this->vec[map(row, col)];
		}
		os << std::endl;
	}
	os << std::endl;
}

template<typename T>
void TextView<T>::print(std::ostream& os) const
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
inline size_t TextView<T>::map(size_t row, size_t col) const
{
	return row * this->nCols + col;
}

template<typename T>
inline size_t TextView<T>::getRow(size_t coord) const
{
	return coord / this->nCols;
}

template<typename T>
inline size_t TextView<T>::getCol(size_t coord) const
{
	return coord % this->nCols;
}

