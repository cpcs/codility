// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <algorithm>
using namespace std;

int solution(vector<int> &X, vector<int> &Y) {
    // Implement your solution here
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());
    long long r = 0;
    for (int i = 0; i < X.size(); ++i) {
        r += abs(X[i] - i - 1) + abs(Y[i] - i - 1);
    }
    return r % 1000000007;
}
