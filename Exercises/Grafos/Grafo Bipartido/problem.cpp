#include <iostream>
//#include "Grafos/Grafo.h"
#include "Grafo.h"
#include <vector>
using namespace std;

class SplitGraph
{
public:
	SplitGraph(Grafo const &g)
	{
		marked.resize(g.V(), false);
		coloured.resize(g.V(), false);
		
			for (int i = 0; i < g.V(); i++)
			{
				if (!marked[i])
				{
					if (!dfs(g, i))
						break;
				}
			}
		

	};

	bool IsSplit() { return split; };

private:

	bool dfs(Grafo const &g, int v)
	{
		marked[v] = true;
		for (int w : g.ady(v))
		{
			if (!marked[w])
			{
				coloured[w] = !coloured[v];
				dfs(g, w);
			}
			else if (coloured[w] == coloured[v])
			{
				split = false;
				return false;
			}
		}

		return true;
	};

	vector<bool> marked; 
	vector<bool> coloured;
	bool split = true;
};

//O(V+E) where V is the number of vertexes and E the number of edges
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
		graph.ponArista(v1, v2);
	}


	SplitGraph sg(graph);

	if (sg.IsSplit())
		cout << "SI\n";
	else
		cout << "NO\n";

	return true;
}

int main()
{
	while (SolveCase());
	return 0;
}