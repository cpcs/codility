int solution(string &S, int K) {
    // Implement your solution here
    const int n = S.length();
    int r = 0;
    if (K == 0) {
        for (char c : S) {
            r += c == 'M';
        }
        return r;
    }
    bool ok = false;
    for (int i = 0, len = 0; i < n; ++i) {
        if (S[i] == 'M') {
           ++len;
           if (len == K) {
               ok = true;
           } else if (len == K + 1) {
               len = 0;
               ++r;
           }
        } else {
            len = 0;
        }
    }
    if (ok) {
        return r;
    }
    r = n;
    for (int i = 0, len = 0; i < n; ++i) {
        if (S[i] == 'M') {
            ++len;
        }
        if (i >= K - 1) {
            if (i >= K && S[i - K] == 'M') {
                --len;
            }
            r = min(r, K - len + (i >= K && S[i - K] == 'M') + (i + 1 < n && S[i + 1] == 'M'));
        }  
    }
    return r;
}
