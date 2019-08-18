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
