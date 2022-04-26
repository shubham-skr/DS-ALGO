/*
	 Kruskal's ALgorithm
	 for Minimum Spanning Tree
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge
{
	int u, v, w;
	bool operator<(Edge e)
	{
		return w < e.w;
	}
};

int V, E;
vector<Edge> edgeList;

vector<int> rnk;
vector<int> parent;

int findSet(int v)
{
	if (v == parent[v])
		return v;
	else
		return (parent[v] = findSet(parent[v]));
}

void unionSet(int u, int v)
{
	if (rnk[u] < rnk[v])
		swap(u, v);
	parent[v] = u;
	if (rnk[u] == rnk[v])
		rnk[u]++;
}

void kruskal()
{
	int totalWeight = 0;
	int cnt = 1;

	sort(edgeList.begin(), edgeList.end());

	for (auto e : edgeList)
	{
		int pu = findSet(e.u);
		int pv = findSet(e.v);

		if (pu == pv)
			continue;

		unionSet(pu, pv);
		totalWeight += e.w;
		cnt++;

		if (cnt == V)
			break;
	}

	cout << totalWeight << endl;
}
