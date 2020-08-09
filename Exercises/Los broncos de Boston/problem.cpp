#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//O(n log n) where n is the number of matches
bool SolveCase()
{
	int n; cin >> n;
	if (n == 0)
		return false;

	vector<int> homeTeam; homeTeam.resize(n);
	vector<int> awayTeam; awayTeam.resize(n);

	for (int i = 0; i < n; i++)
		cin >> awayTeam[i];
	for (int i = 0; i < n; i++)
		cin >> homeTeam[i];

	sort(awayTeam.begin(), awayTeam.end()); //desdencing order
	sort(homeTeam.begin(), homeTeam.end(), greater<int>()); //ascending order

	int solution = 0;

	for (int i = 0; i < n; i++)
	{
		if (homeTeam[i] - awayTeam[i] > 0)
			solution += homeTeam[i] - awayTeam[i];
	}

	cout << solution << '\n';

	return true;
}

int main()
{
	while (SolveCase());
	return 0;
}