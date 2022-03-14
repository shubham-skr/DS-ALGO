/*
    GRAPH TRAVERSAL
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> dist, parent;
vector<bool> visited;
int n;


// 1. Depth First Search
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


// 2. Breadth First Search
void bfs(int s)
{
    queue<int> q;
    q.push(s);

    visited[s] = true;
    dist[s] = 0;
    parent[s] = -1;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v : adj[u])
        {
            if (!visited[v])
            {
                visited[v] = true;
                q.push(v);
                dist[v] = dist[u] + 1;
                parent[v] = u;
            }
        }
    }
}
