// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <bits/stdc++.h>
using namespace std;

int cal(const vector<int> &a, int x1, int y1, const vector<int> &b, int x2, int y2) {
    const int n1 = y1 - x1 + 1, n2 = y2 - x2 + 1;
    if (n1 > n2) {
        return cal(b, x2, y2, a, x1, y1);
    }
    for (int left = 0, right = n1; left <= right; ) {
        const int cut1 = (left + right) >> 1, cut2 = ((n1 + n2 + 1) >> 1) - cut1;
        const int left1 = cut1 ? a[x1 + cut1 - 1] : INT_MIN;
        const int right1 = cut1 == n1 ? INT_MAX : a[x1 + cut1];
        const int left2 = cut2 ? b[x2 + cut2 - 1] : INT_MIN;
        const int right2 = cut2 == n2 ? INT_MAX : b[x2 + cut2];
        if (left1 <= right2 && left2 <= right1) {
            return max(left1, left2);
        }
        if (left1 > right2) {
            right = cut1 - 1;
        } else {
            left = cut1 + 1;
        }
    }
    return 0;
}

int dfs(vector<int> &a, int from, int to, int k) {
    if (from == to) {
        return a[from];
    }
    int left = from, right = to - 1;
    while (left <= right) {
        for (; left <= right && a[left] < a[to]; ++left)
        ;
        for (; left <= right && a[right] > a[to]; --right)
        ;
        if (left <= right) {
            swap(a[left++], a[right--]);
        }
    }
    swap(a[left], a[to]);
    if (left - from == k) {
        return a[left];
    }
    if (left - from > k) {
        return dfs(a, from, left - 1, k);
    }
    return dfs(a, left + 1, to, k - left - 1 + from);
}

int solution(vector<int> &A, vector<int> &B, vector<int> &P, vector<int> &Q, vector<int> &R, vector<int> &S) {
    // Implement your solution here
    const int k = P.size();
    vector<int> a(k);
    for (int i = 0; i < k; ++i) {
        a[i] = cal(A, P[i], Q[i], B, R[i], S[i]);
    }
    return dfs(a,  0, k - 1, k >> 1);
}
