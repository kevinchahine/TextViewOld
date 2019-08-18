cmake_minimum_required(VERSION 3.15)

project(TextViewDriver LANGUAGES C CXX)

add_subdirectory(TextView)

set(Header_Files 
	"Test_TextView.h"
	"Test_ColoredChar.h"
	"Test_LineView.h"
	"Test_Mutation.h"
	"Test_TextView.h"
	"Test_TextViewLayout.h"
	)

set(Source_Files 
	"Test_TextView.cpp"
	"Test_ColoredChar.cpp"
	"Test_LineView.cpp"
	"Test_Mutation.cpp"
	"Test_TextView.cpp"
	"Test_TextViewLayout.cpp"
	)

add_executable(
    TextViewDriver 
    Source.cpp 
    ${Header_Files} 
    ${Source_Files})

target_link_libraries(TextView)
