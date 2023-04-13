// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

vector<int> solution(int K, int M, vector<int> &A) {
    // Implement your solution here
    int ans = 0;
    vector<int> v(M + 2);
    for (int x : A) {
        if (++v[x] > v[ans]) {
            ans = x;
        }
    }
    vector<bool> mark(M + 2);
    const int n = A.size();
    for (int i = 0; i < n; ++i) {
        --v[A[i]];
        if (++v[++A[i]] > v[ans]) {
            ans = A[i];
        }
        if (i >= K) {
            --v[A[i - K]];
            if (++v[--A[i - K]] > v[ans]) {
                ans = A[i - K];
            }
        }
        if (i >= K - 1 && v[ans] + v[ans] > n) {
            mark[ans] = true;
        }
    }
    vector<int> r;
    for (int i = 1; i < mark.size(); ++i) {
        if (mark[i]) {
            r.push_back(i);
        }
    }
    return r;
}
