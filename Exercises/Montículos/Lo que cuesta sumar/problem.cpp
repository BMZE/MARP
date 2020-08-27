#include <queue>
#include <iostream>

using namespace std;

//Processes & solves case
//O(n log n)
bool SolveCase()
{
	int n; cin >> n; //number of numbers to add
	if (n == 0)
		return false;
	else if (n == 1) //if there is only one number there are no additions to make
	{
		int discard;  cin >> discard;
		cout << '0' << '\n';
		return true;
	}

	priority_queue<long long, vector<long long>, greater<long long>> queue; //queue to store numbers in min order, long due to max possible value

	for (int i = 0; i < n; i++)
	{
		long number; cin >> number;
		queue.push(number);
	}

	long solution = 0; //stores the sum of all additions

	while (!queue.empty())
	{
		long a = queue.top();
		queue.pop();

		long b = queue.top();
		queue.pop();

		a += b; //add the first lesser values
		solution += a; //add effort
		
		if (!queue.empty())
			queue.push(a); //push result as it needs to be added to the rest of the numbers
	}

	cout << solution << '\n';

	return true;
}

int main()
{
	while (SolveCase()); //solve problem as long as there are cases

	//system("PAUSE");
}