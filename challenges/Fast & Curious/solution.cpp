// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> &A) {
    // Implement your solution here
    sort(A.begin(), A.end());
    const int n = A.size();
    long long s = 0;
    for (int i = 0; i + 1 < n; ++i) {
        s += A[i];
    }
    long long t = 0, r = 1LL << 62;
    for (int i = n - 2; i >= 0; --i) {
        r = min(r, (i + 1LL) * A[i] - s + t);
        s -= A[i];
        t += A[n - 1] - A[i];
    }
    return r % 1000000007;
}
