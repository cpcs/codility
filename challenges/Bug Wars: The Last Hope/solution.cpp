// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A, vector<int> &X) {
    // Implement your solution here
    const int n = A.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    for (int i = 0; i < n; ++i) {
        dp[i][i] = A[i];
    }
    int r = 0;
    // dp[x][y], one side stops at x and the other side reache y.
    for (int d = 0; d < n; ++d) {
        for (int i = 0; i + d < n; ++i) {
            const int j = i + d;
            if (i && dp[i][j] >= X[i] - X[i - 1]) {
                dp[i - 1][j] = max(dp[i - 1][j], dp[i][j] - (X[i] - X[i - 1]) 
                + A[i - 1]);
                r = d + 1;
            }
            if (j + 1 < n && dp[i][j] >= X[j + 1] - X[i]) {
                dp[j + 1][i] = max(dp[j + 1][i], dp[i][j] - (X[j + 1] - X[i]) + A[j + 1]);
                r = d + 1;
            }
            if (j + 1 < n && dp[j][i] >= X[j + 1] - X[j]) {
                dp[j + 1][i] = max(dp[j + 1][i], dp[j][i] - (X[j + 1] - X[j]) + A[j + 1]);
                r = d + 1;
            }
            if (i && dp[j][i] >= X[j] - X[i - 1]) {
                dp[i - 1][j] = max(dp[i - 1][j], dp[j][i] - (X[j] - X[i - 1]) + A[i - 1]);
                r = d + 1;
            }
        }
    }
    return r + 1;
}
