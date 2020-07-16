#include <queue>
#include <iostream>

using namespace std;

struct user
{
	int id; 
	int period; 
	int turn;
};

struct Compare 
{
	bool operator () (const user &a, const user &b) //return false when a and b have to exchange places
	{
		return a.turn > b.turn || (a.turn == b.turn && a.id > b.id);
	}
};


//O(n log n) 
bool SolveCase()
{
	int n; cin >> n; 
	if (n == 0)
		return false;

	priority_queue<user, vector<user>, Compare> userQueue;

	for (int i = 0; i < n; i++)
	{
		user u; 
		cin >> u.id; cin >> u.period; u.turn = u.period; 
		userQueue.push(u);
	}

	int k; cin >> k; //number of info sent to display

	for (int i = 0; i < k; i++)
	{
		cout << userQueue.top().id << '\n'; //display user id 

		user u = userQueue.top(); userQueue.pop();
		u.turn += u.period;
		userQueue.push(u);
	}

	cout << "---\n"; //end of case

	return true;
}


int main()
{
	while (SolveCase()); //solve problem as long as there are cases

	system("PAUSE");
}