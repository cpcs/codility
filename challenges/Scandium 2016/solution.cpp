// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

string solution(vector<int> &A) {
    // Implement your solution here
    const int n = A.size();
    int first = -1, last2 = -1, m = 0, last1 = 0;
    for (int i = 0; i < n; ++i) {
        if (A[i] & 1) {
            ++m;
            if (first < 0) {
                first = last1;
            }
            last2 = last1;
            last1 = 0;
        } else {
            ++last1;
        }
    }
    if ((m & 1) == 0) {
        return "0," + to_string(n - 1);
    }
    if (m == 1) {
        if (first == last1) {
            return "NO SOLUTION";
        }
        return first > last1? 
        ("0," + to_string(first - last1 - 1))
        : (to_string(first + 1) + "," + to_string(last1));
    }
    // (first evens) ...... (last2 evens) odd (last1 evens)
    if (last2 >= last1) {
        return "0," + to_string(n - 2 - (last1 << 1));
    }
    if (first + last2 >= last1) {
        return to_string(last1 - last2) + "," + to_string(n - last1 - last2 - 2);
    }
    return to_string(first + 1) + "," + to_string(n - first - 1);
    
}
