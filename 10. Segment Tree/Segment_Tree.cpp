/*

SEGMENT TREE
    - Build, Query and Update

*/


#include <vector>
using namespace std;

// Segment tree for range sum queries
class SegmentTree
{
private:
    // size of the segment tree
    int n;
    // segment tree
    vector<int> st;

    // overloaded functions
    void build(int, int, int, vector<int> &);
    int query(int, int, int, int, int);
    void update(int, int, int, int, int);

public:
    SegmentTree(int n)
    {
        this->n = n;
        st.resize(4 * n, 0);
    }

    // Build the segment tree
    void build(vector<int> &v)
    {
        build(0, n - 1, 0, v);
    }

    // Query for the range l to r
    int query(int l, int r)
    {
        return query(0, n - 1, l, r, 0);
    }

    // Update value at x to y
    void update(int x, int y)
    {
        update(0, n - 1, 0, x, y);
    }
};

void SegmentTree::build(int start, int end, int node, vector<int> &v)
{
    // base case - leaf node
    if (start == end)
    {
        st[node] = v[start];
        return;
    }

    int mid = (start + end) / 2;

    // left subtree is (start, mid)
    build(start, mid, 2 * node + 1, v);

    // right subtree is (mid+1, end)
    build(mid + 1, end, 2 * node + 2, v);

    st[node] = st[2 * node + 1] + st[2 * node + 2];
}

int SegmentTree::query(int start, int end, int l, int r, int node)
{
    // non overlapping node
    if (start > r || end < l)
    {
        return 0;
    }

    // complete overlap
    if (start == l && end == r)
    {
        return st[node];
    }

    // partial case
    int mid = (start + end) / 2;

    int q1 = query(start, mid, l, r, 2 * node + 1);
    int q2 = query(mid + 1, end, l, r, 2 * node + 2);

    return q1 + q2;
}

void SegmentTree::update(int start, int end, int node, int index, int value)
{
    // base case
    if (start == end)
    {
        st[node] = value;
        return;
    }

    int mid = (start + end) / 2;

    // left subtree
    if (index <= mid)
    {
        update(start, mid, 2 * node + 1, index, value);
    }
    // right subtree
    else
    {
        update(mid + 1, end, 2 * node + 2, index, value);
    }

    st[node] = st[2 * node + 1] + st[2 * node + 2];
}
