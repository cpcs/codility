// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <bits/stdc++.h>
using namespace std;

int lowbit(int i) {
    return i & (-i);
}

void update(vector<int> &v, int i) {
    for (; i < v.size(); i += lowbit(i)) {
        ++v[i];
    }
}

int count(const vector<int> &v, int i) {
    int r = 0;
    for (; i; i -= lowbit(i)) {
        r += v[i];
    }
    return r;
}

string solution(string &S, int K) {
    // Implement your solution here
    if (K == 0) {
        return S;
    }
    const int n = S.length();
    vector<vector<int>> v(26);
    for (int i = 0; i < n; ++i) {
        v[S[i] - 'a'].push_back(i);
    }
    vector<int> p(n + 1), ind(26);
    string r;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 26; ++j) {
            if (ind[j] >= v[j].size()) {
                continue;
            }
            const int x = v[j][ind[j]];
            const int temp = count(p, x);
            if (x - temp <= K) {
                ++ind[j];
                K -= x - temp;
                r.push_back(S[x]);
                update(p, x + 1);
                break;
            }
        }
    }
    return r;
}
