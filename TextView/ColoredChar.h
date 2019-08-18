#pragma once

#include <iostream>
#include <tuple>

#include "Color.h"

// ColoredChar stores the color and character of text. 
// ColoredChar is defined as a template so that it can be
// used with both char and wchars.
// 
// - char stores ascii (8-bit) characters
// - wchar stores unicode (16-bit) characters 
// 
// When constructing a ColoredChar object specify
// the data type as either char or wchar
// ex:
//	 ColoredChar<char> cc;	// <-- Constructs a ColoredChar to be used to display ascii characters
//   ColoredChar<wchar> cc;	// <-- Constructs a ColoredChar to be used to display unicode characters
// 
// No matter the data type used, the color component will always
//  be stored as a char.
//
// ColoredChar does not alter the consoles text color when printing.
// This prevents ColoredChar from being platform dependent.
// It is up to the developer to alter the consoles text color  
// 
template<typename T>
class ColoredChar : private std::pair<char, T>
{
public:
	ColoredChar();
	ColoredChar(T character);
	ColoredChar(char color, T character);
	ColoredChar(const ColoredChar& CC);
	ColoredChar(const ColoredChar&& CC);
	~ColoredChar();

	char& color();
	const char& color() const;

	T& character();
	const T& character() const;

	const ColoredChar<T>& operator=(const ColoredChar<T>& cc);
	const ColoredChar<T>& operator=(const ColoredChar<T>&& cc);
	const ColoredChar<T>& operator=(char character);

	friend std::ostream& operator<<(std::ostream& os, const ColoredChar<T>& cc)
	{
		os << cc.character();

		return os;
	}
	
	friend std::istream& operator>>(std::istream& is, ColoredChar<T>& cc)
	{
		is >> cc.character();

		return is;
	}
};

// Default Constructor
// Initializes the color to 15 (White Foreground, Black Background)
// And Character to '\0'
template<typename T>
inline ColoredChar<T>::ColoredChar() :
	std::pair<char, T>(15, NULL)
{}

template<typename T>
inline ColoredChar<T>::ColoredChar(T character) :
	std::pair<char, T>(15, character)
{
}

template<typename T>
inline ColoredChar<T>::ColoredChar(char color, T character) :
	std::pair<char, T>(color, character)
{}

template<typename T>
inline ColoredChar<T>::ColoredChar(const ColoredChar& CC) :
	std::pair<char, T>(CC.first, CC.second)
{}

template<typename T>
inline ColoredChar<T>::ColoredChar(const ColoredChar&& CC) :
	std::pair<char, T>(CC.first, CC.second)
{}

template<typename T>
inline ColoredChar<T>::~ColoredChar()
{
}

template<typename T>
inline char& ColoredChar<T>::color()
{
	return this->first;
}

template<typename T>
inline const char& ColoredChar<T>::color() const
{
	return this->first;
}

template<typename T>
inline T& ColoredChar<T>::character()
{
	return this->second;
}

template<typename T>
inline const T& ColoredChar<T>::character() const
{
	return this->second;
}

template<typename T>
const ColoredChar<T>& ColoredChar<T>::operator=(const ColoredChar<T>& cc)
{
	this->color() = cc.color();
	this->character() = cc.character();
	return *this;
}

template<typename T>
const ColoredChar<T>& ColoredChar<T>::operator=(const ColoredChar<T>&& cc)
{
	this->color() = cc.color();
	this->character() = cc.character();
	return *this;
}

template<typename T>
inline const ColoredChar<T>& ColoredChar<T>::operator=(char character)
{
	this->character() = character;
	return *this;
}

