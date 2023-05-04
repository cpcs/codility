// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <bits/stdc++.h>
using namespace std;


vector<int> solution(vector<int> &A, vector<int> &B) {
    if (A.empty() || B.empty()) {
        return A;
    }
    const int h = *max_element(B.begin(), B.end()), m = A.size();
    vector<int> ind(h + 1);
    for (int i = 0, j = 0; i <= h; ++i) {
        for (; j < m && A[j] < i; ++j)
        ;
        ind[i] = j;
    }
    for (int x : B) {
        if (ind[x] > 0 && ind[x] < m) {
            const int y = ind[x] - 1;
            // This is the same as ind[++A[y]] > y.
            if (ind[++A[y]] == ind[x]) {
                ind[A[y]] = y;
            }
        }
    }
    return A;
}
