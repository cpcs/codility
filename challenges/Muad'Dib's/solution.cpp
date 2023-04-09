// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // Implement your solution here
    const int n = A.size();
    vector<int> dp(n + 1);
    for (int i = 1; i <= n; ++i) {
        dp[i] = dp[i - 1] + 2;
        int j = i - 1;
        for (; j && A[i - 1] - A[j - 1] <= 6; --j)
        ;
        dp[i] = min(dp[i], dp[j] + 7);
        for (; j && A[i - 1] - A[j - 1] <= 29; --j)
        ;
        dp[i] = min(dp[i], dp[j] + 25);
    }
    return dp[n];
}
