#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

//O(n log m) in which n is the number of sizes and m the number of kits
bool SolveCase()
{
	int n, m;
	cin >> n;
	if (!cin)
		return false;
	cin >> m;

	vector<int> sizes; sizes.resize(n);
	priority_queue<int, vector<int>, greater<int>> kits; 

	for (int i = 0; i < n; i++)
		cin >> sizes[i];
	
	sort(sizes.begin(), sizes.end()); //ascending order

	for (int i = 0; i < m; i++)
	{
		int kit; cin >> kit;
		kits.push(kit);
	}

	int index = 0;
	int solution = 0;

	while(index < n && !kits.empty())
	{
		if (kits.top() < sizes[index]) //kit is too small
			kits.pop();
		else if (kits.top() == sizes[index] || kits.top() == sizes[index] + 1) //kit can be used
		{
			kits.pop();
			index++;
		}
		else if (kits.top() > sizes[index]) //kit is too big
		{
			solution++;
			index++;
		}
	}

	if (index != n) //not all kids have kits, buy the rest
		solution += n - index;

	cout << solution << '\n';

	return true;
}

int main()
{
	while (SolveCase());
	return 0;
}