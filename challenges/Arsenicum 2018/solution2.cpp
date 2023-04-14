// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <bits/stdc++.h>
using namespace std;

bool ok(const string& s, int i, int len) {
    for (int j = i + len - 1; i < j; ++i, --j) {
        if (s[i] != s[j]) {
            return false;
        }
    }
    return true;
}

void dfs(int id, int diff, int dir, const vector<string> &words, 
const vector<vector<vector<int>>>& pre, vector<string> &left, vector<string> &right) {
    if (diff == words[id].length()) {
        if (dir) {
            right.push_back(words[id]);
        } else {
            left.push_back(words[id]);
        }
        return;
    }
    const int state = pre[id][diff][dir];
    if (state >= 0) {
        const int id2 = state >> 19, state2 = state & 524287;
        dfs(state2 >> 10, (state2 >> 1) & 511, state2 & 1, words, pre, left, right);
        if (state2 & 1) {
            left.push_back(words[id2]);
        } else {
            right.push_back(words[id2]);
        }
    }
}

string join(const vector<string> &left, const vector<string> &right) {
    string r;
    for (const string s : left) {
        if (!r.empty()) {
            r.push_back(' ');
        }
        r.append(s);
    }
    for (int i = right.size() - 1; i >= 0; --i) {
        if (!r.empty()) {
            r.push_back(' ');
        }
        r.append(right[i]);
    }
    return r;
}

string solution(string &S) {
    // Implement your solution here
    istringstream in(S);
    vector<string> words;
    vector<unordered_map<string, int>> have(2);
    vector<unordered_map<string, vector<int>>> partial(2);
    queue<int> q;
    int m = 0;
    for (string s; in >> s;) {
        if (ok(s, 0, s.length())) {
            return s;
        }
        int id = words.size();
        have[1][s] = id;
        words.push_back(s);
        for (int i = 1; i <= s.length(); ++i) {
            partial[1][s.substr(0, i)].push_back(id);
            string temp = s.substr(i - 1);
            reverse(temp.begin(), temp.end());
            partial[0][temp].push_back(id);
        }
        m = max(m, (int) s.length());
        reverse(s.begin(), s.end());
        have[0][s] = id;
    }

    const int n = words.size();
    // [id][unmatched_length][left = 0/right = 1]
    vector<vector<vector<bool>>> mark(n, vector<vector<bool>>(m + 1, vector<bool>(2)));
    vector<vector<vector<int>>> pre(n, vector<vector<int>>(m + 1, vector<int>(2, -1)));
    for (int i = 0; i < n; ++i) {
         q.push((i << 10) | (words[i].length() << 1));
         pre[i][words[i].length()][0] = i << 19;
         mark[i][words[i].length()][0] = true;
    };
    while (!q.empty()) {
        const int state = q.front();
        q.pop();
        const int id = state >> 10, len = (state >> 1) & 511, d1 = state & 1, d2 = d1 ^ 1;
        vector<string> left, right;
        string temp;
        if (d1 == 0) {
        // abcde    ba
        // ab       dceba
            temp = words[id].substr(words[id].length() - len);
        } else {
            temp = words[id].substr(0, len);
            reverse(temp.begin(), temp.end());
        }
        if (partial[d1].count(temp)) {
            for (int i : partial[d1][temp]) {
                const int len2 = words[i].length() - len;
                const int prestate = (i << 19) | state;
                if (ok(words[i], 0, len2)) {
                    pre[id][0][0] = prestate;
                    dfs(id, 0, 0, words, pre, left, right);
                    return join(left, right);
                }
                if (!mark[i][len2][d2]) {
                    pre[i][len2][d2] = prestate;
                    mark[i][len2][d2] = true;
                    q.push((i << 10) | (len2 << 1) | d2);
                }
            }
        }
        for (temp.pop_back(); !temp.empty(); temp.pop_back()) {
            const int len2 = len - temp.length();
            if (!mark[id][len2][d1] && have[d1].count(temp)) {
                pre[id][len2][d1] = (have[d1][temp] << 19) | state;
                mark[id][len2][d1] = true;
                q.push((id << 10) | (len2 << 1) | d1);
            }
        }
    }
    return "NO";
}
