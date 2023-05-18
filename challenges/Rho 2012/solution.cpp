// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <bits/stdc++.h>
using namespace std;

bool dfs(vector<int> &may, int w, int length) {
    if (may.size() > length) {
        return false;
    }
    if (may.back() == w) {
        return true;
    }
    if (may.size() == length) {
        return false;
    }
    for (int i = may.size() - 1; i >= 0; --i) {
        for (int j = i; j >= 0; --j) {
            const int x = may[i] + may[j];
            if (x > w) {
                continue;
            }
            if (x <= may.back() || x << (length - may.size() - 1) < w) {
                break;
            }
            may.push_back(x);
            if (dfs(may, w, length)) {
                return true;
            }
            may.pop_back();
        }
    }
    return false;
}

vector<int> solution(int A) {
    // Implement your solution here
    vector<int> r = {1};
    for (int length = 1; !dfs(r, A, length); ++length)
    ;
    return r;
}
