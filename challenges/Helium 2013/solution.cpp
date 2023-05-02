// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <bits/stdc++.h>
using namespace std;

int solution(string &S) {
    // Implement your solution here
    const int n = S.length();
    if (n < 3) {
        return 0;
    }
    vector<int> z(n);
    for (int i = 1, left = 0, right = 0; i < n; ++i) {
        if (i <= right && z[i - left] <= right - i) {
            z[i] = z[i - left];
        } else {
            for (z[i] = max(0, right - i + 1); i + z[i] < n && S[i + z[i]] == S[z[i]]; ++z[i])
        ;  
        }
        if (i + z[i] - 1 > right) {
            left = i;
            right = i + z[i] - 1;
        }
    }
    // max(z[len], z[len + 1], ...z[n - len * 2] >= len)

    int len = n / 3, a = len, b = n - len - len, m = 0;
    for (int i = a; i <= b; ++i) {
        m = max(m, z[i]);
    }
    for (; len && (m < len || z[n - len] < len); --len) {
        m = max(m, z[--a]);
        m = max(m, z[++b]);
        m = max(m, z[++b]);
    }
    return len;
}
