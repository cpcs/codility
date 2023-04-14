// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> &A, vector<int> &B) {
    const int M = 1000000007;
    // Implement your solution here
    vector<long long> a;
    for (int x : A) {
        a.push_back(x);
    }
    const int n = a.size();
    long long r = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] == B[i]) {
            continue;
        }
        if (i + 1 >= n) {
            return -1;
        }
        const long long d = a[i] - B[i];
        r += llabs(d);
        if (i + 2 >= n) {
            a[i + 1] += d;
            continue;
        }
        if (d > 0) {
            const int temp = min(d, max(B[i + 1] - a[i + 1], 0LL));
            a[i + 1] += temp;
            a[i + 2] += d - temp;
        } else {
            const int temp = min(-d, max(a[i + 1] - B[i + 1], 0LL));
            a[i + 1] -= temp;
            a[i + 2] -= -d - temp;
        }
    }
    return r % M;
}
