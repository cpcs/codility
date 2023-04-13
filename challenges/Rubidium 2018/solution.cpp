// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> &X, vector<int> &Y) {
    // Implement your solution here
    const int n = X.size();
    vector<int> ind(n);
    int m = 0;
    for (int i = 0; i < n; ++i) {
        ind[i] = i;
        m = max(m, max(X[i], Y[i]));
    }
    sort(ind.begin(), ind.end(), [&](const int x, const int y) {
        return X[x] < X[y];
    });
    int left = 1, right = m;
    while (left <= right) {
        const int mid = (left + right) >> 1, threshold = mid << 1;
        map<int, int> have;
        bool mark = false;
        for (int i = 0, p = 0, q = 0; !mark && i < n; ++i) {
            for (; q < n && X[ind[q]] < X[ind[i]] + threshold; ++q) {
                ++have[Y[ind[q]]];
            }
            for (; p < q && X[ind[p]] <= X[ind[i]] - threshold; ++p) {
                if (--have[Y[ind[p]]] == 0) {
                    have.erase(Y[ind[p]]);
                }
            }
            if (i >= p && i < q) {
                if (--have[Y[ind[i]]] == 0) {
                    have.erase(Y[ind[i]]);
                }
            }
            const auto t = have.upper_bound(Y[ind[i]] - threshold);
            mark = t != have.end() && t->first < Y[ind[i]] + threshold;
            if (i >= p && i < q) {
                ++have[Y[ind[i]]];
            }
        }
        if (mark) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return left - 1;
}
