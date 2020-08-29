#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include "Matriz.h"
using namespace std;

int MaxSequence(int i, int j, int r, Matriz<int> &subsequence,
	string const &X, string const &Y)
{
	if (i == 0 || j == 0)
		return 0;
	else if (subsequence[i][j] != -1)
		return subsequence[i][j];
	else
	{
		if (X[i - 1] == Y[j - 1])  
			return subsequence[i][j] = 1 + MaxSequence(i - 1, j - 1, r, subsequence, X, Y);

		return subsequence[i][j] = max(MaxSequence(i, j - 1, r, subsequence, X, Y), MaxSequence(i - 1, j, r, subsequence, X, Y));
	}
}

bool SolveCase()
{
	string X;
	string Y;

	cin >> X >> Y;
	if (!cin)
		return false;

	int r = max(X.length(), Y.length());
	
	Matriz<int> subsequence(r + 1, r + 1, -1);
	
	cout << MaxSequence(X.length(), Y.length(), r, subsequence, X, Y) << '\n';

	return true;
}

int main()
{
	while (SolveCase());
	return 0;
}