#pragma once

#include <algorithm>

#include "TextView.h"

template<typename T>
class TextViewLayout : public TextView<T>
{
public:
	TextViewLayout(size_t nRows, size_t nCols, const ColoredChar<T>& initializer);
	TextViewLayout(size_t nRows, size_t nCols, const ColoredChar<T>&& initializer = ColoredChar<T>());
	TextViewLayout(const TextViewLayout& view);
	TextViewLayout(const TextViewLayout&& view);
	~TextViewLayout();

	void paste(size_t rowPos, size_t colPos, const TextView<T>& view);
	void wipe(size_t row1, size_t col1, size_t row2, size_t col2);

	void print(std::ostream& os) const;

protected:
	std::vector<const ColoredChar<T> *> coloredCharPtrs;
};

template<typename T>
TextViewLayout<T>::TextViewLayout(size_t nRows, size_t nCols, const ColoredChar<T>& initializer) :
	TextView<T>(nRows, nCols, initializer),
	coloredCharPtrs(nRows * nCols, nullptr)
{
}

template<typename T>
TextViewLayout<T>::TextViewLayout(size_t nRows, size_t nCols, const ColoredChar<T>&& initializer) :
	TextView<T>(nRows, nCols, initializer),
	coloredCharPtrs(nRows* nCols, nullptr)
{
}

template<typename T>
TextViewLayout<T>::TextViewLayout(const TextViewLayout& view) :
	TextViewLayout(static_cast<TextView<T>>(view)),
	coloredCharPtrs(view.coloredCharPtrs)
{
}

template<typename T>
TextViewLayout<T>::TextViewLayout(const TextViewLayout&& view) :
	TextViewLayout(static_cast<TextView<T>>(view)),
	coloredCharPtrs(view.coloredCharPtrs)
{
}

template<typename T>
TextViewLayout<T>::~TextViewLayout()
{
}

template<typename T>
void TextViewLayout<T>::paste(size_t rowPos, size_t colPos, const TextView<T>& view)
{
	for (
		size_t row = 0; 
		row < view.nRows && row + rowPos < this->nRows; 
		row++) {
		for (
			size_t col = 0; 
			col < view.nCols && col + colPos < this->nCols; 
			col++) {
			size_t rowOffset = row + rowPos;
			size_t colOffset = col + colPos;
			size_t layoutIndex = 
				(static_cast<TextView<T>>(*this)).map(rowOffset, colOffset);
			size_t viewIndex = view.map(row, col);

			this->coloredCharPtrs[layoutIndex] = &view.vec[viewIndex];
		}
	}
}

template<typename T>
void TextViewLayout<T>::wipe(size_t row1, size_t col1, size_t row2, size_t col2)
{
	// *this is currently a TextViewLayout.
	// Cast it into a TextView so that we can use its TextView components.
	TextView<T>& view = static_cast<TextView<T>&>(*this);

	// Make sure row1 is less then row2
	if (row1 > row2) {
		std::swap(row1, row2);
	}

	// Make sure row2 is inbounds
	row2 = std::min<size_t>(row2, view.nRows);

	// Make sure col1 is less than col2
	if (col1 > col2) {
		std::swap(col1, col2);
	}

	// Make sure col2 is inbounds
	col2 = std::min<size_t>(col2, view.nCols);

	// scan between [row1, col2] and (row2, col2) and set all the 
	// points to nullptr.
	for (size_t r = row1; r < row2; r++) {
		for (size_t c = col1; c < col2; c++) {
			size_t index = view.map(r, c);

			this->coloredCharPtrs[index] = nullptr;
		}
	}
}

template<typename T>
void TextViewLayout<T>::print(std::ostream& os) const
{
	for (size_t row = 0; row < this->nRows; row++) {
		for (size_t col = 0; col < this->nCols; col++) {
			size_t index = static_cast<const TextView<T>>(*this).map(row, col);
			if (this->coloredCharPtrs[index] == nullptr) {
				os << this->vec[index];
			}
			else {
				os << *(this->coloredCharPtrs[index]);
			}
		}
		os << std::endl;
	}
	os << std::endl;
}
