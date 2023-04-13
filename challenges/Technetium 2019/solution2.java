// you can also use imports, for example:
// import java.util.*;

// you can write to stdout for debugging purposes, e.g.
// System.out.println("this is a debug message");

import java.util.*;

class Solution {
    public String solution(int[][] A) {
        // Implement your solution here
        Queue<Integer> q = new ArrayDeque<>();
        q.add(0);
        StringBuilder sb = new StringBuilder("" + A[0][0]);
        int m = A.length, n = A[0].length, p = m + n - 2;
        for (int s = 0; s < p;) {
            int v = -1;
            for (int t = q.size(); t > 0; --t) {
                int x = q.poll(), y = s - x;
                for (int i = 0; i < 2; ++i) {
                    int nx = x + i, ny = y + (i ^ 1);
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && A[nx][ny] > 0) {
                        q.add(nx);
                        v = Math.max(v, A[nx][ny]);
                        A[nx][ny] = -A[nx][ny];
                    }
                }
            }
            sb.append(v);
            ++s;
            for (int t = q.size(); t > 0; --t) {
                int x = q.poll(), y = s - x;
                if (A[x][y] == -v) {
                    q.add(x);
                }
            }
        }
        return sb.toString();
    }
}
