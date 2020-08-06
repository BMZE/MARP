#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//O(n log n) in which n is the number of elements for heights and lengths
bool SolveCase()
{
	int n; cin >> n;
	if (n == 0)
		return false;

	vector<int> heights; heights.resize(n);
	vector<int> lengths; lengths.resize(n);

	for (auto &i : heights)
	{
		int data; cin >> data;
		i = data;
	}

	for (auto &i : lengths)
	{
		int data; cin >> data;
		i = data;
	}

	sort(heights.begin(), heights.end()); //O(n log n)
	sort(lengths.begin(), lengths.end());

	int solution = 0;

	for (int i = 0; i < n; i++)
	{
		solution += abs(heights[i] - lengths[i]);
	}

	cout << solution << '\n';
	return true;
}

int main()
{
	while (SolveCase());
	return 0;
}