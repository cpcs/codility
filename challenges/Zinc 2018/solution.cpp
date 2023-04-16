// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // Implement your solution here
    const int n = A.size();
    vector<vector<long long>> dp(n + 1, vector<long long>(4));
    vector<long long> sum(4);
    sum[0] = dp[0][0] = 1;
    vector<int> last(100005);
    for (int i = 1; i <= n; ++i) {
        const int x = A[i - 1];
        for (int j = 1; j <= 3; ++j) {
            dp[i][j] += sum[j - 1];
        }
        for (int j = 1; j <= 3; ++j) {
            sum[j] += dp[i][j];
            if (last[x]) {
                sum[j] -= dp[last[x]][j];
            }
        }
        last[x] = i;
    }
    return sum[3] % 1000000007;
}
