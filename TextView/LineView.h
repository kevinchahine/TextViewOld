#pragma once

#include <iostream>
#include <iomanip>

#include "TextView.h"

template <typename T>
class LineView : public TextView<T>
{
public:
	LineView();
	LineView(const LineView& view);
	LineView(const LineView&& view);
	LineView(const TextView<T>& view);
	LineView(const TextView<T>&& view);
	~LineView();
};

template<typename T>
LineView<T>::LineView() {}

template<typename T>
LineView<T>::LineView(const LineView& view) :

{
}

template<typename T>
LineView<T>::LineView(const LineView&& view)
{
}

template<typename T>
LineView<T>::LineView(const TextView<T>& view)
{
}

template<typename T>
LineView<T>::LineView(const TextView<T>&& view)
{
}

template<typename T>
LineView<T>::~LineView()
{
}

