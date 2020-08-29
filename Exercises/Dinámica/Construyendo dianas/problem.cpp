#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1000;

//O(n) in which n is the number of sections
void GetDarts(vector<int> const & pointsInSections, int Points, vector<int> &darts)
{
	int n = pointsInSections.size() - 1;
	int i = n; int j = Points;

	while (j > 0) //yet to gather all points
	{
		if (pointsInSections[i] <= j && darts[j] == darts[j - pointsInSections[i]] + 1) //dart thrown to section
		{
			cout << pointsInSections[i] << ' '; //print points in section
			j = j - pointsInSections[i];
		}
		else
			i--;
	}

	cout << '\n';
}

/*
 * darts(i,j) = min darts to obtain j points considering the points in the sections from 1 to i
 *
 * Recursive function:
 *
 *					| darts(i - 1, j)	if pointsInSections(i) > j
 * darts(i,j) =		|
 *					| min(darts(i - 1, j), darts(i - 1, j - pointsInSections[i]) + 1)   if pointsInSections(i)(i) <= j
 *
 * with 1 <= i <= n and 1 <= j <= Points
 *
 * Base cases:
 * darts(0, j) = 0 	 0 <= j <= Points
 * darts(i, 0) = 0 	 0 <= i <= n
*/

//O(nT) in wich n is the number of section and Points the number of points trying to achieve
//and O(T) in additional space
void DartsToThrow(vector<int> const & pointsInSections, int Points)
{
	int n = pointsInSections.size() - 1;
	vector<int> darts(Points + 1, INF);
	darts[0] = 0;

	for (int i = 1; i <= n; i++)
	{
		for (int j = pointsInSections[i]; j <= Points; j++)
		{
			darts[j] = min(darts[j], darts[j - pointsInSections[i]] + 1); //fill in vector
		}
	}

	if (darts[Points] != INF)
	{
		cout << darts[Points] << ": ";
		GetDarts(pointsInSections, Points, darts);
	}
	else
		cout << "Imposible\n";
}



bool SolveCase()
{
	int V, S; 
	cin >> V >> S;
	if (!cin)
		return false;

	vector<int> pointsInSections;
	pointsInSections.resize(S + 1);

	for (int i = 1; i <= S; i++)
		cin >> pointsInSections[i];

	DartsToThrow(pointsInSections, V);

	return true;
}

int main()
{
	while (SolveCase());
	return 0;
}