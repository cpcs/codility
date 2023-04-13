// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <bits/stdc++.h>
using namespace std;
int solution(vector< vector<int> > &A) {
    // Implement your solution here
    int r = 0;
    unordered_map<string, int> have;
    for (const auto& v : A) {
        string s;
        for (int x : v) {
            s.push_back((x ^ v[0]) + '0');
        }
        r = max(r, ++have[s]);
    }
    return r;
}
