#pragma once

// Colors are 8-bit unsigned int (unsigned char) values
// The 4 MSBs represent the Background color
// The 4 LSBs represent the Foreground color
// bbbbffff
//
// Given a 8-bit color value, the foreground and background values
// can be determined using these operations:
//  bg is the background color value as an integer
//  fg is the foreground color value as an integer
//  color is the entire color value (fg and bg) as an integer
//	
//  bg = (color >> 4) & 0x0f;
//  fg = color & 0x0f;
//  color = (bg << 4) | fg;
//
//  Use the inline functions in this Color namespace for these 
//	operations:
//		Color::parseFG();
//		Color::parseBG();
//		Color::mergeColor();
//
// Note: 0x0f = 0b00001111 = 15
namespace Color {
	const unsigned char BLACK = 0;
	const unsigned char BLUE = 1;
	const unsigned char GREEN = 2;
	const unsigned char CYAN = 3;
	const unsigned char RED = 4;
	const unsigned char PURPLE = 5;
	const unsigned char YELLOW = 6;
	const unsigned char LIGHTGREY = 7;
	const unsigned char GREY = 8;
	const unsigned char LIGHTBLUE = 9;
	const unsigned char LIGHTGREEN = 10;
	const unsigned char LIGHTCYAN = 11;
	const unsigned char LIGHTRED = 12;
	const unsigned char LIGHTPURPLE = 13;
	const unsigned char LIGHTYELLOW = 14;
	const unsigned char WHITE = 15;

	// calculates and returns the forground color component of the input parameter
	inline unsigned char parseFG(unsigned char color)
	{
		return (color >> 4) & 0x0f;
	}

	// calculates and returns the background color component of the input parameter
	inline unsigned char parseBG(unsigned char color)
	{
		return color & 0x0f;
	}

	// calculates and returns the concatination of the foreground and background 
	// color components of the input parameters
	inline unsigned char mergeColor(unsigned char fg, unsigned char bg)
	{
		return (bg << 4) | fg;
	}

	//std::ostream & 
};


