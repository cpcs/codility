// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <bits/stdc++.h>
using namespace std;

// Current position is i, assume current value is d >= 0.
// All prefix sums for positions > i (after changing) are non negative.
int cal(const vector<int> &p, unordered_map<int, int> &last, int i, int d, int k) {
    const int n = p.size() - 1, s = p[n] - p[i] + d;
    const int want = (min(s >> 1, k) << 1) - d + p[i];
    // It should be there since prefix sum is consecutive, but want == 0 is special.
    // Also note that we don't check the case here to make the prefix sum == 1
    // and remove a bracket finally since we have the reverse call later.
    return last.count(want) ? last[want] : (-1);
}

int run(string &S, int K) {
    const int n = S.length();
    vector<int> p(n + 1);
    for (int i = 1; i <= n; ++i) {
        p[i] = p[i - 1] + (S[i - 1] == '(' ? 1 : -1);
    }
    unordered_map<int, int> last;
    int r = 0;
    for (int i = n, m = n; i; --i) {
        if (!last.count(p[i])) {
            last[p[i]] = i;
        }
        if (p[m] > p[i]) {
            m = i;
        }
        // minimum prefix sum is negative. Note although we find the last minimum
        // prefix sum. The elements to be changed should be done from the beginning.
        if (p[m] < p[i - 1]) {
            const int num = (p[i - 1] - p[m] + 1) >> 1;
            // We cannot change the minimum prefix sum into positive, it will be
            // handled by the reverse call.
            // In theory we should find another prefix sum here. However, if
            // it's not minimum, it's difficult to find the correct one in 
            // linear time.
            if (num > K) {
                continue;
            }
            r = max(r, cal(p, last, m, (p[i - 1] - p[m]) & 1, K - num) - i + 1);
        } else {
            // minimum prefix sum is non negative.
            r = max(r, cal(p, last, m, p[m] - p[i - 1], K) - i + 1);
        }
    }
    return r;
}

int solution(string &S, int K) {
    int r = run(S, K);
    for (char& c : S) {
        if (c == '(') {
            c = ')';
        } else {
            c = '(';
        }
    }
    reverse(S.begin(), S.end());
    return max(r, run(S, K));
}
