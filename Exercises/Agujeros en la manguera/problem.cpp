#include <iostream>
#include <vector>
using namespace std;

//O(n) in which n is the number od holes
bool SolveCase()
{
	int n; cin >> n; //number of holes
	if (!cin)
		return false;

	int length; cin >> length; //length of patch

	int solution = 0;
	
	vector<int> holePositions; //location of each hole
	holePositions.resize(n);

	for (auto &i : holePositions) //hole data
	{
		int data; cin >> data;
		i = data;
	}

	int pos = 0;
	for (int i = 0; i < n; i++)
	{
		if(i + 1 == n) //always count last patch
			solution++;
		else if (holePositions[pos] + length < holePositions[i+1]) 
		{
			solution++; //add patch
			pos = i + 1;
		}
	}
	
	cout << solution << '\n';

	return true;
}

int main()
{
	while (SolveCase());
	return 0;
}