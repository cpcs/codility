// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(int N, int M, vector<int> &X, vector<int> &Y) {
    // Implement your solution here
    int n = X.size();
    if (n & 1) {
        return 0;
    }
    n >>= 1;
    vector<int> a(N);
    for (int x : X) {
        ++a[x];
    }
    int r = 0;
    for (int i = 0, s = -n; i < N; ++i) {
        s += a[i];
        if (s > 0) {
            break;
        }
        if (s == 0) {
            ++r;
        }
    }
    vector<int> b(M);
    for (int x : Y) {
        ++b[x];
    }
    for (int i = 0, s = -n; i < M; ++i) {
        s += b[i];
        if (s > 0) {
            break;
        }
        if (s == 0) {
            ++r;
        }
    }
    return r;
}
