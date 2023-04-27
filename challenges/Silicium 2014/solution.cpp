// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <bits/stdc++.h>
using namespace std;

int solution(int X, int Y, int K, vector<int> &A, vector<int> &B) {
    // Implement your solution here
    int last = 0;
    vector<int> a;
    for (int x : A) {
        a.push_back(x - last);
        last = x;
    }
    a.push_back(X - last);
    last = 0;
    vector<int> b;
    for (int x : B) {
        b.push_back(x - last);
        last = x;
    }
    b.push_back(Y - last);
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int left = 1, right = 100000000;
    while (left <= right) {
        const int mid = (left + right) >> 1;
        int count = 0;
        for (int i = 0, j = b.size() - 1; i < a.size() && count < K; ++i) {
            for (int t = (mid + a[i] - 1) / a[i]; j >= 0 && b[j] >= t; --j)
            ;
            count += b.size() - 1 - j;
        }
        if (count >= K) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return left - 1;
}
