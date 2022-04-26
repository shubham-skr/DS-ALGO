/*
	 Prim's Algorithm
	 for Minimum Spanning Tree
*/

#include <iostream>
#include <vector>
#include <set>
using namespace std;

const int INF = INT_MAX;

struct Edge
{
	int w = INF;
	int to = -1;
};

int V;

vector<vector<int>> adjMatrix;

void prim()
{
	int totalWeight = 0;
	vector<bool> selected(V, false);
	vector<Edge> minEdge(V);
	minEdge[0].w = 0;

	for (int i = 0; i < V; i++)
	{
		int v = -1;
		for (int j = 0; j < V; j++)
		{
			if (!selected[j] && (v == -1 || minEdge[j].w < minEdge[v].w))
				v = j;
		}

		selected[v] = true;
		totalWeight += minEdge[v].w;
		
		for (int u = 0; u < V; u++)
		{
			if (adjMatrix[v][u] < minEdge[u].w)
				minEdge[u] = {adjMatrix[v][u], v};
		}
	}
	
	cout << totalWeight << endl;
}
