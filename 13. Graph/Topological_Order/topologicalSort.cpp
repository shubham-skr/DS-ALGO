#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;

void topologicalOrder(int u, stack<int> &stk)
{
    visited[u] = true;

    for (auto v : adj[u])
    {
        if (!visited[v])
            topologicalOrder(v, stk);
    }

    stk.push(u);
}

int main()
{
    adj.resize(4);
    adj[0] = {1, 2};
    adj[1] = {3};
    adj[2] = {3};
    adj[3] = {};

    visited.resize(4, false);

    stack<int> stk;

    topologicalOrder(0, stk);

    while (!stk.empty())
    {
        cout << stk.top() << "  ";
        stk.pop();
    }
    cout << endl;
}
