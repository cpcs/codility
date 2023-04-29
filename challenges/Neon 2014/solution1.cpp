// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &R, int X, int M) {
    // Implement your solution here
    const int n = R.size(), len = X << 1;
    if (M / len < n) {
        return -1;
    }
    int left = 0, right = M - X;
    while (left <= right) {
        const int mid = (left + right) >> 1;
        bool can = true;
        for (int i = 0, last = -X; i < n; ++i) {
            const int x = max(last + len, R[i] - mid);
            const int y = min(M - (n - 1 - i) * len - X, R[i] + mid);
            if (x <= y) {
                last = x;
            } else {
                can = false;
                break;
            }
        }
        if (can) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return right + 1;
}
