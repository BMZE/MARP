#include <queue>
#include <iostream>
#include <vector>
using namespace std;


//O(n log n) 
bool SolveCase()
{
	int b; cin >> b; //bags of candy
	if (!cin)
		return false;
	int n; cin >> n; //visits
	int m; cin >> m; //amount of candy a bag needs to give out candy

	priority_queue<int> candyBags;

	for (int i = 0; i < b; i++)
	{
		int c; cin >> c;
		candyBags.push(c);
	}

	int daysWithoutCandy = 0;

	for (int i = 0; i < n; i++) //register visits
	{
		int c; cin >> c; 

		if (candyBags.empty() || (candyBags.top() < m || c > candyBags.top())) //not enough candy
		{
			daysWithoutCandy++;
		}

		if (!candyBags.empty() && candyBags.top() >= m) //give out candy
		{
			int leftCandy = candyBags.top();
			candyBags.pop();

			leftCandy -= c; //c is the amount of candy taken from bag

			if (!candyBags.empty() && leftCandy < m && leftCandy > 0) //candy can be added to another bag
			{
				int biggestBag = candyBags.top();
				candyBags.pop();

				biggestBag += leftCandy;
				candyBags.push(biggestBag);
			}
			else if(leftCandy > 0) //candy is stored in its own bag
			{
				candyBags.push(leftCandy);
			}
		}

	}
	
	//display solution
	cout << daysWithoutCandy << '\n'; 
	
	while (!candyBags.empty())
	{
		cout << candyBags.top() << ' ';
		candyBags.pop();
	}

	cout << '\n';

	return true;
}


int main()
{
	while (SolveCase()); //solve problem as long as there are cases

	//system("PAUSE");
}