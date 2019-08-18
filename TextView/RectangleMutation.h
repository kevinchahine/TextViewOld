#pragma once

#include <algorithm>

#include "Mutation.h"

template<typename T>
class Mutation;

template<typename T>
class RectangleMutation : public Mutation<T>
{
public:
	RectangleMutation();
	RectangleMutation(size_t row1, size_t col1, size_t row2, size_t col2);
	RectangleMutation(const RectangleMutation & mutation);
	~RectangleMutation();

	virtual void applyTo(TextView<T>& textViewPtr) const;

protected:
	size_t row1;
	size_t col1;
	size_t row2;
	size_t col2;
};

template<typename T>
RectangleMutation<T>::RectangleMutation() :
	row1(0),
	col1(0),
	row2(0),
	col2(0)
{
}

template<typename T>
RectangleMutation<T>::RectangleMutation(
	size_t row1, 
	size_t col1, 
	size_t row2, 
	size_t col2) :
	row1(std::min(row1, row2)),	// makes sure row1 is not below row2
	col1(std::min(col1, col2)),	// makes sure col1 is not right of col2
	row2(std::max(row1, row2)),	// makes sure row2 is not above row1
	col2(std::max(col1, col2))	// makes sure col2 is not left of col1
{
}

template<typename T>
RectangleMutation<T>::RectangleMutation(
	const RectangleMutation<T>& mutation) :
	row1(mutation.row1),
	col1(mutation.col1),
	row2(mutation.row2),
	col2(mutation.col2)
{
}

template<typename T>
RectangleMutation<T>::~RectangleMutation()
{
}

template<typename T>
void RectangleMutation<T>::applyTo(TextView<T>& textViewPtr) const
{
	// Draw lines on top and bottom
	for (size_t c = col1; c < col2; c++) {
		textViewPtr.at(row1, c) = '-';
		textViewPtr.at(row2, c) = '-';
	}

	// Draw lines on left and right
	for (size_t r = row1; r < row2; r++) {
		textViewPtr.at(r, col1) = '|';
		textViewPtr.at(r, col2) = '|';
	}

	// Draw corners
	textViewPtr.at(row1, col1) = '+';			// Top Left
	textViewPtr.at(row1, col2) = '+';		// Top Right
	textViewPtr.at(row2, col1) = '+';		// Bottom Left
	textViewPtr.at(row2, col2) = '+';	// Bottom Right
}
