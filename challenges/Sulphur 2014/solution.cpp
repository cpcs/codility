// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int dfs(const vector<vector<int>> &con, const vector<int> &b, int m, int x, vector<int> &ans) {
    if (ans[x] >= 0) {
        return ans[x];
    }
    ans[x] = b[x];
    for (int y : con[x]) {
        if (y < m) {
            ans[x] += dfs(con, b, m, y, ans);
        }
    }
    return ans[x];
}

int solution(vector<int> &A, vector<int> &B, vector<int> &C) {
    // Implement your solution here
    const int n = A.size();
    vector<vector<int>> con(n);
    for (int i = 0; i < n; ++i) {
        if (C[i] >= 0) {
            con[C[i]].push_back(i);
        }
    }
    int left = 1, right = n;
    while (left <= right) {
        const int mid = (left + right) >> 1;
        vector<int> ans(mid, -1);
        bool broken = false;
        for (int i = 0; !broken && i < mid; ++i) {
            const int temp = dfs(con, B, mid, i, ans);
            broken = temp  > A[i];
        }
        if (broken) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return left - 1;
}
