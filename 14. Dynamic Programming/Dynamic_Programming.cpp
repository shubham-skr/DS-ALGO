#include <bits/stdc++.h>
using namespace std;

void A_Frog1(vector<int> &h)
{
    int n = h.size();

    int dp[n];
    dp[0] = 0;
    dp[1] = dp[0] + abs(h[1] - h[0]);

    for (int i = 2; i < n; i++)
    {
        dp[i] = min(dp[i - 1] + abs(h[i - 1] - h[i]), dp[i - 2] + abs(h[i - 2] - h[i]));
    }

    cout << dp[n - 1] << endl;
}

void B_Frog2(vector<int> &h, int k)
{
    int n = h.size();

    int dp[n];
    dp[0] = 0;

    for (int i = 1; i < n; i++)
    {
        dp[i] = INT_MAX;

        for (int j = 1; (i - j) >= 0 && j < k; j++)
            dp[i] = min(dp[i], dp[i - j] + abs(h[i - j] - h[i]));
    }

    cout << dp[n - 1] << endl;
}

void C_Vacation(vector<vector<int>> v, int n)
{
    vector<vector<int>> dp(n, vector<int>(3, 0));

    dp[0][0] = v[0][0];
    dp[0][1] = v[0][1];
    dp[0][2] = v[0][2];

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                if (k != j)
                    dp[i][j] = max(dp[i][j], dp[i - 1][k] + v[i][j]);
            }
        }
    }

    cout << *max_element(dp[n - 1].begin(), dp[n - 1].end()) << endl;
}

void D_knapsack1(vector<int> &wt, vector<int> &val, int W)
{
    int n = wt.size();
    vector<vector<int>> dp(2, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int w = 0; w <= W; w++)
        {
            if (wt[i - 1] <= w)
            {
                dp[i % 2][w] = max(val[i - 1] + dp[(i - 1) % 2][w - wt[i - 1]], dp[(i - 1) % 2][w]);
            }
            else
            {
                dp[i % 2][w] = dp[(i - 1) % 2][w];
            }
        }
    }

    cout << dp[n % 2][W] << endl;
}

void E_knapsack2(vector<int> &wt, vector<int> &val, int W)
{
    int n = wt.size();

    vector<int> dp(100001, INT_MAX);

    for (int i = 0; i < n; i++)
    {
        for (int j = 100000; j >= val[i]; j--)
        {
            if (dp[j - val[i]] != INT_MAX && (dp[j - val[i]] + wt[i]) <= W)
                dp[j] = min(dp[j], wt[i] + dp[j - val[i]]);
        }

        dp[val[i]] = min(dp[val[i]], wt[i]);
    }

    for (int i = 100000; i >= 0; i--)
    {
        if (dp[i] != INT_MAX)
        {
            cout << i << endl;
            return;
        }
    }
}

int F_lcs(string s1, string s2, int n, int m)
{
    int dp[m + 1][n + 1]{};

    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;

            else if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;

            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    return dp[m][n];
}

int G_longestPath(vector<vector<int>> &adj, vector<int> memo, int cur)
{
    if (memo[cur] != -1)
        return memo[cur];

    int ans = -1;
    for (auto x : adj[cur])
    {
        ans = max(ans, G_longestPath(adj, memo, x)) + 1;
    }

    return ans;
}

int H_grid(vector<string> grid, int n, int m, int H, int W)
{
    int mod = 1e9 + 7;

    int dp[n][m]{};

    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            if (grid[i][j] == '#')
            {
                dp[i][j] = 0;
                continue;
            }

            if (i == 0 && j == 0)
                dp[i][j] = 1;
            else if (i == 0)
                dp[i][j] = dp[i][j - 1];
            else if (j == 0)
                dp[i][j] = dp[i - 1][j];
            else
            {
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
                dp[i][j] %= mod;
            }
        }
    }

    return dp[H - 1][W - 1];
}

double I_coins(vector<double> prob, int n)
{
    double dp[n + 1][n + 1]{}; // rows = Heads, column = Tails

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i + j > n)
                break;

            if (i == 0 && j == 0)
                dp[i][j] = 1;
            else if (i == 0)
                dp[i][j] = (1 - prob[i + j - 1]) * dp[i][j - 1];
            else if (j == 0)
                dp[i][j] = prob[i + j - 1] * dp[i - 1][j];
            else
                dp[i][j] = (1 - prob[i + j - 1]) * dp[i][j - 1] + prob[i + j - 1] * dp[i - 1][j];
        }
    }

    double ans = 0;
    for(int i = n/2+1; i <= n; i++) 
        ans += dp[i][n-i];

    return ans;
}

int main()
{
    vector<double> prob = { 0.30, 0.60, 0.80 };
    cout << I_coins(prob, 3) << endl;
}
