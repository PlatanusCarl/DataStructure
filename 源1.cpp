#include<iostream>
#include<ostream>
#include<iomanip>

int main()
{
	using namespace std;
	
	int const low(1);
	int const high(10);
	int const colwidth(4);

	cout << right;

	cout << setw(colwidth) << '*' << '|';
	for (int i(low); i <= high; i++)
		cout << setw(colwidth) << i;
	cout << '\n';

	cout << setfill('-') << setw(colwidth) << "" << '+' << setw(colwidth*(high - low + 1)) << "" << '\n';

	cout << setfill(' ');


	for (int row(low); row <= high; row++)
	{
		cout << setw(colwidth) << row << '|';
		for (int col(low); col <= high; col++)
			cout << setw(colwidth) << row * col;
		cout << '\n';
	}
}