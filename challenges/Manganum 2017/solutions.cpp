#include <bits/stdc++.h>

using namespace std;

struct node {
    int m;
    int lower_bound;

    node() : m(0), lower_bound(0) {}
};


struct segmentTree {
public:
vector<node> tree;

   segmentTree(int n) : tree(vector<node>(n << 2)) {}

    void pushdown(int i) {
        if (tree[i].lower_bound > 0) {
            tree[i << 1].lower_bound = max(tree[i << 1].lower_bound, tree[i].lower_bound);
            tree[i << 1].m = max(tree[i << 1].m, tree[i].lower_bound);
            tree[(i << 1) | 1].lower_bound = max(tree[(i << 1) | 1].lower_bound, tree[i].lower_bound);
            tree[(i << 1) | 1].m = max(tree[(i << 1) | 1].m, tree[i].lower_bound);
            tree[i].lower_bound = 0;
        }
    }
    
    void pushup(int i) {
        tree[i].m = max(tree[i << 1].m, tree[(i << 1) | 1].m);
    }

    int query(int ind, int left, int right, int x, int y) {
        if (left >= x && right <= y) {
            return tree[ind].m;
        }
        pushdown(ind);
        const int mid = (left + right) >> 1;
        int r = 0;
        if (x <= mid) {
            r = query(ind << 1, left, mid, x, y);
        }
        if (y > mid) {
            r = max(r, query((ind << 1) | 1, mid + 1, right, x, y));
        } 
        return r;
    }

    void update(int ind, int left, int right, int x, int y, int lower_bound) {
        if (left >= x && right <= y) {
            tree[ind].lower_bound = max(tree[ind].lower_bound, lower_bound);
            tree[ind].m = max(tree[ind].m, tree[ind].lower_bound);
            return;
        }
        pushdown(ind);
        const int mid = (left + right) >> 1;
        if (x <= mid) {
            update(ind << 1, left, mid, x, y, lower_bound);
        }
        if (y > mid) {
            update((ind << 1) | 1, mid + 1, right, x, y, lower_bound);
        } 
        pushup(ind);
    }
    
    void update(int ind, int left, int right, int x, int v) {

        if (left >= x && right <= x) {
            tree[ind].lower_bound = 0;
            tree[ind].m = v;
            return;
        }
        pushdown(ind);
        const int mid = (left + right) >> 1;
        if (x <= mid) {
            update(ind << 1, left, mid, x, v);
        } else {
            update((ind << 1) | 1, mid + 1, right, x, v);
        } 
        pushup(ind);
    }
};

 
int solution(vector<int> &X, vector<int> &Y, string &T) {
    const int n = X.size();
    unordered_map<int, unordered_set<int>> havex;
    map<int, map<int, int>> havey;
    map<int, int> cx;
    const int ind = T.find('X');
    for (int i = 0; i < n; ++i) {
        const int x = X[i], y = Y[i];
        X[i] = (x + y) / 2;
        Y[i] = (y - x) / 2;
    }
    for (int i = 0; i < n; ++i) {
        if (i == ind || X[i] < X[ind] || Y[i] < Y[ind]) {
            continue;
        }
        havex[X[i]].insert(Y[i]);
        havey[Y[i]][X[i]] = (T[i] == 'p' ? 1 : 10);
        ++cx[X[i]];
        ++cx[X[i] + 1];
        if (X[i] - 1 >= X[ind]) {
            ++cx[X[i] - 1];
        }
    }
    if (havex.count(X[ind]) == 0 && havey.count(Y[ind]) == 0) {
        return 0;
    }
    ++cx[X[ind]];
    int LX = 1;
    for (auto& p : cx) {
        p.second = ++LX;
    }
    ++LX;
    int last = 0;
    segmentTree up(LX + 1), right(LX + 1);
    for (auto ty = havey.rbegin(); ty != havey.rend(); ++ty) {
        const int y = ty->first;
        vector<pair<int, int>> vx;
        for (auto tx = ty->second.begin(); tx != ty->second.end(); ++tx) {
            vx.push_back(*tx);
        }
        last = 0;
        for (int i = vx.size() - 1, x3 = LX; i >= 0; --i) {
            const int x2 = cx[vx[i].first];
            if (havex[vx[i].first].count(y + 1) || havex[vx[i].first].count(y - 1)) {
                up.update(1, 0, LX, x2, 0);
            } else {
                const int v = max(right.query(1, 0, LX, x2, x2), up.query(1, 0, LX, x2, x2)) + vx[i].second;
                up.update(1, 0, LX, x2, v);
            }
            right.update(1, 0, LX, x2, 0);
            const int x1 = i ? cx[vx[i - 1].first] : 0;

            if (x2 > x1 + 1 && x3 > x2 + 1) {
                last = max(last, up.query(1, 0, LX, x2 + 1, x3 - 1)) + vx[i].second;
                right.update(1, 0, LX, x1 + 1, x2 - 1, last);
            } else {
                last = 0;
            }
            x3 = x2;
        }
    }
    if (havey.begin()->first != Y[ind]) {
        last = 0;
    }
    if (havex.count(X[ind])) {
        last = max(last, up.query(1, 0, LX, 2, 2));
    }
    return last; 
}
