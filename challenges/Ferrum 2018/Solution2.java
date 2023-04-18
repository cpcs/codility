// you can also use imports, for example:
// import java.util.*;

// you can write to stdout for debugging purposes, e.g.
// System.out.println("this is a debug message");

class Solution {
    public int solution(int[] A) {
        // Implement your solution here
        int n = A.length;
        // 前缀和数组
        int[] p = new int[n + 1];
        // 以这一项结尾的子数组的最大和
        int[] best = new int[n];
        int length = 0;
        for (int i = 1, m = 0; i <= n; ++i) {
            p[i] = p[i - 1] + A[i - 1];
            best[i - 1] = p[i] - p[m];
            for (; length < i && best[i - length - 1] + p[i] - p[i - length] >= 0; ++length)
            ;
            if (p[i] < p[m]) {
                m = i;
            }
        }
        return length;
    }
}
