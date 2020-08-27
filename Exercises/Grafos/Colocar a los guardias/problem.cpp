#include <iostream>
#include "Grafo.h"
#include <vector>
#include <algorithm>
using namespace std;

class GuardsGraph
{
public:
	GuardsGraph(Grafo const &g)
	{
		marked.resize(g.V(), false);
		guardsSet.resize(g.V(), false);
		
			for (int i = 0; i < g.V(); i++)
			{
				if (!marked[i])
				{
					//cout << i + 1 << '\n';
					alterSelection++;
					dfs(g, i);
					totalGuards += min(selectedGuards, alterSelection);
					selectedGuards = 0;
					alterSelection = 0;
				}
			}
	};

	//Display solution
	void ShowGuards() 
	{ 
		if (!possible)
			cout << "IMPOSIBLE\n";
		else
			cout << totalGuards << '\n';
	}

private:

	void dfs(Grafo const &g, int v)
	{
		marked[v] = true;
		for (int w : g.ady(v))
		{
			if (!marked[w])
			{
				//cout << w + 1 << '\n';

				guardsSet[w] = !guardsSet[v];

				if (guardsSet[w])
					selectedGuards++;
				else
					alterSelection++;

				dfs(g, w);
			}
			else if (guardsSet[w] == guardsSet[v])
			{
				possible = false;
			}
		}

	};

	vector<bool> marked; 
	vector<bool> guardsSet;
	bool possible = true;
	int totalGuards = 0; //minimun amount pf guards
	int selectedGuards = 0; //number of guards in dfs
	int alterSelection = 0; //possible amount of guards after dfs
};

//O(V+E)
bool SolveCase()
{
	int V, E; //vertexes, edges 
	cin >> V;
	if (!cin)
		return false;
	
	cin >> E;

	Grafo graph(V);

	for (int i = 0; i < E; i++) //add edges to graph
	{
		int v1, v2;
		cin >> v1 >> v2;
		graph.ponArista(v1-1, v2-1);
	}

	GuardsGraph g(graph); //set guards

	g.ShowGuards(); //show solution

	return true;
}

int main()
{
	while (SolveCase());
	return 0;
}
