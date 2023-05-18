// you can also use imports, for example:
// import java.util.*;

// you can write to stdout for debugging purposes, e.g.
// System.out.println("this is a debug message");

import java.util.*;

class Solution {
private boolean dfs(List<Integer> may, int w, int length) {
    if (may.size() > length) {
        return false;
    }
    final int last = may.get(may.size() - 1);
    if (may.get(may.size() - 1) == w) {
        return true;
    }
    if (may.size() == length) {
        return false;
    }
    for (int i = may.size() - 1; i >= 0; --i) {
        for (int j = i; j >= 0; --j) {
            final int x = may.get(i) + may.get(j);
            if (x > w) {
                continue;
            }
            if (x <= last || x << (length - may.size() - 1) < w) {
                break;
            }
            may.add(x);
            if (dfs(may, w, length)) {
                return true;
            }
            may.remove(may.size() - 1);
        }
    }
    return false;
}
    public int[] solution(int A) {
        List<Integer> r = new ArrayList<>();
        r.add(1);
        for (int length = 1; !dfs(r, A, length); ++length)
        ;
        return r.stream().mapToInt(i->i).toArray();

    }
}
