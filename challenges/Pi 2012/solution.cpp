// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <bits/stdc++.h>
using namespace std;

void better(int& x, int y) {
    if (x == 0 || x > y) {
        x = y;
    }
}

vector<int> solution(vector<int> &A) {
    // Implement your solution here
    const int n = A.size();
    vector<int> r(n);
    stack<int> s;
    for (int i = 0; i < n; ++i) {
        for (; !s.empty() && A[s.top()] < A[i]; s.pop()) {
            r[s.top()] = i - s.top();
        }
        s.push(i);
    }
    s = {};
    for (int i = 0; i < n; ++i) {
        for (; !s.empty() && A[s.top()] <= A[i]; s.pop())
        ;
        if (!s.empty()) {
            better(r[i], i - s.top());
        }
        s.push(i);
    }
    return r;
}
