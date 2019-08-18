#pragma once

#include <iostream>
#include <iomanip>

#include "TextView.h"
//#include "ASCII_Lines.h"

class LineView : public View<char>
{
public:
	// ====================== CONSTRUCTORS ====================================
	LineView(size_t nRows, size_t nCols, char initializer);
	LineView(const LineView& view);
	LineView(const LineView&& view);
	LineView(const View<char>& view);
	LineView(const View<char>&& view);
	~LineView();

	virtual void print(std::ostream& os = std::cout) const;

};
