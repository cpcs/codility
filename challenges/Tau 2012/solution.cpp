// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector< vector<int> > &C) {
    // Implement your solution here
    const int m = C.size(), n = C[0].size();
    int r = 0;
    for (int i = 0; i < m; ++i) {
        vector<int> v(n);
        for (int j = 0; j < m; ++j) {
            // Row i..(i + j)
            const int k = (i + j) % m;
            int m = 0, sum = 0;
            for (int t = 0, max_ending = 0, min_ending = 0; t < n; ++t) {
                v[t] += C[k][t];
                sum += v[t];
                max_ending = max(max_ending, 0) + v[t];
                min_ending = min(min_ending, 0) + v[t];
                r = max(r, max_ending);
                m = min(m, min_ending);
            }
            r = max(r, sum - m);
        }
    }
    return r;
}
