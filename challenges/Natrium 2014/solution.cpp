// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> &A) {
    // Implement your solution here
    const int n = A.size();
    stack<int> s;
    s.push(0);
    for (int i = 1; i < n; ++i) {
        if (A[s.top()] > A[i]) {
            s.push(i);
        }
    }
    int r = 0;
    for (int i = n - 1, last = INT_MIN; !s.empty() && i >= 0; --i) {
        while (!s.empty() && s.top() >= i) {
            s.pop();
        }
        if (A[i] > last) {
            while (!s.empty() && A[i] >= A[s.top()]) {
                r = max(r, i - s.top());
                s.pop();
            }
            last = A[i];
        }
    }
    return r;
}
