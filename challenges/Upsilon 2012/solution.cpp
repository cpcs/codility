// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> &A) {
    // Implement your solution here
    stack<pair<int, int>> s;
    for (int x : A) {
        int height = 0;
        for (; !s.empty() && s.top().first < x; height = max(height + 1, s.top().second), s.pop())
        ;
        s.push({x, height + 1});
    }
    int r = 0;
    for (; !s.empty(); r = max(r + 1, s.top().second), s.pop())
    ;
    return r;
}
