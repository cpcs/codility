A non-empty array A consisting of N integers is given. A pair of integers (P, Q), such that 0 ≤ P ≤ Q < N, is called a slice of array A. The sum of a slice (P, Q) is the total of A[P] + A[P+1] + ... + A[Q]. The maximum sum is the maximum sum of any slice of A.

For example, consider array A such that:

    A[0] = 3
    A[1] = 2
    A[2] = -6
    A[3] = 3
    A[4] = 1
For example (0, 1) is a slice of A that has sum A[0] + A[1] = 5. This is the maximum sum of A.

You can perform a single swap operation in array A. This operation takes two indices I and J, such that 0 ≤ I ≤ J < N, and exchanges the values of A[I] and A[J]. The goal is to find the maximum sum you can achieve after performing a single swap.

For example, after swapping elements 2 and 4, you will get the following array A:

    A[0] = 3
    A[1] = 2
    A[2] = 1
    A[3] = 3
    A[4] = -6
After that, (0, 3) is a slice of A that has the sum A[0] + A[1] + A[2] + A[3] = 9. This is the maximum possible sum of A after a single swap.

Write a function:

int solution(vector<int> &A);

that, given a non-empty array A of N integers, returns the maximum possible sum of any slice of A after a single swap operation.

For example, given:

    A[0] = 3
    A[1] = 2
    A[2] = -6
    A[3] = 3
    A[4] = 1
the function should return 9, as explained above.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [1..100,000];
each element of array A is an integer within the range [−10,000..10,000].
