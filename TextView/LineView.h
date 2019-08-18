#pragma once

#include <iostream>
#include <iomanip>

#include "TextView.h"

template <typename T>
class LineView : public TextView<T>
{
public:
	LineView(
		size_t nRows, 
		size_t nCols, 
		const ColoredChar<T>& initializer);

	LineView(
		size_t nRows, 
		size_t nCols, 
		const ColoredChar<T>&& initializer = ColoredChar<T>());

	LineView(const LineView& view);
	
	LineView(const LineView&& view);
	
	LineView(const TextView<T>& view);
	
	LineView(const TextView<T>&& view);
	
	~LineView();
};

template<typename T>
LineView<T>::LineView(
	size_t nRows, 
	size_t nCols, 
	const ColoredChar<T>& initializer) :
	View<T>(nRows, nCols) {}

template<typename T>
LineView<T>::LineView(
	size_t nRows,
	size_t nCols,
	const ColoredChar<T>&& initializer) :
	TextView<T>(nRows, nCols, initializer) {}

template<typename T>
inline LineView<T>::~LineView()
{
}


