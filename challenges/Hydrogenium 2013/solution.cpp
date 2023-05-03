// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> &A, vector<int> &B, vector<int> &C, vector<int> &D) {
    // Implement your solution here
    const int n = D.size();
    vector<vector<pair<int, int>>> con(n);
    for (int i = 0; i < A.size(); ++i) {
        con[A[i]].push_back({B[i], C[i]});
        con[B[i]].push_back({A[i], C[i]});
    }
    vector<int> d(n, -1);
    d[0] = 0;
    unordered_set<int> have;
    priority_queue<pair<int, int>> q;
    q.push({0, 0});
    while (!q.empty()) {
        const int x = q.top().second;
        q.pop();
        if (have.count(x)) {
            continue;
        }
        if (D[x] >= d[x]) {
            return d[x];
        }
        for (const auto& p : con[x]) {
            const int may = p.second + d[x];
            if (d[p.first] < 0 || d[p.first] > may) {
                d[p.first] = may;
                q.push({-may, p.first});
            }
        }
    }
    return -1;
}
