#include <queue>
#include <iostream>

using namespace std;

//O(n log n) 
bool SolveCase()
{
	int lead; cin >> lead; //age of first bird
	if (lead == 0)
		return false;
	int m; cin >> m; //number of pairs to join

	//bird sides
	priority_queue<int, vector<int>, greater<int>> right;
	priority_queue<int> left;

	for (int i = 0; i < m; i++)
	{
		int a; cin >> a;
		int b; cin >> b; 

		if (a < lead) left.push(a); //add a & b to corresponding sides
		else right.push(a);

		if (b < lead) left.push(b);
		else right.push(b);

		if (left.size() != right.size())
		{
			if (left.size() < right.size())
			{
				left.push(lead);
				lead = right.top();
				right.pop();
			}
			else
			{
				right.push(lead);
				lead = left.top();
				left.pop();
			}
		}

		cout << lead << ' '; //display current lead
	}

	cout << '\n';

	return true;
}


int main()
{
	while (SolveCase()); //solve problem as long as there are cases

	//system("PAUSE");
}