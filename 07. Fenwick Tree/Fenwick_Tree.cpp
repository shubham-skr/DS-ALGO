/*
    FENWICK TREE (BINARY INDEXED TREE)
        for prefix sum queries and update
*/

#include <vector>
using namespace std;

class FenwickTree
{
private:
    int n;
    vector<int> ft;

    int query(int);

public:
    FenwickTree(int n)
    {
        this->n = n + 1;
        ft.resize(this->n, 0);
    }

    // update a node
    void update(int, int);

    // query for a range
    int query(int l, int r)
    {
        return query(r) - query(l - 1);
    }
};

void FenwickTree::update(int x, int y)
{
    x++; // 1 based indexing
    while (x < n)
    {
        ft[x] += y;
        x += (x & (-x)); // add last set bit
    }
}

int FenwickTree::query(int x)
{
    x++; // 1 based indexing
    int ans = 0;
    while (x)
    {
        ans += ft[x];
        x -= (x & (-x)); // subtract last set bit
    }
    return ans;
}
