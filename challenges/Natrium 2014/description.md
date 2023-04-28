A non-empty array A consisting of N integers is given.

A monotonic pair is a pair of integers (P, Q), such that 0 ≤ P ≤ Q < N and A[P] ≤ A[Q].

The goal is to find the monotonic pair whose indices are the furthest apart. More precisely, we should maximize the value Q − P. It is sufficient to find only the distance.

For example, consider array A such that:

    A[0] = 5
    A[1] = 3
    A[2] = 6
    A[3] = 3
    A[4] = 4
    A[5] = 2
There are eleven monotonic pairs: (0,0), (0, 2), (1, 1), (1, 2), (1, 3), (1, 4), (2, 2), (3, 3), (3, 4), (4, 4), (5, 5). The biggest distance is 3, in the pair (1, 4).

Write a function:

int solution(vector<int> &A);

that, given a non-empty array A of N integers, returns the biggest distance within any of the monotonic pairs.

For example, given:

    A[0] = 5
    A[1] = 3
    A[2] = 6
    A[3] = 3
    A[4] = 4
    A[5] = 2
the function should return 3, as explained above.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [1..300,000];
each element of array A is an integer within the range [−1,000,000,000..1,000,000,000].

  
