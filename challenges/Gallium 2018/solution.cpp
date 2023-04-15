// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // Implement your solution here
    // 5 ^ 12 = 244140625
    vector<vector<int>> dp(4, vector<int>(37, -1));
    dp[0][0] = 0;
    for (int x : A) {
        int num2 = 0, num5 = 0;
        for (int p = x; (p & 1) == 0; p >>= 1, ++num2)
        ;
        for (int p = x; p % 5 == 0; p /= 5, ++num5)
        ;
        for (int i = 3; i >= 1; --i) {
            for (int j = i * 12; j >= num5; --j) {
                if (dp[i - 1][j - num5] >= 0) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - num5] + num2);
                }
            }
        }
    }
    int r = 0;
    for (int i = 0; i < dp[3].size(); ++i) {
        r = max(r, min(dp[3][i], i));
    }
    return r;
}
