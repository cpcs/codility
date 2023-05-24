// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <bits/stdc++.h>
using namespace std;

const int M = 1000000007;

void add(int &x, int y) {
    if ((x += y) >= M) {
        x -= M;
    }
}

int sub(int x, int y) {
    if ((x -= y) < 0) {
        x += M;
    }
    return x;
}

int cal(const string &s, const vector<int> &dp, int m, bool allowEqual) {
    const int n = s.length();
    int r = 0;
    bool valid = true;
    for (int i = 0, last = -1; valid && i < n; ++i) {
        if (s[i] == '1') {
            // Try changing the current bit to 0.
            if (last < 0) {
                add(r, dp[n - i - 1]);
            } else {
                valid = i - last > m;
            if (i - last >= m) {
                add(r, dp[n - i - 1]);
                } else if (last + m >= n) {
                    // All remaining bits must be 0. Now valid == false.
                    add(r, 1);
                } else {
                    // not only change this bit to 0 but also make m 0s.
                    add(r, dp[n - last - m - 1]);
                }
            }
            last = i;
        }
    }
    if (allowEqual && valid) {
        add(r, 1);
    }
    return r;
}

int solution(string &S, string &T, int K) {
    // Implement your solution here
    const int n = T.size();
    vector<int> dp(n + 1);
    // dp[i] = the number of valid integers of length n.
    for (int i = dp[0] = 1; i <= n; ++i) {
        add(dp[i] = dp[i - 1], i > K ? dp[i - K - 1] : 1);
    }
    return sub(cal(T, dp, K, true), cal(string(n - S.length(), '0') + S, dp, K, false));


}
