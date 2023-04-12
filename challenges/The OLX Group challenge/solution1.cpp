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
    multiset<int> d;
    for (int i = 0; i < n; ++i) {
        ind[i] = i;
        d.insert(capacity[i] - juice[i]);
    }
    sort(ind.begin(), ind.end(), [&](const int x, const int y) {
        return juice[x] < juice[y];
    });
    int r = 1;
    for (int i = 0, s = 0, c = 0; i < n; ++i) {
        s += juice[ind[i]];
        c = max(c, capacity[ind[i]]);
        d.erase(d.find(capacity[ind[i]] - juice[ind[i]]));
        if (!d.empty() && *d.rbegin() >= s) {
            r = i + 2;
        } else if (c >= s) {
            r = i + 1;   
        } else {
            break;
        }
    }
    return r;
}
