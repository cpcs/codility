There are N buckets numbered from 0 to N−1. There are also M balls of different colors, numbered from 0 to M−1. The K-th ball has color C[K]. For simplicity we denote each color by an integer.

Initially all buckets are empty. At moment K (for K from 0 to M−1), we put the K-th ball into bucket B[K].

Calculate the earliest moment when there are at least Q balls of the same color in some bucket.

Write a function:

int solution(int N, int Q, vector<int> &B, vector<int> &C);

that, given two integers N and Q, and two arrays B and C consisting of M integers each, returns the earliest moment in which there is some bucket with at least Q balls of the same color. The function should return −1 if no such moment occurs.

Examples:

1. Given N = 3, Q = 2, B = [1, 2, 0, 1, 1, 0, 0, 1] and C = [0, 3, 0, 2, 0, 3, 0, 0], the function should return 4. At moment 3 we have a ball of color 0 in bucket 0, balls of colors 0 and 2 in bucket 1, and a ball of color 3 in bucket 2. At moment 4 we put another ball of color 0 into bucket 1, and there are thus two balls of the same color in this bucket.

2. Given N = 2, Q = 2, B = [0, 1] and C = [5, 5], the function should return −1. There is no moment in which there is some bucket with at least 2 balls of the same color.

3. Given N = 2, Q = 2, B = [0, 1, 0, 1, 0, 1] and C = [1, 3, 0, 0, 3, 3], the function should return 5.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [1..1,000,000];
Q and M are integers within the range [1..100,000];
each element of array B is an integer within the range [0..N-1];
each element of array C is an integer within the range [0..1,000,000].
