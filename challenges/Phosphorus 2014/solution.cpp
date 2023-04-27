// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <bits/stdc++.h>
using namespace std;

void better(int &x, int y) {
    if ((y >= 0) && (x < 0 || x > y)) {
        x = y;
    }
}

void dfs(const vector<vector<int>> &con, int x, int f, 
const unordered_set<int> &g, vector<vector<int>> &dp) {
    const bool have = g.count(x);
    if (con[x].size() == 1) {
        dp[x][0] = 1;
        dp[x][1] = 0;
        return;
    }
    dp[x][0] = dp[x][1] = dp[x][2] = 0;
    int sum = 1;
    for (int y : con[x]) {
        if (y != f) {
            dfs(con, y, x, g, dp);
            int v = -1;
            vector<int> temp(3, -1);
            for (int i = 0; i < 3; ++i) {
                if (dp[y][i] < 0) {
                    continue;
                }
                better(v, dp[y][i]);
                for (int j = 0; j < 3; ++j) {
                    if (dp[x][j] < 0) {
                        continue;
                    }
                    const int state = i | j | (have << 1);
                    if (state < 3) {
                        better(temp[state], dp[y][i] + dp[x][j]);
                    }
                }
            }
            // It must have solution since we can put guards on all the leaves.
            sum += v;
            dp[x] = temp;
        }
    }
    if (!have) {
        better(dp[x][0], sum);
    }
}

int solution(vector<int> &A, vector<int> &B, vector<int> &C) {
    // Implement your solution here
    const int n = A.size() + 1;
    vector<vector<int>> con(n);
    for (int i = 0; i + 1 < n; ++i) {
        con[A[i]].push_back(B[i]);
        con[B[i]].push_back(A[i]);
    }
    if (C.empty()) {
        return 0;
    }
    for (int x : C) {
        if (con[x].size() == 1) {
            return -1;
        }
    }
    unordered_set<int> g(C.begin(), C.end());
    // dp[n][0] For the subtree rooted at n which is controlled, nobody can reach
    // the root and there is no path from root to a leaf.
    // dp[n][1] For the subtree rooted at n which is controlled, nobody can reach
    // the root and there is a path from root to a leaf.
    // dp[n][2] or the subtree rooted at n which is controlled, there is at least
    // one prisoner can reach the root. (So there is no way to reach a leaf).
    vector<vector<int>> dp(n, vector<int>(3, -1));
    dfs(con, C[0], -1, g, dp);
    int r = dp[C[0]][0];
    better(r, dp[C[0]][1]);
    better(r, dp[C[0]][2]);
    return r;
}
