#include <iostream>
#include <vector>
//#include "Matriz.h"
#include <algorithm>
using namespace std;

/*
 * groupsToWatch(i,j) = max groups to watch with j money considering the groups in the concerts from 1 to i
 *
 * Recursive function:
 *
 *							| groupsToWatch(i - 1, j)	if prices(i) > j
 * groupsToWatch(i,j) =		|
 *							| max(groupsToWatch(i - 1, j), darts(i - 1, j - prices[i]) + groups(i))   if prices(i)(i) <= j
 *
 * with 1 <= i <= n and 1 <= j <= M
 *
 * Base cases:
 * groupsToWatch(0, j) = 0 	 0 <= j <= M
 * groupsToWatch(i, 0) = 0 	 0 <= i <= n
*/

///SPACE NOT OPTIMIZED
//O(nT) in wich n is the number of section and Points the number of points trying to achieve
//and O(nT) in additional space 
//void CalculateConcerts(vector<int> const& groups, vector<int> const& prices, int M)
//{
//	int n = groups.size() - 1;
//	Matriz<int> groupsToWatch(n + 1, M + 1, 0);
//
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= M; j++)
//		{
//			if (prices[i] > j)
//				groupsToWatch[i][j] = groupsToWatch[i - 1][j];
//			else
//				groupsToWatch[i][j] = max(groupsToWatch[i - 1][j],
//					groupsToWatch[i - 1][j - prices[i]] + groups[i]);
//		}
//	}
//	cout << groupsToWatch[n][M] << '\n';
//}


///OPTIMIZED SPACE
//O(nM) in wich n is the number of elements in groups and prices and M the amount of money available
//and O(M) in additional space 
void CalculateConcerts(vector<int> const& groups, vector<int> const& prices, int M)
{
	int n = groups.size() - 1;
	vector<int> groupsToWatch(M + 1, 0);

	for (int i = 1; i <= n; i++)
	{
		for (int j = M; j >= prices[i]; j--)
		{
			groupsToWatch[j] = max(groupsToWatch[j], groupsToWatch[j - prices[i]] + groups[i]); //fill in vector
		}
	}

	cout << groupsToWatch[M] << '\n';
}

bool SolveCase()
{
	int p, n; 
	cin >> p >> n;
	if (!cin)
		return false;

	vector<int> groups; groups.resize(n + 1);
	vector<int> prices; prices.resize(n + 1);

	for (int i = 1; i <= n; i++)
		cin >> groups[i] >> prices[i];

	CalculateConcerts(groups, prices, p);

	return true;
}

int main()
{
	while (SolveCase());
	return 0;
}