// you can also use imports, for example:
// import java.util.*;

// you can write to stdout for debugging purposes, e.g.
// System.out.println("this is a debug message");

import java.util.*;

class Solution {
    public String solution(int[][] A) {
        // Implement your solution here
        Queue<Integer>[] q = new Queue[2];
        q[0] = new ArrayDeque<>();
        q[1] = new ArrayDeque<>();
        q[0].add(0);
        StringBuilder sb = new StringBuilder("" + A[0][0]);
        int m = A.length, n = A[0].length, p = m + n - 2;
        for (int s = 0; s < p;++s) {
            int last = s & 1, now = last ^ 1, v = -1;
            for (q[now].clear(); !q[last].isEmpty();) {
                int x = q[last].poll(), y = s - x;
                for (int i = 0; i < 2; ++i) {
                    int nx = x + i, ny = y + (i ^ 1);
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && A[nx][ny] >= v) {
                        if (A[nx][ny] > v) {
                            v = A[nx][ny];
                            q[now].clear();
                        }
                        q[now].add(nx);
                        A[nx][ny] = 0;
                    }
                }
            }
            sb.append(v);
        }
        return sb.toString();
    }
}
