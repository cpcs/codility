// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A, vector<int> &B) {
    // Implement your solution here
    const int n = A.size();
    for (int i = 1; i < n; ++i) {
        A[i] = min(A[i], A[i - 1]);
    }
    int j = 0;
    for (int i = n - 1; i >= 0 && j < B.size(); --i) {
        for (; i >= 0 && A[i] < B[j]; --i)
        ;
        if (i >= 0) {
            ++j;
        }
    }
    return j;
}
