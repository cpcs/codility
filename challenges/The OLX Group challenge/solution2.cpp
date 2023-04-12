// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> &juice, vector<int> &capacity) {
    // Implement your solution here
    const int n = juice.size();
    vector<int> ind1(n), ind2(n);
    for (int i = 0; i < n; ++i) {
        ind1[i] = ind2[i] = i;
    }
    sort(ind1.begin(), ind1.end(), [&](const int x, const int y) {
        return juice[x] < juice[y];
    });
    sort(ind2.begin(), ind2.end(), [&](const int x, const int y) {
        return capacity[ind1[x]] - juice[ind1[x]] > capacity[ind1[y]] - juice[ind1[y]];
    });
    int r = 0;
    for (int i = 0, j = 0, s = 0, c = 0; i < n; ++i) {
        for (; j < n && ind2[j] <= i; ++j)
        ;
        s += juice[ind1[i]];
        c = max(c, capacity[ind1[i]]);
        // We want to have juice ind1[0..i], can we find another 
        // glass outside the range to hold it?
        if (j < n && capacity[ind1[ind2[j]]] - juice[ind1[ind2[j]]] >= s) {
            r = i + 2;
        } else if (c >= s) {
            r = i + 1;
        } else {
            break;
        }
    }
    return r;
}
