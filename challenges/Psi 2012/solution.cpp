// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

bool dfs(int n, int x, int y, const vector<vector<vector<bool>>> &e, vector<vector<bool>> &mark) {
    if (x < 0 || x >= n || y < 0 || y >= n || mark[x][y]) {
        return false;
    }
    mark[x][y] = true;
    if (x == n - 1 && y == n - 1) {
        return true;
    }
    const int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
    for (int i = 0; i < 4; ++i) {
       if (e[x][y][i] && dfs(n, x + dx[i], y + dy[i], e, mark)) {
           return true;
       }
    }
    return false;
}

int solution(int N, vector<int> &A, vector<int> &B, vector<int> &C) {
    // Implement your solution here
    vector<vector<vector<bool>>> e(N, vector<vector<bool>>(N, vector<bool>(4, true)));
    const int m = A.size();
    for (int i = 0; i < m; ++i) {
        if (C[i]) {
            e[A[i]][B[i]][1] = e[A[i] + 1][B[i]][3] = false;
        } else {
            e[A[i]][B[i]][0] = e[A[i]][B[i] + 1][2] = false;
        }
    }
    vector<vector<bool>> mark(N, vector<bool>(N));
    if (dfs(N, 0, 0, e, mark)) {
        return -1;
    }
    for (int i = m - 1; i >= 0; --i) {
        if (C[i]) {
            e[A[i]][B[i]][1] = e[A[i] + 1][B[i]][3] = true;
            if ((mark[A[i]][B[i]] || mark[A[i] + 1][B[i]]) && ((dfs(N, A[i], B[i], e, mark) || dfs(N, A[i] + 1, B[i], e, mark)))) {
                return i + 1;
            }
        } else {
            e[A[i]][B[i]][0] = e[A[i]][B[i] + 1][2] = true;
            if ((mark[A[i]][B[i]] || mark[A[i]][B[i] + 1]) && ((dfs(N, A[i], B[i], e, mark) || dfs(N, A[i], B[i] + 1, e, mark)))) {
                return i + 1;
            }
        }
    }
    return -1;
}
