/*
    DETECT CYCLE IN DIRECTED GRAPH
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;

bool isCycleUtil(int u, vector<bool> &visited, vector<bool> &recursionStack)
{
    if (visited[u] == false)
    {
        visited[u] = true;
        recursionStack[u] = true;

        for (auto v : adj[u])
        {
            if (!visited[v] && isCycleUtil(v, visited, recursionStack))
                return true;
            else if (recursionStack[v])
                return true;
        }
    }

    recursionStack[u] = false;
    return false;
}

bool isCycle(int n)
{
    vector<bool> visited(n, false);
    vector<bool> recursionStack(n, false);

    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && isCycleUtil(i, visited, recursionStack))
            return true;
    }

    return false;
}
