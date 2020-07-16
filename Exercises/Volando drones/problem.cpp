#include <queue>
#include <iostream>
#include <vector>

using namespace std;

//O(n log n) 
bool SolveCase()
{
	int n; cin >> n; //number of drones
	if (!cin)
		return false;

	int nA; cin >> nA; //number of batteries of type A
	int nB; cin >> nB; //number of batteries of type B

	priority_queue<int> batA; //first element is the bigger element
	priority_queue<int> batB;

	for (int i = 0; i < nA; i++)
	{
		int battery; cin >> battery;
		batA.push(battery);
	}

	for (int i = 0; i < nB; i++)
	{
		int battery; cin >> battery;
		batB.push(battery);
	}

	int totalTime = 0;
	int drones = n; //drones left to fly

	vector<int> usedA; usedA.reserve(nA); //as all drones fly at the same time, batteries are reused
	vector<int> usedB; usedB.reserve(nB); //once all drones have flown

	while (!batA.empty() && !batB.empty()) //no batteries left of one type
	{
		while (drones-- && !batA.empty() && !batB.empty())
		{
			int a = batA.top(); batA.pop();
			int b = batB.top(); batB.pop();

			if (a > b) //battery b died befor a
			{
				a -= b;
				usedA.push_back(a);
				totalTime += b;
			}
			else //battery a died befor b
			{
				b -= a;
				usedB.push_back(b);
				totalTime += a;
			}
		}
		
		if (totalTime != 0) //all drones have flied at least once
		{
			drones = n;
			cout << totalTime << ' ';
			totalTime = 0;

			for (auto i : usedA) //add used batteries for reuse
				batA.push(i);
			for (auto i : usedB)
				batB.push(i);

			usedA.clear(); 
			usedB.clear(); 
		}
	}

	if(totalTime != 0) //if not all drones flew but some did
		cout << totalTime;

	cout << '\n';

	return true;
}


int main()
{
	while (SolveCase()); //solve problem as long as there are cases

	//system("PAUSE");
}