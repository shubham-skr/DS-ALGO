/*
	DISJOINT SET UNION with
	UNION BY RANK and
	PATH COMPRESSION optimization
*/

#include <vector>
using namespace std;

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
	int pu = findSet(u);
	int pv = findSet(v);

	if (pu != pv)
	{
		if (rnk[pu] < rnk[pv])
			swap(pu, pv);
		parent[pv] = pu;
		if (rnk[pu] == rnk[pv])
			rnk[pu]++;
	}
}
