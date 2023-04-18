// you can also use imports, for example:
// import java.util.*;

// you can write to stdout for debugging purposes, e.g.
// System.out.println("this is a debug message");

import java.util.*;

class Solution {
    public int solution(int[] A) {
        // Implement your solution here
        List<List<Integer>> p = new ArrayList<>();
        p.add(Arrays.asList(0, 0));
        int r = 0;
        for (int i = 1, s = 0; i <= A.length; ++i) {
            s += A[i - 1];
            if (p.get(p.size() - 1).get(1) > s) {
                p.add(Arrays.asList(i, s));
            }
            int left = 0, right = p.size() - 1;
            while (left <= right) {
                int mid = (left + right) >> 1;
                if (p.get(mid).get(1) <= s) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            r = Math.max(r, i - p.get(right + 1).get(0));
        }
        return r;
    }
}
