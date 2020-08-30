#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include "Matriz.h"
#include "Grafo.h"
#include <map>
using namespace std;

const int INF = 100000000; //10^9

void Floyd(Matriz<int> const &G, Matriz<int> &C)
{
	int n = G.numfils() - 1;
	C = G;
	
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				int temp = C[i][k] + C[k][j];
				if (temp < C[i][j]) //best to go trough k
				{
					C[i][j] = temp;
					
				}
			}
		}
	}
}

void print_paths(Matriz<int> const& C)
{
	int n = C.numfils() - 1;
	int maxP = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i != j && C[i][j] < INF)
			{
				maxP = max(C[i][j], maxP);
			}
		}
	}

	cout << maxP << '\n';
}

bool SolveCase()
{
	int p, r; 
	cin >> p >> r;
	if (!cin)
		return false;

	Grafo g(p);

	map<string, int> people;
	string nameA, nameB;

	for (int i = 0; i < r; i++) //fill in graph in order of appeareance
	{
		cin >> nameA >> nameB;

		if (people.count(nameA) == 0) //register vertex if name is not in
			people[nameA] = people.size() + 1;
		if (people.count(nameB) == 0) 
			people[nameB] = people.size() + 1;
	
		g.ponArista(people[nameA] - 1, people[nameB] - 1); //add vertex relation
	}
	
	Matriz<int> graph(p + 1, p + 1, INF);
	for (int u = 1; u <= p; u++)
		graph[u][u] = 0;

	for (int i = 0; i < g.V(); i++)
	{
		for (int w : g.ady(i))
			graph[i + 1][w + 1] = 1;
	}

	Matriz<int> C(0, 0);

	Floyd(graph, C);

	bool disconected = false;

	for (int j = 1; j < C.numfils(); j++) 
	{
		if (C[1][j] == INF) 
		{
			disconected = true;
			break;
		}
	}

	if (disconected)
		cout << "DESCONECTADA\n";
	else
		print_paths(C);

	return true;
}

int main()
{
	while (SolveCase());
	return 0;
}