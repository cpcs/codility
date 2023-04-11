// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

string solution(string &S) {
    // Implement your solution here
    const int n = S.length();
    for (int i = 0; i + 2 < n; ++i) {
        if (S[i] == 'a' && S[i + 1] == 'b' && S[i + 2] == 'b') {
            S[i] = 'b';
            S[i + 1] = S[i + 2] = 'a';
            for (int j = i, mark = 0; j >= 2; --j) {
                if (S[j] == 'b' && S[j - 1] == 'b' && S[j - 2] == 'a') {
                    S[j - 2] = 'b';
                    S[j - 1] = S[j] = 'a';
                    mark = 0;
                } else if (++mark == 3) {
                    break;
                }
            }
        }
    }
    return S;
}
