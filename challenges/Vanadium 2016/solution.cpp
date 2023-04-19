// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <bits/stdc++.h>
using namespace std;


int solution(string &S) {
    // Implement your solution here
    vector<int> have(1024);
    have[0] = 1;
    int state = 0;
    long long r = 0;
    for (char c : S) {
        state ^= 1 << (c - '0');
        r += have[state]++;
        for (int i = 0; i < 10; ++i) {
            r += have[state ^ (1 << i)];
        }
    }
    return r % 1000000007;
}
