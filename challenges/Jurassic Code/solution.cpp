// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> &X, vector<int> &Y, string &colors) {
    // Implement your solution here
    map<int, int> have;
    unordered_map<int, int> save;
    const int n = X.size();
    for (int i = 0; i < n; ++i) {
        const int d = X[i] * X[i] + Y[i] * Y[i];
        ++save[d];
        if (colors[i] == 'R') {
            ++have[d];
        } else {
            --have[d];
        }
    }
    int s = 0, m = 0, r = 0;
    for (const auto& p : have) {
        s += p.second;
        m += save[p.first];
        if (s == 0) {
            r = m;
        }
    }
    return r;
}
