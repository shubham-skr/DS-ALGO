/*

BELLMAN-FORD ALGORITHM

- single source shortest path
- works for graph with negative weight edges

*/

#include <iostream>
#include <vector>
using namespace std;

const int INF = INT_MAX;

struct Edge
{
	int u, v, w;
};

int V, E;
vector<Edge> edgeList;
vector<int> dist;

void bellmanFord(int s)
{
	dist.assign(V, INF);
	dist[s] = 0;

	for (int i = 0; i < V - 1; i++)
	{
		bool flag = false;

		for (int j = 0; j < E; j++)
		{
			if (dist[edgeList[j].u] < INF)
			{
				dist[edgeList[j].v] = min(dist[edgeList[j].v], dist[edgeList[j].u] + edgeList[j].w);
				flag = true;
			}
		}

		if (!flag)
			break;
	}
}
