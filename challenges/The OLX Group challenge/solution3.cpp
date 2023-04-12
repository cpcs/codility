// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> &juice, vector<int> &capacity) {
    // Implement your solution here
    const int n = juice.size();
    vector<int> ind(n);
    for (int i = 0; i < n; ++i) {
        ind[i] = i;
    }
    sort(ind.begin(), ind.end(), [&](const int x, const int y) {
        return juice[x] < juice[y];
    });
    long long s = 0;
    int r = 0;
    for (int c = 0, i = 0; i < n; ++i) {
        s += juice[ind[i]];
        c = max(c, capacity[ind[r]]);
        if (c >= s) {
            r = i;
        }
    }
    s = 0;
    for (int i = 0; i <= r; ++i) {
        s += juice[ind[i]];
    }
    map<int, int> d;
    for (int i = ++r; i < n; ++i) {
        ++d[capacity[ind[i]] - juice[ind[i]]];
    }
    for (; r < n && !d.empty() && d.rbegin()->first >= s; ++r) {
        s += juice[ind[r]];
        const int temp = capacity[ind[r]] - juice[ind[r]];
        if (--d[temp] == 0) {
            d.erase(temp);
        }
    }
    return r;
}
