#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

#include "View.h"

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
class TextView : public View<ColoredChar<T>>
{
public:
	TextView(size_t nRows, size_t nCols, const ColoredChar<T>& initializer);
	TextView(size_t nRows, size_t nCols, const ColoredChar<T>&& initializer = ColoredChar<T>());
	TextView(const TextView& view);
	TextView(const TextView&& view);
	~TextView();

	//void apply(Mutation * mutation);

	virtual void printInColorTo(std::ostream& os) const;
	
	friend std::ostream& operator<<(std::ostream& os, const TextView& view) {
		os << '<' << view.getNRows() << ", " << view.getNCols() << "> = {";

		for (auto& cc : view.vec) {
			os << cc << ", ";
		}
		
		os << "}";

		return os;
	}

};

// ========================== CONSTRUCTORS ====================================
//
//template<typename T>
//TextView<T>::TextView(
//	size_t nRows, 
//	size_t nCols, 
//	const ColoredChar<T>& initializer) :
//	View<ColoredChar<T>>(nRows, nCols, initializer)
//{
//}
//
//template<typename T>
//TextView<T>::TextView(size_t nRows, size_t nCols, const ColoredChar<T>&& initializer) :
//	View<ColoredChar<T>>(nRows, nCols, initializer)
//{
//}
//
//template<typename T>
//TextView<T>::TextView(const TextView& view) :
//	View<ColoredChar<T>>(view.nRows, view.nCols, view.vec)
//{}
//
//template<typename T>
//TextView<ColoredChar<T>>::TextView(const TextView&& view) :
//	View<ColoredChar<T>>(view.nRows, view.nCols, view.vec)
//{}
//
//template<typename T>
//TextView<ColoredChar<T>>::~TextView()
//{
//}
//
//// ========================== PRINT ===========================================
//
//template<typename T>
//void TextView<ColoredChar<T>>::printInColorTo(std::ostream& os) const
//{
//	//std::HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
//	
//	//CONSOLE_SCREEN_BUFFER_INFO info;
//	//if (!GetConsoleScreenBufferInfo(console, &info)) {
//	//	std::cerr << __func__ << " line " << __LINE__ << std::endl;
//	//	return false;
//	//}
//	
//	for (size_t row = 0; row < this->nRows; row++) {
//		//char startColor = info.wAttributes;
//		//char prevColor = startColor;
//
//		for (size_t col = 0; col < this->nCols; col++) {
//			os << this->vec[map(row, col)];
//		}
//		os << std::endl;
//	}
//	os << std::endl;
//}

