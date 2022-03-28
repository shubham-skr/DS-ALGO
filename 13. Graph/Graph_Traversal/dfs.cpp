/*
	GRAPH TRAVERSAL - Depth First Search
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> dist, parent;
vector<bool> visited;
int n;

void dfs(int u)
{
	visited[u] = true;

	for (int v : adj[u])
	{
		if (!visited[v])
		{
			parent[v] = u;
			dist[v] = dist[u] + 1;
			dfs(v);
		}
	}
}
