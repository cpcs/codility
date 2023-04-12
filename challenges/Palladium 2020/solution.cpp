// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> &H) {
    // Implement your solution here
    const int n = H.size();
    vector<int> p(n + 1);
    for (int i = n - 1; i >= 0; --i) {
        p[i] = max(H[i], p[i + 1]);
    }
    int r = INT_MAX;
    for (int i = 0, m = 0; i < n; ++i) {
        m = max(m, H[i]);
        r = min(r, m * (i + 1) + p[i + 1] * (n - i - 1));
    }
    return r;
}
