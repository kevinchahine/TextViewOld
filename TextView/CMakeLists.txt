# --- TextView ---

add_library(
	TextView
    
	# Color
	Color.h
	Color.cpp

	ColoredChar.h
	ColoredChar.cpp
	
    # Mutations
	Mutation.h
	Mutation.cpp
	
    RectangleMutation.h
	RectangleMutation.cpp
	RectangleLineMutation.h
	RectangleLineMutation.cpp
	LineMutation.h
	LineMutation.cpp
	HorizontalLineMutation.h	
	HorizontalLineMutation.cpp
	
    # Views
	View.h
	View.cpp
	TextView.h
	TextView.cpp
	TextViewLayout.h
	TextViewLayout.cpp
	LineView.h
	LineView.cpp
)

add_library(ASCII_LINES INTERFACE)

target_include_directories(ASCII_LINES
	INTERFACE "D:\\Documents\\Visual Studio 2019\\Projects\\C++\\ASCII\\ASCII")

target_compile_definitions(ASCII_LINES
	INTERFACE COOL_FEATURE=1
		$<$<COMPILE_FEATURES:cxx_std_14>:HAVE_CXX11>)

target_link_libraries(ASCII_LINES INTERFACE ASCII_LINES)
