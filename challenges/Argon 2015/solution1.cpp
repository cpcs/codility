// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) { 
    int n = A.size(); int m = (n + 1) << 1; 
    // [-n..+n] ->[1..2 * n + 1] 
    vector<int> save1(m, n); 
    vector<int> p(n + 1); 
    p[0] = n + 1; 
    save1[n + 1] = 0; 
     // If sum == i, what is the minimum index?
    for (int i = 1; i <= n; ++i) { 
        p[i] = p[i - 1] + ((A[i - 1] == 0)? 1 : (-1)); 
        if (save1[p[i]] == n) { 
            save1[p[i]] = i;
        } 
    } 
    for (int i = 1; i < m; ++i) { 
        save1[i] = min(save1[i], save1[i - 1]); 
    } 
    vector<int> save2(m, 0); 
    int now = n + 1; 
    save2[n + 1] = n + 1; 
    for (int i = n; i > 0; --i) { 
        now += ((A[i - 1] == 1)?1 : (-1)); 
        if (save2[now] == 0) { 
            save2[now] = i; 
        } 
    } 
    // If sum == i, what is the maximum index?
    for (int i = 1; i < m; ++i) { 
        save2[i] = max(save2[i], save2[i - 1]); 
    } 
    int answer = 0; 
    now = n + 1; 
    for (int i = n; i > 1; --i) { 
        //1..i - 1, i..n 
        now = now + ((A[i - 1] == 1)? 1 : (-1)); 
        if ((save1[p[i - 1] - 1] < i - 1) && (save2[now - 1] > i)) { 
            answer = max(answer, save2[now - 1] - 1 - save1[p[i - 1] - 1]); 
        } 
    } 
    return answer; 
}
