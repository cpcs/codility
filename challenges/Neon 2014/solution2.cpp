// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &R, int X, int M) {
    // Implement your solution here
    const int n = R.size(), len = X << 1;
    if (M / len < n) {
        return -1;
    }
    vector<int> mini(n);
    for (int i = n - 1, center = len * n - X; i >= 0; --i, center -= len) {
        mini[i] = R[i] - center;
        if (i + 1 < n) {
            mini[i] = min(mini[i], mini[i + 1]);
        }
    }
    const int limit = M - len * n;
    int r = 0;
    for (int i = 0, center = X, move = 0; i < n; ++i, center += len) {
        const int d = R[i] - center;
        if (d > r) {
            move = max(move, min((d + mini[i]) / 2, limit));
        }
        r = max(r, abs(d - move));
    }
    return r;
}
