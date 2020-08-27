#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;


//O(n log n)
bool SolveCase()
{
	int n; cin >> n;
	if (n == 0)
		return false;

	vector<pair<int, int>> activities;
	activities.resize(n);

	for (int i = 0; i < n; i++)
		cin >> activities[i].first >> activities[i].second;
	
	sort(activities.begin(), activities.end()); //ascending order from start time

	int solution = 0;
	int current = 0;

	priority_queue<int, vector<int>, greater<int>> friends;

	for (int i = 1; i < n; i++) //always available for the first activity
	{
		if (activities[current].second > activities[i].first) //current activity ends after next actv starts
		{
			if (friends.empty() || friends.top() > activities[i].first) //no friends helped yet, friends are still in activities
			{
				friends.push(activities[i].second); //only matters when the activity ends
				solution++;
			}
			else //friends activity ends before new one starts
			{
				friends.pop(); 
				friends.push(activities[i].second);
			}
		}
		else
			current = i;
	}

	cout << solution << '\n';

	return true;
}

int main()
{
	while (SolveCase());
	return 0;
}