// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

void better(int &x, int y) {
    if (y >= 0 && (x < 0 || x > y)) {
        x = y;
    }
}

int solution(vector<int> &A, vector<int> &B) {
    // Implement your solution here
    const int n = A.size();
    vector<int> dp = {0, 1};
    for (int i = 1; i < n; ++i) {
        vector<int> v = {-1, -1};
        if (A[i] > A[i - 1] && B[i] > B[i - 1]) {
            if (dp[0] >= 0) {
                better(v[0], dp[0]);
            }
            if (dp[1] >= 0) {
                better(v[1], dp[1] + 1);
            }
        }
        if (A[i] > B[i - 1] && B[i] > A[i - 1]) {
            if (dp[1] >= 0) {
                better(v[0], dp[1]);
            }
            if (dp[0] >= 0) {
                better(v[1], dp[0] + 1);
            }
        }
        dp = v;
    }
    int r = dp[0];
    better(r, dp[1]);
    return r;
}
