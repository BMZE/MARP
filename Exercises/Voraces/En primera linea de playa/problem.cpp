#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;


//O(n) where n is the number of buildings
bool SolveCase()
{
	int n; cin >> n;
	if (n == 0)
		return false;
	
	vector<pair<int, int>> buildings; //first = left position, second = width (right position)
	buildings.resize(n);

	for (int i = 0; i < n; i++)
		cin >> buildings[i].first >> buildings[i].second;

	sort(buildings.begin(), buildings.end()); //sort from first element in ascending order

	int tunels = 0;
	int current = 0;

	for (int i = 1; i < n; i++)
	{
		if (buildings[i].first >= buildings[current].second)
		{
			current = i;
			tunels++;
		}
		else if (buildings[i].second < buildings[current].second)
			current = i;
	}

	tunels++;

	cout << tunels << '\n';

	return true;
}

int main()
{
	while (SolveCase());
	return 0;
}