#include <queue>
#include <iostream>
#include <string>

using namespace std;


struct patient
{
	string name;
	int severity; 
	int arrival; //order in which the patients come
};

struct Compare
{
	bool operator()(patient const &a, patient const &b)
	{
		return a.severity < b.severity || (a.severity == b.severity && a.arrival > b.arrival);
	}
};

//O(n log n) 
bool SolveCase()
{
	int n; cin >> n; //number of events
	if (n == 0)
		return false;

	//queue order: patient with most severity, or patient who waited longer
	priority_queue<patient, vector<patient>, Compare> queue; 


	for (int i = 0; i < n; i++)
	{
		char event; cin >> event;

		if (event == 'I') //insert patient to queue
		{
			patient p; 
			cin >> p.name; cin >> p.severity; 
			p.arrival = i;
			queue.push(p);
		}
		else if (event == 'A') //treat patient with most severity
		{
			cout << queue.top().name << '\n';
			queue.pop();
		}
	}

	cout << "---\n"; //end of cases

	return true;
}


int main()
{
	while (SolveCase()); //solve problem as long as there are cases

	//system("PAUSE");
}