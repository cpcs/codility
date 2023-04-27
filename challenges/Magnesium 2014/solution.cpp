// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <bits/stdc++.h>
using namespace std;

int solution(int N, vector<int> &A, vector<int> &B, vector<int> &C) {
    // Implement your solution here
    vector<int> dp(N);
    vector<vector<int>> e;
    const int m = A.size();
    for (int i = 0; i < m; ++i) {
        e.push_back({C[i], A[i], B[i]});
    }
    sort(e.begin(), e.end());
    for (int i = 0; i < m;) {
        vector<vector<int>> temp;
        for (const int j = i; i < m && e[j][0] == e[i][0]; ++i) {
            temp.push_back({e[i][1], dp[e[i][2]] + 1});
            temp.push_back({e[i][2], dp[e[i][1]] + 1});
        }
        for (const auto& v : temp) {
            dp[v[0]] = max(dp[v[0]], v[1]);
        }
    }
    return *max_element(dp.begin(), dp.end());
}
