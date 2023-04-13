// you can also use imports, for example:
// import java.util.*;

// you can write to stdout for debugging purposes, e.g.
// System.out.println("this is a debug message");

class Solution {
    public int solution(String S, int K) {
        // Implement your solution here
        int n = S.length();
        if (K == 0) {
            return n;
        }
        int[] num = new int[26];
        for (int i = 0; i < n; ++i) {
            if (++num[S.charAt(i) - 'a'] == 1) {
                --K;
            }
        }
        if (K == 0) {
            return 0;
        }
        if (K > 0) {
            return -1;
        }
        int r = Integer.MAX_VALUE;
        for (int i = 0, j = 0; i < n; ) {
            for (; j < n && K < 0; ++j) {
                if (--num[S.charAt(j) - 'a'] == 0) {
                    ++K;
                }
            }
            if (K == 0) {
                r = Math.min(r, j - i);
            }
            if (++num[S.charAt(i++) - 'a'] == 1) {
                --K;
            }
        }
        return r;
    }
}
