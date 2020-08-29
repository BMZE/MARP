#include <iostream>
#include <vector>
#include <algorithm>
#include "Matriz.h"
using namespace std;

/*
 * goldTaken(i,j) = max gold value we can obtain with j being the max possible time considering the gold from 1 to i
 * 
 * Recursive function:
 *
 *					| goldTaken(i - 1, j)	if depth(i) > j 
 * goldTaken(i,j) = |
 *					| max(goldTaken(i - 1, j), goldTaken(i - 1, j - depth[i]) + gold(i)) if depth(i) <= j 
 * with 1 <= i <= n and 1 <= j <= T
 * 
 * Base cases: 
 * goldTaken(0, j) = 0 	 0 <= j <= T
 * goldTaken(i, 0) = 0 	 0 <= i <= n
*/

//O(nT) in wich n is the number of chests and T the total time available
void TreasureChests(vector<int> const & gold, vector<int> const & time,int T, int &maxGold, 
	vector<bool> &chestsTaken, int &chests)
{
	int n = time.size() - 1;
	Matriz<int> goldTaken(n + 1, T + 1, 0);
	
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= T; j++)
		{
			if (time[i] > j)
				goldTaken[i][j] = goldTaken[i - 1][j];
			else
				goldTaken[i][j] = max(goldTaken[i - 1][j],
					goldTaken[i - 1][j - time[i]] + gold[i]);
		}
	}
	maxGold = goldTaken[n][T];

	//cálculo de los objetos
	int rest = T;
	for (int i = n; i >= 1; --i)
	{
		if (goldTaken[i][rest] == goldTaken[i - 1][rest])
		{	//no cogemos objeto i
			chestsTaken[i] = false;
		}
		else
		{ //sí cogemos objeto i 
			chestsTaken[i] = true;
			rest = rest - time[i];
			chests++;
		}
	}
}

bool SolveCase()
{
	int t; cin >> t;
	if (!cin)
		return false;

	int n; cin >> n;

	vector<int> gold; gold.resize(n+1);
	vector<int> time; time.resize(n+1);

	for (int i = 1; i <= n; i++)
	{
		cin >> time[i] >> gold[i]; //1d
		time[i] *= 3; //2d
	}
	
	
	vector<bool> chestsTaken; chestsTaken.resize(n+1);
	int chests = 0; //number of chests taken
	int maxGold = 0;
	TreasureChests(gold, time, t, maxGold, chestsTaken, chests);

	//print solution
	cout << maxGold << '\n';
	cout << chests << '\n';

	for (int i = 0; i <= n; i++)
	{
		if (chestsTaken[i])
			cout << time[i] / 3 << ' ' << gold[i] << '\n';
	}

	cout << "----\n";

	return true;
}

int main()
{
	while (SolveCase());
	return 0;
}