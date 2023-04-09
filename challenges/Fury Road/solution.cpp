// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(string &R) {
    // Implement your solution here
    int r = 0;
    for (char c : R) {
        r += c == 'A' ? 5 : 40;
    }
    for (int i = R.length() - 1, may = r; i >= 0; --i) {
        may += R[i] == 'A' ? 15 : -10;
        r = min(may, r);
    }
    return r;
}
