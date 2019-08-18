#pragma once

#include "Mutation.h"

//template<typename T>
//class LineMutation : public Mutation<T>
//{
//public:
//	LineMutation();
//	LineMutation(
//		size_t startingRow, 
//		size_t startingCol,
//		size_t lineLength,
//		const Mutation<T> & base = Mutation<T>());
//	LineMutation(const LineMutation<T> & copy);
//	~LineMutation();
//
//	virtual void applyTo(TextView<T>& view) const;
//
//protected:
//	size_t startingRow;
//	size_t startingCol;
//	size_t lineLength;
//};
//
//template<typename T>
//inline LineMutation<T>::LineMutation() :
//	Mutation<T>(),
//	startingRow(0),
//	startingCol(0),
//	lineLength(0)
//{
//}
//
//template<typename T>
//inline LineMutation<T>::LineMutation(
//	size_t startingRow, 
//	size_t startingCol,
//	size_t lineLength,
//	const Mutation<T>& base) :
//	Mutation<T>(base),
//	startingRow(startingRow),
//	startingCol(startingCol),
//	lineLength(lineLength)
//{
//}
//
//template<typename T>
//inline LineMutation<T>::LineMutation(const LineMutation<T>& copy) :
//	Mutation<T>(static_cast<Mutation<T>>(copy)),
//	startingRow(copy.startingRow),
//	startingCol(copy.startingCol),
//	lineLength(copy.lineLength)
//{
//}
//
//template<typename T>
//inline LineMutation<T>::~LineMutation()
//{
//}
//
//template<typename T>
//void LineMutation<T>::applyTo(TextView<T>& view) const
//{
//	std::cout << "ERROR: calling " << __func__ << " line " << __LINE__ << '\n';
//}
//
