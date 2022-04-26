/*

Dijkstra Algorithm

- single source shortest paths
- greedy algorithm
- works for weighted graph
- doesn't work for graph with negative weight edges

*/


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = INT_MAX;

vector<vector<pair<int, int>>> adj;
vector<int> dist, parent;
vector<bool> visited;

void dijkstra(int s)
{
	int n = adj.size();
	dist.assign(n, INF);
	parent.assign(n, -1);
	visited.assign(n, false);

	dist[s] = 0;

	for (int i = 0; i < n; i++)
	{
		int v = -1;
		for (int j = 0; j < n; j++)
		{
			if (!visited[j] && (v == -1 || dist[j] < dist[v]))
				v = j;
		}

		visited[v] = true;

		for (auto edge : adj[v])
		{
			int u = edge.first;
			int weight = edge.second;

			if ((dist[v] + weight) < dist[u])
			{
				dist[u] = dist[v] + weight;
				parent[u] = v;
			}
		}
	}
}

vector<int> restorePath(int s, int t)
{
	vector<int> path;

	for (int v = t; v != s; v = parent[v])
		path.push_back(v);
	path.push_back(s);

	reverse(path.begin(), path.end());

	return path;
}
