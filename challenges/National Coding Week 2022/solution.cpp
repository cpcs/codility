// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <bits/stdc++.h>
using namespace std;

int dfs(int x, int f, const vector<vector<int>> &con, vector<vector<int>> &dp) {
    dp[x][0] = 1;
    int r = 0;
    for (int y : con[x]) {
        if (y != f) {
            r += dfs(y, x, con, dp);
            r += dp[y][0] * dp[x][0] + dp[y][1] * dp[x][1];
            dp[x][1] += dp[y][0];
            dp[x][0] += dp[y][1];
        }
    }
    return r;
}

int solution(vector<int> &A, vector<int> &B) {
    // Implement your solution here
    const int n = A.size();
    vector<vector<int>> con(n + 1);
    for (int i = 0; i < n; ++i) {
        con[A[i]].push_back(B[i]);
        con[B[i]].push_back(A[i]);
    }
    vector<vector<int>> dp(n + 1, vector<int>(2));
    return dfs(0, -1, con, dp); 
}
