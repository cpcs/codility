// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // Implement your solution here
    vector<int> b;
    for (int i = 1; i + 1 < A.size(); ++i) {
        if (A[i] > A[i - 1] && A[i] > A[i + 1]) {
            b.push_back(i);
        }
    }
    if (b.empty()) {
        return 0;
    }
    int left = 1, right = b.size();
    while (left <= right) {
        const int mid = (left + right) >> 1;
        int num = 1;
        for (int i = 1, last = b[0]; i < b.size() && num < mid; ++i) {
            if (b[i] >= last + mid) {
                last = b[i];
                ++num;
            }
        }
        if (num >= mid) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return left - 1;
}
