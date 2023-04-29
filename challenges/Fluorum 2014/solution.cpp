// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int dfs(int x, int f, int dep, const vector<vector<int>> &con, vector<int> &num, vector<bool>& leaf) {
    num[x] = dep++;
    leaf[x] = true;
    int best = x;
    for (int y : con[x]) {
        if (y != f) {
            leaf[x] = false;
            const int may = dfs(y, x, dep, con, num, leaf);
            if (num[may] > num[best] || (num[may] == num[best] && may < best)) {
                // Only the best one is the candidate to the current node.
                // And only the best one uses the "absolute value".
                num[best] -= dep;
                best = may;
            } else {
                num[may] -= dep;
            }
        }
    }
    return best;
}

vector<int> solution(int K, vector<int> &T) {
    // Implement your solution here
    const int n = T.size();
    vector<vector<int>> con(n);
    for (int i = 0; i < n; ++i) {
        if (T[i] != i) {
            con[i].push_back(T[i]);
            con[T[i]].push_back(i);
        }
    }
    vector<int> num(n);
    vector<bool> leaf(n);
    dfs(K, -1, 0, con, num, leaf);
    vector<int> r = {K};
    vector<vector<int>> all(n);
    for (int i = 0; i < n; ++i) {
        if (i != K && leaf[i]) {
            all[num[i]].push_back(i);
        }
    }
    for (int i = n - 1; i >= 0; --i) {
        for (int x : all[i]) {
            r.push_back(x);
        }
    }
    return r;
}
