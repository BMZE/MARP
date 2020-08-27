#include <iostream>
#include <queue>
using namespace std;

struct battery
{
	int id;
	int t; //next time to recharge
	int charge; //seconds for recharge
};

struct Compare 
{
	bool operator()(battery const &a, battery const &b)
	{
		return a.t > b.t || (a.t == b.t && a.id > b.id);
	}
};

//O(n log n) in which n is the number of elements pushed to the priority queue
bool SolveCase()
{
	int n; cin >> n;
	if (!cin)
		return false;

	priority_queue<battery, vector<battery>, Compare> runningBatteries;

	int order = 1;
	for (int i = 0; i < n; i++) //current batteries
	{
		battery data; cin >> data.t;
		data.id = order; order++;
		data.charge = data.t;
		runningBatteries.push(data);
	}

	int nB; cin >> nB;
	queue<battery> backupBatteries;

	for (int i = 0; i < nB; i++) //backup batteries
	{
		battery data; cin >> data.t;
		data.id = order; order++;
		data.charge = data.t;
		backupBatteries.push(data);
	}

	int z, t;
	cin >> z >> t;

	while (!runningBatteries.empty() && runningBatteries.top().t <= t)
	{
		battery bat = runningBatteries.top();
		runningBatteries.pop();

		bat.charge -= z; //reduce charge capacity 
	
		if (bat.charge > 0) //keep old battery
		{
			bat.t += bat.charge;
			runningBatteries.push(bat);
		}
		else if(!backupBatteries.empty()) //discard old battery
		{
			battery newBat = backupBatteries.front();
			backupBatteries.pop();

			newBat.t += bat.t; //add passed time to new battery
			runningBatteries.push(newBat);
			
		}
	}

	//print solution
	if (runningBatteries.size() == n)
	{
		cout << "CORRECTO\n";
		while (!runningBatteries.empty())
		{
			cout << runningBatteries.top().id << ' ' << runningBatteries.top().t << '\n';
			runningBatteries.pop();
		}
	}
	else if (!runningBatteries.empty())
	{
		cout << "FALLO EN EL SISTEMA\n";
		while (!runningBatteries.empty())
		{
			cout << runningBatteries.top().id << ' ' << runningBatteries.top().t << '\n';
			runningBatteries.pop();
		}
	}
	else
		cout << "ABANDONEN INMEDIATAMENTE LA BASE\n";

	cout << "---\n";

	return true;
}

int main()
{
	while (SolveCase());
	return 0;
}