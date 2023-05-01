// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <bits/stdc++.h>
using namespace std;

int solution(string &S) {
    // Implement your solution here
    const int n = S.length(), m = 1000000000;
    vector<int> z(n), p(n + 1);
    for (int i = 1, left = 0, right = 0; i < n; ++i) {
        if (i <= right && z[i - left] < right - i + 1) {
            z[i] = z[i - left];
        } else {
            for (z[i] = max(0, right - i + 1); i + z[i] < n && S[z[i]] == S[z[i] + i]; ++z[i])
            ;
        }
        if (i + z[i] - 1 > right) {
            right = i + z[i] - 1;
            left = i;
        }
        if (z[i]) {
            ++p[1];
            --p[z[i] + 1];
        }
    }
    int r = n;
    for (int i = p[0] = 1; i <= n; ++i) {
        p[i] += p[i - 1];
        if ((m + i - 1) / i <= p[i]) {
            return m;
        }
        r = max(r, p[i] * i);
    }
    return r;
}
