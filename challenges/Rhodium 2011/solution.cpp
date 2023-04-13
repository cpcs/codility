// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

void dfs(const vector<vector<int>> &con, int x, int f, int t1, int t2, vector<int> &m1, vector<int> &m2) {
    m1[x] = t1 = min(t1, x);
    m2[x] = t2 = max(t2, x);
    for (int y : con[x]) {
        if (y != f) {
            dfs(con, y, x, t1, t2, m1, m2);
        }
    }
}

int solution(vector<int> &T) {
    // Implement your solution here
    const int n = T.size();
    vector<vector<int>> con(n);
    for (int i = 0; i < n; ++i) {
        if (T[i] != i) {
            con[i].push_back(T[i]);
            con[T[i]].push_back(i);
        } 
    }
    vector<vector<int>> p1(n, vector<int>(n));
    vector<vector<int>> p2(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        dfs(con, i, -1, i, i, p1[i], p2[i]);
    }
    int r = n;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1, m = i; j < n && p1[j - 1][j] >= i; ++j) {
            m = max(m, p2[j - 1][j]);
            if (m <= j) {
                ++r;
            }
            
        }
    }
    return r;
}
