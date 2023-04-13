// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <vector>
using namespace std;

void dfs(int have, int now, int state, const vector<vector<bool>> &mark, int num, int &ans) {
    if (num >= ans) {
        return;
    }
    int mask = 1 << now;
    if (mask > have) {
        ans = num;
        return;
    }
    if ((mask & have) == 0) {
        dfs(have, now + 1, state, mark, num, ans);
    } else {
        int temp = 0, d = 0;
        for (int i = now + 1; i < 26; ++i) {
            if (mark[i][now] && (have & (1 << i)) > 0) {
                temp |= 1 << i;
                ++d;
            }
        }
        dfs(have ^ temp, now + 1, state | temp, mark, num + d, ans);
        dfs(have, now + 1, state | mask, mark, num + 1, ans);
    }
} 
    
int solution(string &P, string &Q) {
    // Implement your solution here
    vector<vector<bool>> mark(26, vector<bool>(26));
    const int n = P.length();
    for (int i = 0; i < n; ++i) {
        const int p = P[i] - 'a', q = Q[i] - 'a';
        mark[p][q] = mark[q][p] = true;
    }
    int temp = 0;
    for (int i = 0; i < 26; ++i) {
        if (mark[i][i]) {
            ++temp;
            for (int j = 0; j < 26; ++j) {
                mark[i][j] = mark[j][i] = false;
            }
        }
    }
    int have = 0;
    for (int i = 0; i < 26; ++i) {
        for (int j = 0; j < 26; ++j) {
            if (mark[i][j]) {
                have |= 1 << i;
                break;
            }
        }
    }
    int ans = P.length();
    dfs(have, 0, 0, mark, temp, ans);
    return ans;
}
