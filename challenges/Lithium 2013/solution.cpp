// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <bits/stdc++.h>
using namespace std;

vector<int> make(const vector<int> &v) {
    const int n = v.size();
    int i = 0, j = 1, k = 0;
    while (i < n && j < n && k < n) {
        const int t = v[(i + k) % n] - v[(j + k) % n];
        if (t == 0) {
            ++k;
            continue;
        }
        if (t > 0) {
            i += k + 1;
        } else {
            j += k + 1;
        }
        if (i == j) {
            ++j;
        }
        k = 0;
    }
    vector<int> r(n);
    for (i = min(i, j), j = 0; j < n; ++j) {
        r[j] = v[(i + j) % n];
    }
    return r;
}

int solution(vector< vector<int> > &A, int P) {
    // Implement your solution here
    const int n = A.size(), m = A[0].size();
    if (m == 1) {
        return n * (n - 1) / 2;
    }
    map<vector<int>, int> have;
    int r = 0;
    for (auto& v : A) {
        sort(v.begin(), v.end());
        vector<int> p(m);
        for (int j = 0; j + 1 < m; ++j) {
            p[j] = v[j + 1] - v[j];
        }
        p[m - 1] = P - v[m - 1] + v[0];
        r += have[make(p)]++;
    }
    return r;
}
