// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <bits/stdc++.h>
using namespace std;

void better(int &x, int y) {
    if ((y >= 0) && (x < 0 || x > y)) {
        x = y;
    }
}

int check(const list<int> &left) {
    if (left.size() < 3) {
        return -1;
    }
    auto t = left.end();
    --t;
    --t;
    --t;
    return left.back() - (*t) - 2;
}

int cal(list<int> &left, const list<int> &right, int p1, int p2, int p3) {
    const int num1 = p2 - p1 - 1, num2 = p3 - p2 - 1;
    int cost = num1 + num2;
    if (num1 >= 3) {
        return cost;
    }
    int q = p1, r = -1;
    auto t = right.begin();
    for (int i = 1; (i <= num1 + num2 || t != right.end()) && q - p1 < 3; ++i) {
        left.push_back(q++);
        const int may = check(left);
        if (i > num1 && i <= num1 + num2) {
            ++cost;
        } else if (i > num1 + num2) {
            cost += (*(t++)) - p3 + 2;
        }
        if (may >= 0) {
            better(r, may + cost);
        }
    }
    for (int i = q - p1; i; --i) {
        left.pop_back();
    }
    return r;
}

int run(string &s) {
    // Implement your solution here
    list<int> right;
    const int n = s.length();
    int m = 0;
    // The minimal cost to have 3 consecutive b's in S[i..n - 1]
    vector<int> dp(n, -1);
    for (int i = n - 1; i >= 0; --i) {
        if (i + 1 < n) {
            dp[i] = dp[i + 1];
        }
        if (s[i] == 'a') {
            ++m;
        } else {
            right.push_front(i);
            better(dp[i], check(right));
        }
    }
    if (m < 3 || right.size() < 3) {
        return -1;
    }
    list<int> left, a;
    int r = -1;
    for (int i = 0, last = 0; i < n; ++i) {
        while (!right.empty() && right.front() <= i) {
            right.pop_front();
        }
        if (s[i] == 'b') {
            continue;
        }
        a.push_back(i);
        if (a.size() >= 3) {
            auto t = a.end();
            --t;
            int p2 = *(--t);
            int p1 = *(--t);
            for (; last <= p1; ++last) {
                if (s[last] == 'b') {
                    left.push_back(last);
                }
            }
            const int cost = i - p1 - 2;
            if (dp[i] >= 0) {
                better(r, cost + dp[i]);
            }
            better(r, cal(left, right, p1, p2, i));
        }
    }
    return r;
}

int solution(string& S) {
    int r = run(S);
    reverse(S.begin(), S.end());
    better(r, run(S));
    return r;
}
