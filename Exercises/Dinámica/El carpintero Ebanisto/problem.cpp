#include <iostream>
#include <vector>
#include <algorithm>
#include "Matriz.h"
using namespace std;

int const INF = 100000000;

void Effort(vector<int> const& positions)
{
	int n = positions.size();

	Matriz<int> matrices(n, n, 0);

	for (int d = 2; d <= n; d++)
	{
		for (int i = 0; i < n - d; i++)
		{
			int j = i + d;

			//mini = min(mini, tabla[f][k] + tabla[k][c] + (2 * (cortes[c] - cortes[f])));

			//min
			matrices[i][j] = INF;
			for (int k = i + 1; k < j; k++)
			{	
				int temp = matrices[i][k] + matrices[k][j] + (2 * (positions[j] - positions[i]));

				if (temp < matrices[i][j])
				{
					matrices[i][j] = temp;
				}
			}
		}
	}

	cout << matrices[0][n-1] << '\n';
}

bool SolveCase()
{
	int L, N;
	cin >> L >> N;
	
	if (L == 0 && N == 0)
		return false;

	vector<int> positions; positions.resize(N + 2, 0);

	positions[N + 1] = L;

	for (int i = 1; i <= N; i++)
		cin >> positions[i];

	Effort(positions);


	return true;
}

int main()
{
	while (SolveCase());
	return 0;
}