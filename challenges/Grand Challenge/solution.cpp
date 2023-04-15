// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <bits/stdc++.h>
using namespace std;

int solution(string &S) {
    // Implement your solution here
    unordered_map<int, int> have;
    have[0] = 0;
    char x = S[0], y = '?';
    int r = 0;
    for (int i = 0, sum = 0, valid = 0, start = 0, len = 0; i < S.length(); ++i) {
        if (S[i] == x) {
            ++sum;
        } else if (y == '?' || y == S[i]) {
            y = S[i];
            --sum;
        } else {
            valid = i;
            len = i - start;
            sum = 1;
            x = S[i];
            y = S[start];
        }
        if (S[start] != S[i]) {
            start = i;
        }
        if (sum >= 0 && sum <= len) {
            r = max(r, i - valid + 1 + sum);
        } else if (have.count(sum) && have[sum] >= valid) {
            r = max(r, i + 1 - have[sum]);
        } else {
            have[sum] = i + 1;
        }
    }
    return r;
}
