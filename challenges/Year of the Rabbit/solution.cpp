// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A, vector<int> &B) {
    // Implement your solution here
    const int n = A.size();
    for (int i = 0; i < n; ++i) {
        bool ok = true;
        for (int j = 0; ok && j < n; ++j) {
            ok = A[j] != B[(j - i + n) % n];
        }
        if (ok) {
            return i;
        }
    }
    return -1;
}
