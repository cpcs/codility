// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> &A, vector<int> &B, int F) {
    // Implement your solution here
    priority_queue<int> q;
    int s = 0;
    for (int i = 0; i < A.size(); ++i) {
        s += A[i];
        q.push(B[i] - A[i]);
        if (q.size() > F) {
            s += q.top();
            q.pop();
        }
    }
    return s;
}
