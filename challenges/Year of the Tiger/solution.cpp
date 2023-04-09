// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <bits/stdc++.h>
using namespace std;

int solution(vector<string> &T) {
    // Implement your solution here
    int r = 0;
    unordered_map<string, int> have;
    for (const string & s : T) {
        unordered_set<string> one = {s};
        string p(s);
        swap(p[0], p[1]);
        one.insert(p);
        swap(p[0], p[1]);
        swap(p[1], p[2]);
        one.insert(p);
        for (const auto& t : one) {
            r = max(r, ++have[t]);
        }
    }
    return r;
}
