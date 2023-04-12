// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <bits/stdc++.h>

using namespace std;

struct node {
    int start;
    int len;

    node(int start, int len) : start(start), len(len) {}
    node() : node(0, 0) {}
    
};


struct segmentTree {
private:
    node merge(const node& n1, const node &n2) {
        if (n1.len < 0) {
            return n1;
        }
        if (n2.len < 0) {
            return n2;
        }
        if (n1.len == 0) {
            return n2;
        }
        if (n2.len == 0) {
            return n1;
        }
        if (n1.start + n1.len == n2.start) {
            return {n1.start, n1.len + n2.len};
        }
        return {0, -1};
    }
public:
vector<node> tree;

   segmentTree(int n) : tree(vector<node>(n << 2)) {}

    void pushdown(int i) {
        if (tree[i].len == 0) {
            return;
        }
        const int left = i << 1, right = left | 1;
        tree[left] = merge(tree[left], tree[i]);
        tree[right] = merge(tree[right], tree[i]);
        tree[i] = {0, 0};
    }

    bool query(int ind, int left, int right, int x, int k) {
        if (left >= x && right <= x) {
            return tree[ind].start == 1 && tree[ind].len == k;
        }
        pushdown(ind);
        const int mid = (left + right) >> 1;
        return x <= mid ? query(ind << 1, left, mid, x, k) : query((ind << 1) | 1, mid + 1, right, x, k);
    }

    void update(int ind, int left, int right, int x, int y, int c) {
        if (left >= x && right <= y) {
            tree[ind] = merge(tree[ind], {c, 1});
            return;
        }
        pushdown(ind);
        const int mid = (left + right) >> 1;
        if (x <= mid) {
            update(ind << 1, left, mid, x, y, c);
        }
        if (y > mid) {
            update((ind << 1) | 1, mid + 1, right, x, y, c);
        } 
    }
};

int solution(int N, int K, vector<int> &A, vector<int> &B, vector<int> &C) {
    // Implement your solution here
    segmentTree tree(N);
    for (int i = 0; i < A.size(); ++i) {
        tree.update(1, 1, N, A[i], B[i], C[i]);
    }
    int r = 0;
    for (int i = 1; i <= N; ++i) {
        r += tree.query(1, 1, N, i, K);
    }
    return r;
}
