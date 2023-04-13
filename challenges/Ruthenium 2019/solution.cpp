// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> &A, int K) {
    // Implement your solution here
    const int n = A.size();
    unordered_map<int, vector<pair<int, int>>> have;
    unordered_map<int, int> num;
    int m = 0;
    for (int i = 0; i < n;) {
        const int j = i;
        for (; i < n && A[j] == A[i]; ++i)
        ;
        have[A[j]].push_back({j, i - 1});
        m = max(m, num[A[j]] += i - j);
    }
    if (m >= n - K) {
        return n;
    }
    int r = 0;
    for (const auto& p : have) {
        const auto& v = p.second;
        const int s = v.size();
        for (int i = 0, j = 1, m = K; j <= s;) {
            for (; j < s && v[j].first - v[j - 1].second - 1 <= m; ++j) {
                m -= v[j].first - v[j - 1].second - 1;
            }
            r = max(r, v[j - 1].second - v[i].first + 1 + m);
            if (++i < j) {
                m += v[i].first - v[i - 1].second - 1;
            } else {
                j = i + 1;
                m = K;
            }
        }
    }
    return r;
}
