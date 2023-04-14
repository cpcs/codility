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
    vector<vector<int>> num(n, vector<int>(2, INT_MAX));
    // minimum number of 2 and 5 when the other one is minimum.
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
                dp[j] = num[j] = v;
                continue;
            }
            int num2 = num[j][0];
            int num5 = num[j][1];
            if (j) {
                num2 = min(num2, num[j - 1][0]);
                num5 = min(num5, num[j - 1][1]);
            }
            int dp2 = INT_MAX;
            int dp5 = INT_MAX;
            if (num2 == num[j][0]) {
                dp5 = min(dp5, dp[j][1]);
            }
            if (j && num2 == num[j - 1][0]) {
                dp5 = min(dp5, num[j - 1][1]);
            }
            if (num5 == num[j][1]) {
                dp2 = min(dp2, dp[j][0]);
            }
            if (j && num5 == num[j - 1][1]) {
                dp2 = min(dp2, num[j - 1][0]);
            }
        
            num[j] = {num2 + v[0], num5 + v[1]};
            dp[j] = {dp2 + v[0], dp5 + v[1]};
        }
    }
    const int r = min(min(dp[n - 1][0], num[n - 1][1]), min(dp[n - 1][1], num[n - 1][0]));
    return z ? min(r, 1) : r;
}

