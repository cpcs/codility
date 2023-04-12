// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> &A, vector<int> &B) {
    // Implement your solution here
    const int n = A.size();
    int r = 0;
    unordered_map<int, int> have;
    for (int i = 0; i < n; ++i) {
        r = max(r, ++have[A[i]]);
        if (A[i] != B[i]) {
            r = max(r, ++have[B[i]]);
        }
    }
    return r;
}
