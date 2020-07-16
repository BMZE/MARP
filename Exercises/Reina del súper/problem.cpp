#include <queue>
#include <iostream>

using namespace std;

struct cashier
{
	int id;
	int time;
};

struct Compare
{
	bool operator()(cashier const &a, cashier const &b)
	{
		return a.time > b.time|| (a.time == b.time && a.id > b.id);
	}
};

//O(n log n) 
bool SolveCase()
{
	int n; cin >> n; //number of cashiers
	int c; cin >> c; //number of clients

	if (n == 0 && c == 0)
		return false;
	
	priority_queue<cashier, vector<cashier>, Compare> cashiers;

	int occupied = 0;

	for (int i = 0; i < c; i++)
	{
		int time; cin >> time;

		if (occupied != n) //some checkers are free
		{
			cashier c; 
			c.id = i; c.time = time;
			cashiers.push(c); //add client
			occupied++;
		}
		else //checkers are full, client goes to the one with less time
		{
			cashier c = cashiers.top();
			cashiers.pop();
			c.time += time;
			cashiers.push(c);
		}
	}

	if(occupied == n) //clients > cashiers
		cout << cashiers.top().id + 1 << '\n';
	else
		cout << occupied + 1 << '\n';

	return true;
}


int main()
{
	while (SolveCase()); //solve problem as long as there are cases

	//system("PAUSE");
}