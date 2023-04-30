The city of Codicity is located at the seaside. The city area comprises N plots located along a boulevard on one side of the city. Each plot is flat, but different plots have different heights above the sea level. The relative heights of the consecutive plots are given in the form of a non-empty array A of N integers.

The sea level changes constantly and many plots are sometimes under water. Water levels on consecutive days are given in the form of a non-empty array B of M integers.

A slice of array A is any pair of integers (P, Q) such that 0 ≤ P ≤ Q < N. An island is a slice of consecutive plots that rise above the water’s surface. The plots on either side of each island are under water. More precisely, if the level of the water is K, then an island is a slice (P, Q) in which the level of each plot A[P], A[P + 1], ..., A[Q] is greater than K. Both of the adjacent plots should also be under water; that is:

P = 0 or A[P − 1] ≤ K
Q = N − 1 or A[Q + 1] ≤ K
The goal is to calculate the number of islands on consecutive days.

For example, given the following arrays A and B:

    A[0] = 2    B[0] = 0
    A[1] = 1    B[1] = 1
    A[2] = 3    B[2] = 2
    A[3] = 2    B[3] = 3
    A[4] = 3    B[4] = 1
We have the following number of islands on consecutive days:

on the first day there is only 1 island: (0, 4),
on the second day there are 2 islands: (0, 0) and (2, 4),
on the third day there are 2 islands: (2, 2) and (4, 4),
on the fourth day there aren't any islands,
on the fifth day there are 2 islands: (0, 0) and (2, 4).
Write a function:

vector<int> solution(vector<int> &A, vector<int> &B);

that, given a non-empty array A of N integers and a non-empty array B of M integers, returns a sequence consisting of M integers representing the number of islands on consecutive days.

Result array should be returned as a vector of integers.

For example, given:

    A[0] = 2    B[0] = 0
    A[1] = 1    B[1] = 1
    A[2] = 3    B[2] = 2
    A[3] = 2    B[3] = 3
    A[4] = 3    B[4] = 1
the function should return the array [1, 2, 2, 0, 2], as explained above.

Write an efficient algorithm for the following assumptions:

N and M are integers within the range [1..30,000];
each element of arrays A and B is an integer within the range [0..100,000].
