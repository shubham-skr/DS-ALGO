/*

FLOYD WARSHALL ALGORITHM

- all pairs shortest path
- dynamic programming based algorithm

*/

#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9;

int V;
vector<vector<int>> adjMatrix;
vector<vector<int>> dist;

void floydWarshall()
{
	int i, j, k;

	for (i = 0; i < V; i++)
		for (j = 0; j < V; j++)
			dist[i][j] = adjMatrix[i][j];

	for (k = 0; k < V; k++)
	{
		for (i = 0; i < V; i++)
		{
			for (j = 0; j < V; j++)
			{
				if (dist[i][k] + dist[k][j] < dist[i][j])
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}
}
