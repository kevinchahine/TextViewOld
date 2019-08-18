#pragma once

#include "RectangleMutation.h"

template<typename T>
class RectangleLineMutation : public RectangleMutation<T>
{
public:
	RectangleLineMutation();
	RectangleLineMutation(const RectangleMutation<T>& base);
	~RectangleLineMutation();
};

template<typename T>
inline RectangleLineMutation<T>::RectangleLineMutation()
{
}

template<typename T>
inline RectangleLineMutation<T>::RectangleLineMutation(
	const RectangleMutation<T>& base) :
	RectangleMutation<T>(base)
{
}

template<typename T>
inline RectangleLineMutation<T>::~RectangleLineMutation()
{
}
