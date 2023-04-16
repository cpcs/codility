// you can also use imports, for example:
// import java.util.*;

// you can write to stdout for debugging purposes, e.g.
// System.out.println("this is a debug message");

 import java.util.*;
class Solution {
    public int solution(int[] A) {
        // Implement your solution here
        // 5 ^ 12 = 244140625
        int[][] dp = new int[4][];
        for (int i = 0; i < 4; ++i) {
            dp[i] = new int[37];
            Arrays.fill(dp[i], -1);
        }
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
                        dp[i][j] = Math.max(dp[i][j], dp[i - 1][j - num5] + num2);
                    }
                }
            }
        }
        int r = 0;
        for (int i = 0; i < dp[3].length; ++i) {
            r = Math.max(r, Math.min(dp[3][i], i));
        }
        return r;
    }
}
