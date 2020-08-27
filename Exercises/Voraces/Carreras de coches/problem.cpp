#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//O(n log n) where n is the number of batteries
void SolveCase()
{

	int n; cin >> n;
	int v; cin >> v;

	vector<int> batteries;
	batteries.resize(n);

	for (int i = 0; i < n; i++)
		cin >> batteries[i];

	sort(batteries.begin(), batteries.end());

	int solution = 0;

	int l = 0;
	int i = n;

	while (l != i && i--)
	{
		while (i != l)
		{
			if (batteries[i] + batteries[l] >= v)
			{
				solution++;
				l++;
				break;
			}
			else
				l++;
		}
	}

	cout << solution << '\n';

}

int main()
{
	int n; cin >> n;
	while (n--)
		SolveCase();

	return 0;
}