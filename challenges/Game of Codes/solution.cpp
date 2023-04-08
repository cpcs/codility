// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <bits/stdc++.h>
using namespace std;

int solution(string &S) {
    // Implement your solution here
    vector<vector<int>> best(26, vector<int>(4));
    vector<int> dp(vector<int>(4));
    for (int i = S.length() - 1; i >= 0; --i) {
        const int c = S[i] - 'a';
        for (int j = 3; j; --j) {
            ++best[c][j];
            best[c][j] = max(best[c][j], dp[j - 1] + 1);
            dp[j] = max(dp[j], best[c][j]);
        }
    }
    return dp[3];
}
