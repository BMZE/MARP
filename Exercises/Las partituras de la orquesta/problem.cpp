#include <queue>
#include <iostream>

using namespace std;

struct group
{
	int musicians;
	int musicSheets;
};

struct Compare
{
	bool operator()(group const &a, group const &b)
	{
		int first, second;
		if (a.musicians % a.musicSheets == 0) first = a.musicians / a.musicSheets;
		else first = a.musicians / a.musicSheets + 1;

		if (b.musicians % b.musicSheets == 0) second = b.musicians / b.musicSheets;
		else second = b.musicians / b.musicSheets + 1;

		return first < second;
	}
};

//O(n log n) 
bool SolveCase()
{
	int p; cin >> p; //number of available music sheets
	if (!cin)
		return false;

	int n; cin >> n; //types of instruments

	priority_queue<group, vector<group>, Compare> groups; //musicians in each music stand 

	int musicSheetsBought = 0; //assigned music sheets

	while(musicSheetsBought < n) //there is at least one music sheet per instrument group
	{
		group g; cin >> g.musicians;
		g.musicSheets = 1;
		groups.push(g);
		musicSheetsBought++;
	}

	while (musicSheetsBought < p) //if there are more music sheets, give to group with most members
	{
		group g = groups.top();
		groups.pop();

		g.musicSheets++;
		groups.push(g);

		musicSheetsBought++;
	}

	//display solution
	if(groups.top().musicians % groups.top().musicSheets == 0)
		cout << groups.top().musicians / groups.top().musicSheets << '\n';
	else 
		cout << groups.top().musicians / groups.top().musicSheets + 1 << '\n';

	return true;
}


int main()
{
	while (SolveCase()); //solve problem as long as there are cases

	//system("PAUSE");
}