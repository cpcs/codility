Integers K, M and a non-empty array A consisting of N integers, not bigger than M, are given.

The leader of the array is a value that occurs in more than half of the elements of the array, and the segment of the array is a sequence of consecutive elements of the array.

You can modify A by choosing exactly one segment of length K and increasing by 1 every element within that segment.

The goal is to find all of the numbers that may become a leader after performing exactly one array modification as described above.

Write a function:

vector<int> solution(int K, int M, vector<int> &A);

that, given integers K and M and an array A consisting of N integers, returns an array of all numbers that can become a leader, after increasing by 1 every element of exactly one segment of A of length K. The returned array should be sorted in ascending order, and if there is no number that can become a leader, you should return an empty array. Moreover, if there are multiple ways of choosing a segment to turn some number into a leader, then this particular number should appear in an output array only once.

For example, given integers K = 3, M = 5 and the following array A:

  A[0] = 2
  A[1] = 1
  A[2] = 3
  A[3] = 1
  A[4] = 2
  A[5] = 2
  A[6] = 3
the function should return [2, 3]. If we choose segment A[1], A[2], A[3] then we get the following array A:

  A[0] = 2
  A[1] = 2
  A[2] = 4
  A[3] = 2
  A[4] = 2
  A[5] = 2
  A[6] = 3
and 2 is the leader of this array. If we choose A[3], A[4], A[5] then A will appear as follows:

  A[0] = 2
  A[1] = 1
  A[2] = 3
  A[3] = 2
  A[4] = 3
  A[5] = 3
  A[6] = 3
and 3 will be the leader.

And, for example, given integers K = 4, M = 2 and the following array:

  A[0] = 1
  A[1] = 2
  A[2] = 2
  A[3] = 1
  A[4] = 2
the function should return [2, 3], because choosing a segment A[0], A[1], A[2], A[3] and A[1], A[2], A[3], A[4] turns 2 and 3 into the leaders, respectively.

Write an efficient algorithm for the following assumptions:

N and M are integers within the range [1..100,000];
K is an integer within the range [1..N];
each element of array A is an integer within the range [1..M].
