// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

void update(vector<pair<int, int>> &v, const pair<int, int> &p) {
    if (p.first > v[0].first) {
        v[1] = v[0];
        v[0] = p;
    } else if (p.first > v[1].first) {
        v[1] = p;
    }
}

int solution(vector<string> &words) {
    vector<vector<pair<int, int>>> first(26, vector<pair<int, int>>(2, {0, -1})), 
    last(26, vector<pair<int, int>>(2, {0, -2}));
    vector<int> all(26);
    int r = 0;
    for (int i = 0; i < words.size(); ++i) {
        int len = 0;
        char p = '?';
        bool f = true;
        for (char c : words[i]) {
            if (c == p) {
                ++len;
            } else {
                if (len) {
                    const int ind = p - 'a';
                    if (f) {
                        update(first[ind], {len, i});
                        f = false;
                    }
                    r = max(r, len);
                }
                p = c;
                len = 1;
            }
        }
        r = max(r, len);
        const int ind = p - 'a';
        if (len == words[i].length()) {
            all[ind] += len;
        } else {
            update(last[ind], {len, i});
        }
    }
    for (int i = 0; i < 26; ++i) {
        r = max(r, first[i][0].first + all[i] + last[i][first[i][0].second == last[i][0].second].first);
        r = max(r, last[i][0].first + all[i] + first[i][first[i][0].second == last[i][0].second].first);

    }
    return r;
}
