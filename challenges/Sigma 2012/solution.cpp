// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> &H) {
    // Implement your solution here
    stack<int> s;
    int r = 0;
    for (int x : H) {
        while (!s.empty() && s.top() > x) {
            s.pop();
        }
        if (!s.empty() && s.top() == x) {
            continue;
        }
        s.push(x);
        ++r;
    }
    return r;
}
