// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> &A, vector<int> &B) {
    // Implement your solution here
    int ma = 0, mb = 0;
    const int n = A.size(), m = B.size();
    unordered_map<int, vector<int>> amap, bmap;
    for (int i = 0; i < n; ++i) {
        amap[A[i]].push_back(i + 1);
        ma = max(ma, A[i]);
    }
    for (int i = 0; i < m; ++i) {
        bmap[B[i]].push_back(i);
        mb = max(mb, B[i]);
    }
    vector<int> r(m);
    unordered_set<int> water = {0, n + 1};
    for (int i = 0, num = 1; i <= ma || i <= mb; ++i) {
        if (amap.count(i)) {
            for (int x : amap[i]) {
                num += 1 - water.count(x - 1) - water.count(x + 1);
                water.insert(x);
            }
        }
        if (bmap.count(i)) {
            for (int x : bmap[i]) {
                r[x] = num;
            }
        }
    }
    return r;
}w
