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
    unordered_map<string, int> have;
    unordered_map<string, int> rhave;
    unordered_map<string, vector<int>> prefix;
    unordered_map<string, vector<int>> suffix;
    queue<int> q;
    int m = 0;
    for (string s; in >> s;) {
        if (ok(s, 0, s.length())) {
            return s;
        }
        int id = words.size();
        have[s] = id;
        words.push_back(s);
        for (int i = 1; i <= s.length(); ++i) {
            prefix[s.substr(0, i)].push_back(id);
            string temp = s.substr(i - 1);
            reverse(temp.begin(), temp.end());
            suffix[temp].push_back(id);
        }
        m = max(m, (int) s.length());
        reverse(s.begin(), s.end());
        rhave[s] = id;
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
        const int id = state >> 10, len = (state >> 1) & 511, d = state & 1;
        vector<string> left, right;
        string temp;
        // abcde    ba
        // ab       dceba
        if (d == 0) {
            temp = words[id].substr(words[id].length() - len);
            if (suffix.count(temp)) {
                for (int i : suffix[temp]) {
                    const int len2 = words[i].length() - len;
                    const int prestate = (i << 19) | state;
                    if (ok(words[i], 0, len2)) {
                        pre[id][0][0] = prestate;
                        dfs(id, 0, 0, words, pre, left, right);
                        return join(left, right);
                    }
                    if (!mark[i][len2][1]) {
                        pre[i][len2][1] = prestate;
                        mark[i][len2][1] = true;
                        q.push((i << 10) | (len2 << 1) | 1);
                    }
                }
            }
            for (temp.pop_back(); !temp.empty(); temp.pop_back()) {
                const int len2 = len - temp.length();
                if (!mark[id][len2][0] && rhave.count(temp)) {
                    pre[id][len2][0] = (rhave[temp] << 19) | state;
                    mark[id][len2][0] = true;
                    q.push((id << 10) | (len2 << 1));
                }
            }
        } else {
            temp = words[id].substr(0, len);
            reverse(temp.begin(), temp.end());
            if (prefix.count(temp)) {
                for (int i : prefix[temp]) {
                    const int len2 = words[i].length() - len;
                    const int prestate = (i << 19) | state;
                    if (ok(words[i], len, len2)) {
                        pre[id][0][0] = prestate;
                        dfs(id, 0, 0, words, pre, left, right);
                        return join(left, right);
                    }
                    if (!mark[i][len2][0]) {
                        pre[i][len2][0] = prestate;
                        mark[i][len2][0] = true;
                        q.push((i << 10) | (len2 << 1));
                    }
                }
            }
            for (temp.pop_back(); !temp.empty(); temp.pop_back()) {
                const int len2 = len - temp.length();
                if (have.count(temp) && !mark[id][len2][1]) {
                    pre[id][len2][1] = (have[temp] << 19) | state;
                    mark[id][len2][1] = true;
                    q.push((id << 10) | (len2 << 1) | 1);
                }
            }
        }
    }
    return "NO";
}
