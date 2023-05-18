Consider an array A of N integers. Indices of this array are integers from 0 to N−1. Take an index K. Index J is called an ascender of K if A[J] > A[K]. Note that if A[K] is a maximal value in the array A, then K has no ascenders.

Ascender J of K is called the closest ascender of K if abs(K−J) is the smallest possible value (that is, if the distance between J and K is minimal). Note that K can have at most two closest ascenders: one smaller and one larger than K.

For example, let us consider the following array A:

  A[0] = 4     A[1]  = 3    A[2]  = 1  
  A[3] = 4     A[4]  = -1   A[5]  = 2  
  A[6] = 1     A[7]  = 5    A[8]  = 7  
  
If K = 3 then K has two ascenders: 7 and 8. Its closest ascender is 7 and distance between K and 7 equals abs(K−7) = 4.

Write a function:

vector<int> solution(vector<int> &A);

that, given an array A of N integers, returns an array R of N integers, such that (for K = 0,..., N−1):

if K has the closest ascender J, then R[K] = abs(K−J); that is, R[K] is equal to the distance between J and K,
if K has no ascenders then R[K] = 0.
For example, given the following array A:

  A[0] = 4     A[1]  = 3    A[2]  = 1  
  A[3] = 4     A[4]  = -1   A[5]  = 2  
  A[6] = 1     A[7]  = 5    A[8]  = 7  
  
the function should return the following array R:

  R[0] = 7     R[1]  = 1    R[2]  = 1  
  R[3] = 4     R[4]  = 1    R[5]  = 2  
  R[6] = 1     R[7]  = 1    R[8]  = 0  
  
Result array should be returned as a vector of integers.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [0..50,000];  
each element of array A is an integer within the range [−1,000,000,000..1,000,000,000].  
