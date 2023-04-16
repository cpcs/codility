// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <bits/stdc++.h>
using namespace std;

int solution(vector< vector<int> > &A) {
    // Implement your solution here
    const int n = A.size();
    // minimum number of 2 and 5.
    vector<vector<int>> dp(n, vector<int>(2, INT_MAX));
    bool z = false;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            vector<int> v(2);
            if (A[i][j] == 0) {
                v[0] = v[1] = 1;
                z = true;
            } else {
                for (int x = A[i][j]; (x & 1) == 0; x >>= 1, ++v[0])
                ;
                for (int x = A[i][j]; x % 5 == 0; x /= 5, ++v[1]);
            }
            if (i == 0 && j == 0) {
                dp[j] = v;
                continue;
            }
            int dp2 = dp[j][0], dp5 = dp[j][1];
            if (j) {
                dp2 = min(dp2, dp[j - 1][0]);
                dp5 = min(dp5, dp[j - 1][1]);
            }
            dp[j] = {dp2 + v[0], dp5 + v[1]};
        }
    }
    const int r = min(dp[n - 1][0], dp[n - 1][1]);
    return z ? min(r, 1) : r;
}
