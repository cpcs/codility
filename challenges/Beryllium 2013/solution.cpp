// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> &A) {
    // Implement your solution here
    const int n = A.size();
    unordered_set<int> a, b, onlya, onlyb;
    int r = 0;
    for (int i = 0, j = n - 1; i < n && j >= 0 && r < 1000000000;) {
        // same -> different.
        onlya.insert(A[i]);
        a.insert(A[i++]);
        for (; (!onlya.empty() && j >= 0) || (!onlyb.empty() && i < n);) {
            for (; !onlya.empty() && j >= 0; --j) {
               onlya.erase(A[j]);
               b.insert(A[j]);
               if (!a.count(A[j])) {
                   onlyb.insert(A[j]);
               }
            }
            for (; !onlyb.empty() && i < n; ++i) {
                onlyb.erase(A[i]);
                a.insert(A[i]);
                if (!b.count(A[i])) {
                    onlya.insert(A[i]);
                }
            }
        }
        if (!onlya.empty() || !onlyb.empty()) {
            break;
        }
        int c = 1;
        for (; i < n && a.count(A[i]); ++i, ++c)
        ;
        r += c;
        for (; j >= 0 && b.count(A[j]) && r < 1000000000; --j, r += c)
        ;
    }
    return min(r, 1000000000);
}
