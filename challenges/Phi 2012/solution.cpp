// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <bits/stdc++.h>
using namespace std;

const int M = 10000007;

void add(int &x, int y) {
    if ((x += y) >= M) {
        x -= M;
    }
}

int mul(long long x, long long y) {
    return x * y % M;
}

vector<vector<int>> mul(const vector<vector<int>> &a, const vector<vector<int>> &b) {
    const int m = a.size(), n = b.size(), p = b[0].size();
    vector<vector<int>> r(m, vector<int>(p));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < p; ++k) {
                add(r[i][k], mul(a[i][j], b[j][k]));
            }
        }
    }
    return r;
}

void dfs(int last, int now, int col, int n, vector<vector<int>> &a) {
    if (col >= n) {
        ++a[last][now];
        return;
    }
    // We can always use 1 * 1 to cover last row (or we don't need to cover it at all)
    dfs(last, now, col + 1, n, a);
    if ((last & (1 << col)) == 0 && (col + 1 < n) && (last & (1 << (col + 1))) == 0) {
        dfs(last, now | (3 << col), col + 2, n, a);
    }
}

int solution(int N, int M) {
    if (N == 1 || M == 1) {
        return 1;
    }
    const int n = 1 << M;
    vector<vector<int>> m(n, vector<int>(n)), r = m;
    for (int i = 0; i < n; ++i) {
        dfs(i, 0, 0, M, m);
        r[i][i] = 1;
    }
    for (; N; N >>= 1) {
        if (N & 1) {
            r = mul(r, m);
        }
        m = mul(m, m);
    }
    return r[0][0];
}
