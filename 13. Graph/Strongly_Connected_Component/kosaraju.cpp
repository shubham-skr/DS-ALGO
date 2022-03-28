/*
	Finding Strongly Connected Component
	- Kosaraju's Algorithm
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> adj, adjRev;
vector<bool> visited;
vector<int> order, component;
vector<vector<int>> scc;

void topologicalSort(int v)
{
	visited[v] = true;

	for (auto u : adj[v])
	{
		if (!visited[u])
			topologicalSort(u);
	}

	order.push_back(v);
}

void dfsRev(int v)
{
	visited[v] = true;
	component.push_back(v);

	for (auto u : adjRev[v])
	{
		if (!visited[u])
			dfsRev(u);
	}
}

int main()
{
	int V, E;
	cin >> V >> E;

	for (int i = 0; i < E; i++)
	{
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adjRev[y].push_back(x);
	}

	visited.resize(V, false);

	for (int i = 0; i < V; i++)
	{
		if (!visited[i])
			topologicalSort(i);
	}
	reverse(order.begin(), order.end());

	visited.resize(V, false);

	for (auto v : order)
	{
		if (!visited[v])
			dfsRev(v);

		scc.push_back(component);
		component.clear();
	}
}
