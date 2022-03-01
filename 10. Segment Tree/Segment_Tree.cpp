/*

SEGMENT TREE (with lazy propagation)
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
    // segment tree and lazy tree
    vector<int> st, lazy;

    // overloaded functions
    void build(vector<int> &, int, int, int);
    int query(int, int, int, int, int);
    void update(int, int, int, int, int, int);

public:
    SegmentTree(int n)
    {
        this->n = n;
        st.resize(4 * n, 0);
        lazy.resize(4 * n, 0);
    }

    // Build the segment tree
    void build(vector<int> &v)
    {
        build(v, 0, n - 1, 0);
    }

    // Query for the range l to r
    int query(int l, int r)
    {
        return query(0, n - 1, l, r, 0);
    }

    // Update value at x to y
    void update(int l, int r, int x)
    {
        update(0, n - 1, 0, l, r, x);
    }
};

void SegmentTree::build(vector<int> &v, int start, int end, int node)
{
    // base case - leaf node
    if (start == end)
    {
        st[node] = v[start];
        return;
    }

    int mid = (start + end) / 2;

    // left subtree is (start, mid)
    build(v, start, mid, 2 * node + 1);

    // right subtree is (mid+1, end)
    build(v, mid + 1, end, 2 * node + 2);

    st[node] = st[2 * node + 1] + st[2 * node + 2];
}

int SegmentTree::query(int start, int end, int l, int r, int node)
{
    // non overlapping node
    if (start > r || end < l)
    {
        return 0;
    }

    // lazy propagation
    if (lazy[node] != 0)
    {
        // update the segment tree node
        st[node] = lazy[node] * (end - start + 1);
        if (start != end)
        {
            // propagate tge update value
            lazy[2 * node + 1] += lazy[node];
            lazy[2 * node + 2] += lazy[node];
        }
        lazy[node] = 0;
    }

    // complete overlap
    if (start >= l && end <= r)
    {
        return st[node];
    }

    // partial case
    int mid = (start + end) / 2;

    int q1 = query(start, mid, l, r, 2 * node + 1);
    int q2 = query(mid + 1, end, l, r, 2 * node + 2);

    return q1 + q2;
}

void SegmentTree::update(int start, int end, int node, int l, int r, int value)
{
    // non-overlapping case
    if (start > r || end < l)
    {
        return;
    }

    // lazy propagation
    // clear the lazy update
    if (lazy[node] != 0)
    {
        // update the segment tree node
        st[node] += lazy[node] * (end - start + 1);
        if (start != end)
        {
            // propagate the updated value
            lazy[2 * node + 1] += lazy[node];
            lazy[2 * node + 2] += lazy[node];
        }
        lazy[node] = 0;
    }

    // complete overlap
    if (start >= l && end <= r)
    {
        st[node] += value * (end - start + 1);
        if (start != end)
        {
            lazy[2 * node + 1] += value;
            lazy[2 * node + 2] += value;
        }
        return;
    }

    // partial case
    int mid = (start + end) / 2;

    update(start, mid, 2 * node + 1, l, r, value);

    update(mid + 1, end, 2 * node + 2, l, r, value);

    st[node] = st[2 * node + 1] + st[2 * node + 2];
}
