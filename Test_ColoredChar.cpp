#include "Test_ColoredChar.h"

using namespace std;

void Test_ColoredChar::test()
{
	ColoredChar<char> def;
	ColoredChar<char> full(Color::mergeColor(Color::GREEN, Color::BLUE), 'f');
	ColoredChar<char> copy(full);
	ColoredChar<char> move(ColoredChar<char>(Color::mergeColor(Color::GREEN, Color::BLUE), 'f'));

	cout << "def: " << setw(10) << def << '\n';
	cout << "full: " << setw(10) << full << '\n';
	cout << "copy: " << setw(10) << copy << '\n';
	cout << "move: " << setw(10) << move << '\n';
	cout.flush();

	ColoredChar<wchar_t> wdef;
	ColoredChar<wchar_t> wfull;/// (Color::mergeColor(Color::GREEN, Color::BLUE), 'f');
	ColoredChar<wchar_t> wcopy(wfull);
	ColoredChar<wchar_t> wmove;/// (ColoredChar<wchar_t>(Color::mergeColor(Color::GREEN, Color::BLUE), 'f'));

	cout << "wdef: " << setw(10) <<  wdef << '\n';
	cout << "wfull: " << setw(10) << wfull << '\n';
	cout << "wcopy: " << setw(10) << wcopy << '\n';
	cout << "wmove: " << setw(10) << wmove << '\n';
	cout.flush();
}

void Test_ColoredChar::streams()
{
	ColoredChar<char> c;

	stringstream ss;

	ss << 'A';

	ss >> c;

	cout << c << endl;
}
