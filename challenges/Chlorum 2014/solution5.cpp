// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <bits/stdc++.h>
using namespace std;

int dfs(const vector<unordered_set<int>> &con, const vector<int> &D, vector<bool> &mark, int x, int f, int w) {
    if (D[x] < w || mark[x]) {
        return 0;
    }
    mark[x] = true;
    int r = 1;
    for (int y : con[x]) {
        if (y != f) {
            r += dfs(con, D, mark, y, x, w);
        }
    }
    return r;
}

void dfs(const vector<unordered_set<int>> &con, const vector<int> &D, vector<int> &diff, int x, int f) {
    if (f >= 0) {
        diff[x] = D[x] == D[f] ? diff[f] : D[f];
    }
    for (int y : con[x]) {
        if (y != f) {
            dfs(con, D, diff, y, x);
        }
    }
}

int solution(int K, vector<int> &C, vector<int> &D) {
    // Implement your solution here
    const int n = C.size();
    if (K == 1 || K == n) {
        return K;
    }
    vector<unordered_set<int>> con(n);
    int m = 0;
    for (int i = 0; i < n; ++i) {
        if (i != C[i]) {
            con[i].insert(C[i]);
            con[C[i]].insert(i);
        }
        if (D[m] < D[i]) {
            m = i;
        }
    }
    vector<bool> mark(n);
    int r = 0;
    for (int i = 0; i < n; ++i) {
        r = max(r, dfs(con, D, mark, i, -1, D[m]));
    }
    r = min(r, K);
    if (r == K) {
        return K;
    }
    vector<int> diff(n);
    dfs(con, D, diff, m, -1);
    set<vector<int>> leaves;
    multiset<int> remain;
    for (int i = 0; i < n; ++i) {
        if (con[i].size() == 1) {
            leaves.insert({D[i], diff[i], i});
        }
        remain.insert(D[i]);
    }
    for (int v = INT_MIN; remain.size() > K || *remain.begin() < v;) {
        const int leaf = (*leaves.begin())[2];
        v = max(v, D[leaf]);
        remain.erase(remain.find(D[leaf]));
        leaves.erase(leaves.begin());
        const int other = *con[leaf].begin();
        con[other].erase(leaf);
        if (con[other].size() == 1) {
            leaves.insert({D[other], diff[other], other});
        }
    }
    r = max(r, (int) remain.size());
    return r;
}
