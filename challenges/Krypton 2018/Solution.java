// you can also use imports, for example:
// import java.util.*;

// you can write to stdout for debugging purposes, e.g.
// System.out.println("this is a debug message");

class Solution {
    public int solution(int[][] A) {
        int n = A.length;
        // minimum number of 2 and 5.
        int[][] dp = new int[n][];
        for (int i = 0; i < n; ++i) {
            dp[i] = new int[] {Integer.MAX_VALUE, Integer.MAX_VALUE};
        }
        boolean z = false;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int[] v = new int[2];
                if (A[i][j] == 0) {
                    v[0] = v[1] = 1;
                    z = true;
                } else {
                    for (int x = A[i][j]; (x & 1) == 0; x >>= 1, ++v[0])
                    ;
                    for (int x = A[i][j]; x % 5 == 0; x /= 5, ++v[1]);
                }
                if (i == 0 && j == 0) {
                    dp[j] = v;
                    continue;
                }
                if (j > 0) {
                    dp[j][0] = Math.min(dp[j][0], dp[j - 1][0]);
                    dp[j][1] = Math.min(dp[j][1], dp[j - 1][1]);
                }
                dp[j][0] += v[0];
                dp[j][1] += v[1];
            }
        }
        int r = Math.min(dp[n - 1][0], dp[n - 1][1]);
        return z ? Math.min(r, 1) : r;
    }
}
