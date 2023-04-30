// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <bits/stdc++.h>
using namespace std;

int solution(int K, vector<int> &A) {
    // Implement your solution here
    const int n = A.size();
    deque<int> qmin, qmax;
    int r = 0;
    for (int i = 0, j = 0; i < n; ++i) {
       for (; j < n; ++j) {
            // It's OK to insert the same j again here.
            for (;!qmin.empty() && A[qmin.back()] >= A[j]; qmin.pop_back())
            ;
            qmin.push_back(j);
            for (;!qmax.empty() && A[qmax.back()] <= A[j]; qmax.pop_back())
            ;
            qmax.push_back(j);
            if (!qmin.empty() && A[qmax.front()] - A[qmin.front()] > K) {
                break;
            }
        }
        r += j - i;
        if (r >= 1000000000) {
            return 1000000000;
        }
        for (; !qmin.empty() && qmin.front() <= i; qmin.pop_front())
        ;
        for (; !qmax.empty() && qmax.front() <= i; qmax.pop_front())
        ;
    }
    return r;

}
