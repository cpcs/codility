// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <bits/stdc++.h>
using namespace std;

int solution(string &S) {
    // Implement your solution here
    const int n = S.length();
    vector<int> dp(26, -1);
    int last = 0;
    for (int i = 0; i < n; ++i) {
        const int c = S[i] - 'a', temp = last++;
        if (dp[c] >= 0) {
            last = min(last, dp[c]);
            dp[c] = min(dp[c], temp);
        } else {
            dp[c] = temp;
        }
    }
    return last;
}
