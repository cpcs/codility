// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <bits/stdc++.h>
using namespace std;

const int P = 10000103;
const int T = 20000208;

int mul(long long x, long long y, int m) {
    return x * y % m;
}

int pow(int x, int y, int m) {
    int r = 1;
    for (int i = y; i; i >>= 1) {
        if (i & 1) {
            r = mul(r, x, m);
        }
        x = mul(x, x, m);
    }
    return r;
}

vector<vector<int>> mul(const vector<vector<int>>  &a, vector<vector<int>> &b, int m) {
    const int n = a.size();
    vector<vector<int>> r(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int k = 0; k < n; ++k) {
            for (int j = 0; j < n; ++j) {
                r[i][j] += mul(a[i][k], b[k][j], m);
                if (r[i][j] >= m) {
                    r[i][j] -= m;
                }
            }
        }
    }
    return r;
}

vector<vector<int>> pow(const vector<vector<int>> &a, int y, int m) {
    vector<vector<int>> x = a;
    const int n = x.size();
    vector<vector<int>> r(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        r[i][i] = 1;
    }
    for (int i = y; i; i >>= 1) {
        if (i & 1) {
            r = mul(r, x, m);
        }
        x = mul(x, x, m);
    }
    return r;
}

int solution(int N, int M) {
    N = pow(N, M, T);
    if (N == 0) {
        return 0;
    }
    vector<vector<int>> a(2,vector<int>(2, 1));
    a[0][0] = 0;
    return pow(a, N, P)[1][0];
}
