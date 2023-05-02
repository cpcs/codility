A non-empty array A consisting of N integers is given. A prefix suffix set is a pair of indices (P, S) such that 0 ≤ P, S < N and such that:

every value that occurs in the sequence A[0], A[1], ..., A[P] also occurs in the sequence A[S], A[S + 1], ..., A[N − 1],
every value that occurs in the sequence A[S], A[S + 1], ..., A[N − 1] also occurs in the sequence A[0], A[1], ..., A[P].
The goal is to calculate the number of prefix suffix sets in the array.

For example, consider array A such that:

    A[0] = 3
    A[1] = 5
    A[2] = 7
    A[3] = 3
    A[4] = 3
    A[5] = 5
There are exactly fourteen prefix suffix sets: (1, 4), (1, 3), (2, 2), (2, 1), (2, 0), (3, 2), (3, 1), (3, 0), (4, 2), (4, 1), (4, 0), (5, 2), (5, 1), (5, 0).

Write a function:

int solution(vector<int> &A);

that, given a non-empty array A of N integers, returns the number of prefix suffix sets.

If the number of prefix suffix sets is greater than 1,000,000,000, the function should return 1,000,000,000.

For example, given:

    A[0] = 3
    A[1] = 5
    A[2] = 7
    A[3] = 3
    A[4] = 3
    A[5] = 5
the function should return 14, as explained above.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [1..40,000];
  
each element of array A is an integer within the range [−1,000,000,000..1,000,000,000].
