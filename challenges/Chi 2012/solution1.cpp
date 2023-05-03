// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> &A, vector<int> &B) {
    // Implement your solution here
    if (A.empty() || B.empty()) {
        return A;
    }
    map<int, int> have;
    have[A[0]] = 0;
    const int m = A.size();
    for (int i = 1, last = A[0]; i < m; ++i) {
        if (A[i] > last) {
            have[last = A[i]] = i;
        }
    }
    for (int x : B) {
        auto t = have.lower_bound(x);
        if (t == have.end() || t->second == 0) {
            continue;
        }
        const int ind = t->second - 1;
        ++A[ind];
        t = have.lower_bound(A[ind]);
        if (t != have.end() && t->second <= ind) {
            continue;
        }
        have[A[ind]] = ind;
    }
    return A;
}
