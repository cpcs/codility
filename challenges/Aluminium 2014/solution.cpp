// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <bits/stdc++.h>
using namespace std;

int run(const vector<int> &a) {
      // Implement your solution here
    const int n = a.size();
    vector<int> bestMissing(n);
    int r = a[0];
    for (int i = 1, normalEnding = a[0], missingEnding = 0; i < n; ++i) {
        missingEnding = max(max(missingEnding + a[i], normalEnding), 0);
        bestMissing[i] = max(bestMissing[i - 1], missingEnding);
        normalEnding = max(normalEnding + a[i], a[i]);
        r = max(r, normalEnding);
    }
    for (int i = n - 1, m = INT_MIN; i; --i) {
        m = max(m, a[i]);
        r = max(r, bestMissing[i - 1] + m);
    }
    return r;
}

int solution(vector<int> &A) {
    int r = run(A);
    reverse(A.begin(), A.end());
    return max(r, run(A));
}
