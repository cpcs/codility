// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <bits/stdc++.h>
using namespace std;

int check(vector<pair<char, int>> &v, const pair<char, int> &p) {
    if (v.empty()) {
        if (p.first != '?') {
            v = {p};
            return p.second;
        }
        return 0;
    }
    if (v.size() == 1) {
        if (p.first == '?') {
            v.push_back(p);
            return 0;
        }
        v = {p};
        return p.second;
    }
    // v.size() == 2
    const auto p1 = v[0], p2 = v[1];
    v = {p};
    if (p1.first == p.first) {
        if (p2.second & 1) {
            return p.second;
        }
        return max(p.second, 2);
    } else if ((p2.second & 1) == 0) {
        return p.second;
    } else if (p2.second > 1) {
        return max(p.second, 2);
    } else if (p.second < p1.second) {
        return ++v[0].second;
    } else {
        return max(p.second, p1.second + 1);
    }
}

int solution(string &S) {
    // Implement your solution here
    const int n = S.length();
    vector<pair<char, int>> v;
    int r = 1;
    int len = 0;
    for (int i = 0; i < n; ++i) {
        if (i && S[i] != S[i - 1]) {
            r = max(r, check(v, {S[i - 1], len}));
            len = 1;
        } else {
            ++len;
        }
    }
    return max(r, check(v, {S[n - 1], len}));
}
