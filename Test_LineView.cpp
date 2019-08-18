#include "Test_LineView.h"

void Test_LineView::constructors()
{
	LineView<char> line(10, 20);

	line.print();
}
