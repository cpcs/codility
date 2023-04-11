// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> &A, int L, int R) {
    // Implement your solution here
    sort(A.begin(), A.end());
    int r = 0;
    for (int last = -1, i = 0; i < A.size(); ++i) {
        if (A[i] > last && A[i] < L) {
            last = A[i];
            ++r;
        } else if (A[i] > R) {
            R = A[i];
            ++r;
        }
    }
    return r;
}
