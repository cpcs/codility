// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> &A) {
    // Implement your solution here
    unordered_map<int, int> have;
    have[0] = 0;
    const int n = A.size();
    int r = 0, s = 0;
    for (int i = 1; i <= n; ++i) {
        s += A[i - 1];
        if (have.count(s)) {
            r = max(r, i - have[s]);
        } else {
            have[s] = i;
        }
    }
    return s > 0 ? n : r;
}
