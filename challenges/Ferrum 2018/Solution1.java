// you can also use imports, for example:
// import java.util.*;

// you can write to stdout for debugging purposes, e.g.
// System.out.println("this is a debug message");

import java.util.*;

class Solution {
    public int solution(int[] A) {
        // Implement your solution here
        Map<Integer, Integer> have = new HashMap<>();
        have.put(0, 0);
        int r = 0, s = 0;
        for (int i = 1; i <= A.length; ++i) {
            s += A[i - 1];
            if (have.containsKey(s)) {
                r = Math.max(r, i - have.get(s));
            } else {
                have.put(s, i);
            }
        }
        return s > 0 ? A.length : r;
    }
}
