#include "Test_Mutation.h"

void Test_Mutation::basicLine()
{
	TextView<char> view(10, 15);

	///Mutation<char> m;
	///m.applyTo(view);
	RectangleMutation<char> boarder(
		0, 0, 
		view.getNRows() - 1, view.getNCols() - 1); 
	boarder.applyTo(view);

	RectangleLineMutation<char> b(RectangleMutation<char>(1, 1, 3, 3));
	b.applyTo(view);
	
	HorizontalLineMutation<char> horLin(LineMutation<char>(2, 5, 7));
	horLin.applyTo(view);

	view.print();
}

void Test_Mutation::boxDrawing()
{
}
