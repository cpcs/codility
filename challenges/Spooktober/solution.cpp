// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // Implement your solution here
    const int n = A.size();
    vector<int> p(n);
    p.back() = A.back();
    for (int i = n - 2; i >= 0; --i) {
        p[i] = A[i] + (p[i + 1] >> 1);
    }
    int r = p[0];
    for (int i = 1, last = A[0]; i < n; last += A[i++]) {
        last >>= 1;
        r = max(r, last + p[i]);
    }
    return r;
}
