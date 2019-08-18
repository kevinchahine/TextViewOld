#pragma once

#include "LineMutation.h"
//
//template <typename T>
//class HorizontalLineMutation : public LineMutation<T>
//{
//public:
//	HorizontalLineMutation();
//	HorizontalLineMutation(const LineMutation<T> && base);
//	~HorizontalLineMutation();
//
//	virtual void applyTo(TextView<T>& view) const {
//		size_t endingCol = startingCol + lineLength;
//
//		for (size_t col = startingCol; col < endingCol; col++) {
//			view.at(startingRow, col) = '-';
//		}
//	}
//};
//
//template<typename T>
//inline HorizontalLineMutation<T>::HorizontalLineMutation() 
//{
//}
//
//template<typename T>
//inline HorizontalLineMutation<T>::HorizontalLineMutation(
//	const LineMutation<T>&& base) :
//	LineMutation<T>(base)
//{
//}
//
//template<typename T>
//inline HorizontalLineMutation<T>::~HorizontalLineMutation()
//{
//}
//
////template<typename T>
////void HorizontalLineMutation<T>::applyTo(TextView<T> & textView) const
////{
////	size_t endingCol = startingCol + lineLength;
////
////	for (size_t col = startingCol; col < endingCol; col++) {
////		textView.at(startingRow, col) = '-';
////	}
////}
