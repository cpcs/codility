// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

vector<int> solution(vector<int> &A) {
    // Implement your solution here
    vector<int> r(3), c(3);
    int m = 0;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            r[i] += A[i * 3 + j];
            c[j] += A[i * 3 + j];
        }
        m = max(m, r[i]);
    }
    for (int i = 0; i < 3; ++i) {
        m = max(m, c[i]);
    }
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            const int d = min(m - r[i], m - c[j]);
            r[i] += d;
            c[j] += d;
            A[i * 3 + j] += d;
        }
    }
    return A;
}
