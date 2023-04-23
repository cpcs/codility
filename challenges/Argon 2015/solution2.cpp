// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> &A) {
    // Implement your solution here
    const int n = A.size();
    // If valid, the sum must be 1 or include all the numbers.
    unordered_map<int, int> have;
    have[0] = 0;
    vector<int> ans(n);
    for (int i = 0, s = 0; i < n; ++i) {
        s += A[i] == 0 ? 1 : -1;
        if (s > 0) {
            ans[i] = i + 1;
        } else {
            ans[i] = i ? ans[i - 1] : 0;
            if (have.count(s - 1)) {
                ans[i] = max(ans[i], i + 1 - have[s - 1]);
            }
        }
        if (!have.count(s)) {
            have[s] = i + 1;
        }
    }
    have.clear();
    have[0] = n;
    int r = 0;
    for (int i = n - 1, s = 0; i; --i) {
        s += A[i] == 1 ? 1 : -1;
        int temp = 0;
        if (s > 0) {
            temp = n - i;
        } else if (have.count(s - 1)) {
            temp = have[s - 1] - i;
        }
        if (temp && ans[i - 1]) {
            r = max(r, temp + ans[i - 1]);
        }
        if (!have.count(s)) {
            have[s] = i;
        }
    }
    return r;
}
