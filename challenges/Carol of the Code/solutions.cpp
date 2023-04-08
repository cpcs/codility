// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<string> &A) {
    // Implement your solution here
    const char *p = "RGBW";
    const int n = A.size();
    int r = n;
    for (int i = 0; i < 4; ++i) {
        char last = p[i];
        int may = 0;
        for (int j = 0; may < r && j < n; ++j) {
            for (int k = 0; k < 4; ++k) {
                if (A[j][k] == last) {
                    const int d = (k + 1) & 3;
                    may += d == 3 ? 1 : d;
                    last = A[j][(k + 2) & 3];
                    break;
                }
            }
        }
        r = min(r, may);
    }
    return r;
}
