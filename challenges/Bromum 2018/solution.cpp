// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <bits/stdc++.h>
using namespace std;

int solution(int N, int Q, vector<int> &B, vector<int> &C) {
    // Implement your solution here
    vector<unordered_map<int,int>> v(N);
    for (int i = 0; i < B.size(); ++i) {
        if (++v[B[i]][C[i]] >= Q) {
            return i;
        }
    }
    return -1;
}
