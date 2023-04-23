// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> &A) {
    // Implement your solution here
    const int n = A.size();
    // best[i] is the maximum subarray ending with A[i]
    vector<int> ans(n), best(n), p(n + 1);
    for (int i = 0, length = 0; i < n; ++i) {
        p[i + 1] = p[i];
        const int x = A[i] == 0 ? 1 : -1;
        p[i + 1] += x;
        ans[i] = i ? ans[i - 1] : 0;
        best[i] = max(i ? (best[i - 1] + x) : x, x);
        for (; i >= length && best[i - length] + p[i + 1] - p[i + 1 - length] > 0; ++length)
        ;
        if (p[i + 1] > p[i + 1 - length]) {
            ans[i] = max(ans[i], length);
        }
    }
    int r = 0;
    p = vector<int>(n + 1, 0);
    for (int i = n - 1, length = 0, s = 0; i; --i) {
        const int x = A[i] == 1 ? 1 : -1;
        p[i] = p[i + 1] + x;
        best[i] = max(i + 1 < n ? (best[i + 1] + x) : x, x);
        for (; i + length < n && best[i + length] + p[i] - p[i + length] > 0; ++length)
        ;
        if (length && ans[i - 1]) {
            r = max(r, length + ans[i - 1]);
        }
    }
    return r;
}
