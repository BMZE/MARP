#include <iostream>
#include "Grafo.h"
#include <vector>
#include <algorithm>
using namespace std;


class NewsReach
{
public:
	NewsReach(Grafo const &g)
	{
		marked.resize(g.V(), false);
		reachedUsers.resize(g.V(), 0);

		for (int i = 0; i < g.V(); i++)
		{
			if (!marked[i])
			{
				size = 1;
				markedUsers.push_back(i); //add first user
				dfs(g, i); //count max reach from i user
				
				for (int j = 0; j < markedUsers.size(); j++)
					reachedUsers[markedUsers[j]] = size; //size to all users in the group

				markedUsers.clear(); //clear users in the group
			}
		}
	}

	//Display solution
	void ShowReach()
	{
		for (int &i : reachedUsers)
			cout << i << ' ';
	}


private:
	vector<bool> marked; 
	vector<int> reachedUsers;
	vector<int> markedUsers;
	int size;

	void dfs(Grafo const &g, int v)
	{
		marked[v] = true;
		
		for (int w : g.ady(v))
		{
			if (!marked[w])
			{
				marked[w] = true;
				markedUsers.push_back(w); //add marked user
				size++; //add to max reach
				dfs(g, w);
			}
		}
	}
};

//O(V + E)
bool SolveCase()
{
	int n; cin >> n;
	if (!cin)
		return false;

	int m; cin >> m;

	Grafo g(n);

	for (int i = 0; i < m; i++) //fill in edges in graph
	{
		int u; cin >> u;
		if (u > 1)
		{
			int f; cin >> f;
			for (int j = 1; j < u; j++)
			{
				int c; cin >> c;
				g.ponArista(f - 1, c - 1);
				f = c;
			}
		}
		else if (u > 0)
			cin >> u; //discard the number
	}


	NewsReach nr(g);

	nr.ShowReach();

	cout << '\n';

	return true;
}

int main()
{
	while (SolveCase());
	return 0;
}