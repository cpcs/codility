// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

/*

Naive algorithm should be:

def solution(H):
    MOD = 1000000007
    N = len(H)
    nests = [(height, index) for index, height in enumerate(H)]
    nests.sort()
    dp_left = [0] * N
    dp_right = [0] * N
    total = 0

    for nest in nests:
        index = nest[1]

        # Add 1 way for the current nest
        total += 1

        # Add all possible ways reaching this nest from the left
        for i in range(index):
            total += dp_left[i]
            total %= MOD

        # Add all possible ways reaching this nest from the right
        for i in range(index + 1, N):
            total += dp_right[i]
            total %= MOD

        # Initialize left and right ways to 1 for the current nest
        dp_right[index] = 1
        dp_left[index] = 1

        # Update the right possible ways for nests to the left
        for i in range(index):
            dp_right[i] += dp_left[i]
            dp_right[i] %= MOD

        # Update the left possible ways for nests to the right
        for i in range(index + 1, N):
            dp_left[i] += dp_right[i]
            dp_left[i] %= MOD

    return total % MOD

  
    */

#include <bits/stdc++.h>

using namespace std;

const int M = 1000000007;

int add(int x, int y) {
    if ((x += y) >= M) {
        x -= M;
    }
    return x;
}

void sum(int &x, int y) {
    x = add(x, y);
}

int mul(long long x, long long y) {
    return x * y % M;
}

struct node {
    int leftStart;
    int rightStart;
    int total;
    // lazy fields:
    // LL: leftStart adds into leftStart
    // LR: leftStart adds into rightStrart
    // RL: righttStart adds into leftStrart
    // RR: rightStart adds into rightStrart
    int LL, LR, RL, RR;

    node() : leftStart(0), rightStart(0), total(0), LL(0), LR(0), RL(0), RR(0) {}
};


struct segmentTree {
public:
vector<node> tree;

    segmentTree(int n) : tree(vector<node>(n << 2)) {}

    
    void godown(const node& parent, node& child) {
        const int childRRUpdate = add(add(parent.RR , mul(parent.RR, child.RR)), 
                                      mul(parent.LR, child.RL));
        const int childLRUpdate = add(add(parent.LR, mul(parent.LR, child.LL)),
                                      mul(child.LR, parent.RR));
        const int childLLUpdate = add(add(parent.LL, mul(parent.LL, child.LL)),
                                      mul(parent.RL, child.LR));
        const int childRLUpdate = add(add(parent.RL, mul(parent.RL, child.RR)), 
                                      mul(child.RL, parent.LL));
        sum(child.RR, childRRUpdate);
        sum(child.LR, childLRUpdate);
        sum(child.LL, childLLUpdate);
        sum(child.RL, childRLUpdate);
    
    }
    void pushdown(int i ,int x, int y) {
        if (tree[i].LL || tree[i].LR || tree[i].RL || tree[i].RR) {
            const int updateRight = add(mul(tree[i].RR, tree[i].rightStart),
            mul(tree[i].LR, tree[i].leftStart));
            const int updateLeft = add(mul(tree[i].RL, tree[i].rightStart),
            mul(tree[i].LL, tree[i].leftStart));
            sum(tree[i].rightStart, updateRight);
            sum(tree[i].leftStart, updateLeft);
            if (x < y) {
                const int left = i << 1, right = left | 1;
                godown(tree[i], tree[left]);
                godown(tree[i], tree[right]);
            }
            tree[i].LL = tree[i].LR = tree[i].RL = tree[i].RR = 0;
        }
    }
    
    void pushup(int i) {
        const int lson = i << 1, rson = lson | 1;
        sum(tree[i].total = tree[lson].total, tree[rson].total);
        sum(tree[i].leftStart = tree[lson].leftStart, tree[rson].leftStart);
        sum(tree[i].rightStart = tree[lson].rightStart, tree[rson].rightStart);
    }

    void update(int i, int left, int right, int x, int y, int mode, int total = 0) {
        pushdown(i, left, right);
        const int lson = i << 1, rson = lson | 1;
        if (left >= x && right <= y) {
            switch(mode) {
                // Left
                case 0:
                    sum(tree[i].leftStart, tree[i].rightStart);
                    break;
                // Right
                case 1:
                    sum(tree[i].rightStart, tree[i].leftStart);
                    break;
                // total
                case 2:
                    sum(tree[i].total, total);
                    sum(tree[i].leftStart, 1);
                    sum(tree[i].rightStart, 1);

            }
            if (x < y) {
                //leftStart += rightStart
                // When Update R: LR += 1 + LL; RR += RL
                // When Update L: RL += 1 + RR; LL += LR
                switch(mode) {
                    // Left
                    case 0:
                        sum(tree[lson].RL, tree[lson].RR);
                        sum(tree[lson].RL, 1);
                        sum(tree[lson].LL, tree[lson].LR);
                        sum(tree[rson].RL, tree[rson].RR);
                        sum(tree[rson].RL, 1);
                        sum(tree[rson].LL, tree[rson].LR);
                        break;
                    // Right
                    case 1:
                        sum(tree[lson].LR ,tree[lson].LL);
                        sum(tree[lson].LR, 1);
                        sum(tree[lson].RR, tree[lson].RL);
                        sum(tree[rson].LR, tree[rson].LL);
                        sum(tree[rson].LR, 1);
                        sum(tree[rson].RR, tree[rson].RL);
                        break;
                }
            }
            return;
        }
        
        const int mid = (left + right) >> 1;
        if (x <= mid) {
            update(lson, left, mid, x, y, mode, total);
        }
        if (y > mid) {
            update(rson, mid + 1, right, x, y, mode, total);
        } 
        pushup(i);
    }

    int query(int i, int left, int right, int x, int y, int mode) {
        pushdown(i, left, right);
        if (left >= x && right <= y) {
            switch(mode) {
                case 0:
                    return tree[i].leftStart;
                case 1:
                    return tree[i].rightStart;
                case 2:
                    return tree[i].total;
                default:
                    return 0;
            }
        }
        int r = 0;
        const int mid = (left + right) >> 1;
        if (x <= mid) {
            r = query(i << 1, left, mid, x, y, mode);
        }
        if (y > mid) {
            sum(r, query((i << 1) | 1, mid + 1, right, x, y, mode));
        } 
        return r;
    }
};

 
// H = [ 13, 2, 5 ]
// output = 7.

// H = [ 4, 6, 2, 1, 5 ]
// output = 23
    

int solution(vector<int> &H) {
    // Implement your solution here
    const int n = H.size();
    vector<int> ind(n);
    for (int i = 0; i < n; ++i) {
        ind[i] = i;
    }
    sort(ind.begin(), ind.end(), [&](const int x, const int y) {
        return H[x] < H[y];
    });
    // left[i] the number of ways to start from nested i and ending on the left side.
    segmentTree tree(n << 2);
    for (int i = 0; i < n; ++i) {
        const int sumLeft = ind[i] ? tree.query(1, 0, n - 1, 0, ind[i] - 1, 0) : 0;
        const int sumRight = ind[i] + 1 < n ? tree.query(1, 0, n - 1, ind[i] + 1, n - 1, 1) : 0;
        const int total = add(add(sumLeft, sumRight), 1);
        tree.update(1, 0, n - 1, ind[i], ind[i], 2, total);
        if (ind[i]) {
            tree.update(1, 0, n - 1, 0, ind[i] - 1, 1);
        }
        if (ind[i] + 1 < n) {
            tree.update(1, 0, n - 1, ind[i] + 1, n - 1, 0);
        }   
    }
    return tree.query(1, 0, n - 1, 0, n - 1, 2);
}
