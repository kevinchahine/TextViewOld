#include "LineView.h"

// ========================== CONSTRUCTORS ====================================

LineView::LineView(
	size_t nRows,
	size_t nCols,
	char initializer) :
	View<char>(nRows, nCols, initializer) {}

LineView::LineView(const LineView& view) :
	View<char>(static_cast<View<char>>(view))
{
}

LineView::LineView(const LineView&& view) :
	View<char>(static_cast<View<char>>(view))
{
}

LineView::LineView(const View<char>& view) :
	View<char>(view)
{
}

LineView::LineView(const View<char>&& view) :
	View<char>(view)
{
}

LineView::~LineView()
{
}

void LineView::print(std::ostream& os) const
{
	for (size_t row = 0; row < this->nRows; row++) {
		for (size_t col = 0; col < this->nCols; col++) {
			os << this->vec[map(row, col)];
		}
		os << std::endl;
	}
	os << std::endl;
}


