// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> &A) {
    // Implement your solution here
    const int n = A.size();
    int left = 1, right = n;
    while (left <= right) {
        const int mid = (left + right) >> 1;
        deque<int> q;
        bool can = false;
        for (int i = 0; !can && i < n; ++i) {
            while (!q.empty() && A[q.back()] >= A[i]) {
                q.pop_back();
            }
            while (!q.empty() && q.front() <= i - mid) {
                q.pop_front();
            }
            q.push_back(i);
            if (i >= mid - 1 && !q.empty() && A[q.front()] >= mid) {
                can = true;
            }
        }
        if (can) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return left - 1;
}
