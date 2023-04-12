// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int dfs(int x, const vector<int> &a, const vector<int> &b, const vector<vector<int>> &con, vector<bool> &mark) {
    if (mark[x]) {
        return 0;
    }
    int r = a[x] - b[x];
    mark[x] = true;
    for (int y : con[x]) {
        r += dfs(y, a, b, con, mark);
    }
    return r;

}

bool solution(vector<int> &P, vector<int> &T, vector<int> &A, vector<int> &B) {
    // Implement your solution here
    const int n = P.size();
    vector<vector<int>> con(n);
    for (int i = 0; i < A.size(); ++i) {
        con[A[i]].push_back(B[i]);
        con[B[i]].push_back(A[i]);
    }
    vector<bool> mark(n);
    for (int i = 0; i < n; ++i) {
        if (dfs(i, P, T, con, mark)) {
            return false;
        }
    }
    return true;
}
