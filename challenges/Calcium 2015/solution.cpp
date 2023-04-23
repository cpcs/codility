// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

// The minimum number of cameras needed for the tree rooted at x.
// And the minimum length of paths without camera to go up until root.
pair<int, int> dfs(const vector<vector<int>> &con, int x, int f, int d) {
    pair<int, int> r = {0, 0};
    for (int y : con[x]) {
        if (y != f) {
            const auto p = dfs(con, y, x, d);
            r.first += p.first;
            const int may = p.second + 1;
            if (r.second + may > d) {
                ++r.first;
                r.second = min(r.second, may);
            } else {
                r.second = max(r.second, may);
            }
        }
    }
    return r;
}

int solution(vector<int> &A, vector<int> &B, int K) {
    // Implement your solution here
    const int n = A.size();
    vector<vector<int>> con(n + 1);
    for (int i = 0; i < n; ++i) {
        con[A[i]].push_back(B[i]);
        con[B[i]].push_back(A[i]);
    }
    int left = 0, right = n;
    while (left <= right) {
        const int mid = (left + right) >> 1;
        const int temp = dfs(con, 0, -1, mid).first;
        if (temp <= K) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return right + 1;
}
