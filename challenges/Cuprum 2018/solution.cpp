// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <bits/stdc++.h>
using namespace std;

int change(char c) {
    return isdigit(c) ? (c - '0') : (c - 'a' + 10);
}

int solution(string &S) {
    // Implement your solution here
    unordered_map<long long, int> have;
    have[0] = 0;
    long long s = 0;
    int r = 0;
    for (int i = 1; i <= S.length(); ++i) {
        s ^= 1LL << change(S[i - 1]);
        if (have.count(s)) {
            r = max(r, i - have[s]);
        } else {
            have[s] = i;
        }
    }
    return r;
}
