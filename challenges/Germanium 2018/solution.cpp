// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <bits/stdc++.h>
using namespace std;

vector<int> dfs(const vector<vector<int>> &con, int x, vector<bool> &mark) {
    // Return number of nodes, sum of degrees.
    vector<int> r(2);
    if (mark[x]) {
        return r;
    }
    mark[x] = true;
    r = {1, con[x].size()};
    for (int y : con[x]) {
        const auto& v = dfs(con, y, mark);
        r[0] += v[0];
        r[1] += v[1];
    }
    return r;
}

int solution(vector<int> &A, vector<int> &B) {
    // Implement your solution here
    const int n = A.size();
    vector<bool> reachable(n);
    vector<vector<int>> con(n);
    unordered_set<int> s;
    for (int i = 0; i < n; ++i) {
        const int x = max(A[i], B[i]) - 1, y = min(A[i], B[i]) - 1;
        if (y >= n) {
            continue;
        }
        reachable[y] = true;
        if (x > y && x < n) {
            con[y].push_back(x);
            con[x].push_back(y);
            reachable[x] = true;
        } else {
            con[y].push_back(y);
        }
    }
    vector<bool> mark(n);
    int r = n;
    for (int i = n - 1; i >= 0; --i) {
        if (!reachable[i]) {
            r = i;
        } else if (!mark[i]) {
            const auto& v = dfs(con, i, mark);
            // If it's a tree, make the largest number (which is i) unreachable.
            if (((v[0] - 1) << 1) == v[1]) {
                // reachable[i] = false;
                r = i;
            }
        }
    }
    return r + 1;
}
