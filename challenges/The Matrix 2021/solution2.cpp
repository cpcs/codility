// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> &A) {
    // Implement your solution here
    stack<int> s;
    const int n = A.size();
    int r = 0;
    for (int i = 0; i < n; ++i) {
        while (!s.empty() && A[s.top()] > A[i]) {
            const int h = A[s.top()];
            s.pop();
            const int w = s.empty() ? i : (i - s.top() - 1);
            r = max(r, min(w, h));
        }
        s.push(i);
    }
    while (!s.empty()) {
        const int h = A[s.top()];
        s.pop();
        const int w = s.empty() ? n : (n - s.top() - 1);
        r = max(r, min(w, h));
    }
    return r;
}
