// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <bits/stdc++.h>
using namespace std;

int getf(vector<int> &f, int x) {
    return f[x] == x ? x : (f[x] = getf(f, f[x]));
}

void merge(vector<int> &f, vector<int> &num, int x, int y) {
    x = getf(f, x);
    y = getf(f, y);
    if (x == y) {
        return;
    }
    if (num[x] < num[y]) {
        swap(x, y);
    }
    num[x] += num[y];
    f[y] = x;
}

int solution(int K, vector<int> &C, vector<int> &D) {
    // Implement your solution here
    const int n = C.size();
    if (K == n) {
        return n;
    }
    vector<int> f(n), num(n);
    map<int, vector<int>> e;
    for (int i = 0; i < n; ++i) {
        f[i] = i;
        num[i] = 1;
        e[D[i]].push_back(i);
    }
    vector<vector<int>> con(n);
    for (int i = 0; i < n; ++i) {
        if (i != C[i]) {
            con[i].push_back(C[i]);
            con[C[i]].push_back(i);
        }
    }
    vector<bool> mark(n);
    const int p = e.rbegin()->second[0];
    int r = 0, s = 0;
    for (auto t = e.rbegin(); r < K && t != e.rend(); ++t) {
        // Add all nodes with the same weight.
        for (int x : t->second) {
            for (int y : con[x]) {
                if (mark[y]) {
                    merge(f, num, x, y);
                }

            }
            mark[x] = true;
        }
        s += t->second.size();
        // If these are nodes with the maximum weights.
        if (t == e.rbegin()) {
            for (int x : t->second) {
                r = max(r, min(K, num[getf(f, x)]));
            }
            continue;
        }
        // Now we need to consider how many nodes are not in the "main" tree
        // (main tree is the tree with the maximum weight nodes)
        int non = 0;
        for (int x : t->second) {
            if (getf(f, x) != getf(f, p)) {
                ++non;
            }
        }
        // For the current weight (smallest so far), non of them are not in the 
        // "main" tree. The main tree should have s - non nodes meaning all
        // other nodes (that have larger weights) are in the main tree.
        int have = s - non;
        // All on the same tree
        if (num[getf(f, p)] == have) {
            if (have <= K) {
                r = have;
            } else {
                // We add more nodes, now we should delete leaf nodes the 
                // deleted leaves must have the same weight (current minimum weight).
                vector<unordered_set<int>> c(n);
                for (auto temp = e.rbegin();; ++temp) {
                    for (int x : temp->second) {
                        for (int y : con[x]) {
                            if (getf(f, p) == getf(f, y)) {
                                c[x].insert(y);
                                c[y].insert(x);
                            }
                        }
                    }
                    if (temp == t) {
                        break;
                    }
                }
                queue<int> leaves;
                for (int i = 0; i < n; ++i) {
                    if (c[i].size() == 1 && D[i] == t->first) {
                        leaves.push(i);
                    }
                }
                for (; have > K && !leaves.empty(); --have) {
                    const int leaf = leaves.front();
                    leaves.pop();
                    const int other = *c[leaf].begin();
                    c[other].erase(leaf);
                    if (c[other].size() == 1 && D[other] == t->first) {
                        leaves.push(other);
                    }
                }
                if (have <= K) {
                    // Here, have should == K.
                    r = have;
                }
                // No need to try adding nodes with smaller weights.
                break;
            }

        }
    }
    return r;
}
