// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <bits/stdc++.h>
using namespace std;

void addNodesToBoundary(int x, int f, const vector<int> &D, const vector<vector<int>> &con, unordered_map<int, unordered_set<int>> &boundary) {
    for (int y : con[x]) {
        if (y != f) {
            boundary[D[y]].insert(y);
        }
    }
}

int dfs(int x, int f, int m, const vector<int> &D,
const vector<vector<int>> &con, vector<int> &p, bool maxOnly = false) {
    if (maxOnly && D[x] < D[m]) {
        return 0;
    }
    int r = 1;
    p[x] = f;
    for (int y : con[x]) {
        if (y != f) {
            r += dfs(y, x, m, D, con, p, maxOnly);
        }
    }
    return r;
}

int solution(int K, vector<int> &C, vector<int> &D) {
    // Implement your solution here
    const int n = C.size();
    if (K == 1 || K == n) {
        return K;
    }
    // The node with maximum weight.
    int m = 0;
    vector<vector<int>> con(n);
    for (int i = 0; i < n; ++i) {
        if (D[i] > D[m]) {
            m = i;
        }
        if (C[i] != i) {
            con[i].push_back(C[i]);
            con[C[i]].push_back(i);
        }
    }
    vector<bool> mark(n);
    vector<int> p(n), ind(n);
    int r = 0;
    set<pair<int, int>> unselected = {{INT_MIN, -1}};
    for (int i = 0; i < n; ++i) {
        if (!mark[i] && D[i] == D[m]) {
            mark[i] = true;
            r = max(r, min(K, dfs(i, -1, m, D, con, p, true)));
            if (r == K) {
                return K;
            }
        }
        ind[i] = i;
        if (i != m) {
            unselected.insert({D[i], i});
        }
    }
    dfs(m, -1, m, D, con, p);
    unordered_map<int, unordered_set<int>> boundary;
    // These are the candidates one step away from the tree.
    addNodesToBoundary(m, -1, D, con, boundary);
    sort(ind.begin(), ind.end(), [&](const int x, const int y) {
        return D[x] > D[y];
    });
    set<pair<int, int>> selected = {{D[m], m}};
    for (int i = 0; i < n && r < K && selected.size() <= K; ++i) {
        if (boundary.count(D[ind[i]])) {
            auto& temp = boundary[D[ind[i]]];
            while (!temp.empty() && selected.size() < K) {
                const int node = *temp.begin();
                boundary[D[ind[i]]].erase(temp.begin());
                // It may be already in the tree since we didn't delete nodes 
                // when add one up to root.
                if (selected.insert({D[node], node}).second) {
                    addNodesToBoundary(node, p[node], D, con, boundary);
                    unselected.erase({D[node], node});
                }
            }
            if (temp.empty()) {
                boundary.erase(D[ind[i]]);
            }
        }
        if (selected.begin()->first >= unselected.rbegin()->first) {
             r = max(r, (int) selected.size());
        }
        if (selected.size() < K && !selected.count({D[ind[i]], ind[i]})) {
            for (int j = ind[i]; j >= 0 && !selected.count({D[j], j}); j = p[j]) {
                addNodesToBoundary(j, p[j], D, con, boundary);
                selected.insert({D[j], j});
                unselected.erase({D[j], j});
            } 
        }
        if (selected.size() <=K && selected.begin()->first >= unselected.rbegin()->first) {
             r = max(r, (int) selected.size());
        }
    }
    return r;
}
