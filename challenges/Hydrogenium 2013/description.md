There is no food in your fridge and you are hungry. You want to go to a local store and buy some food. You have to hurry as some of the shops will close soon.

There are N squares in your neighborhood and M direct roads connecting them. The squares are numbered from 0 to N − 1. You are living in square 0 and can reach it in 0 seconds. The stores are located in the squares, one in each of them. You are given a map of the neighborhood in the form of four zero-indexed arrays A, B, C and D. Each of the arrays A, B, C contains M integers, while D contains N integers.

For each I (0 ≤ I < M), the walking distance between squares A[I] and B[I] is C[I] seconds (in either direction).
There can be multiple roads connecting the same pair of squares, or a road with both ends entering the same square.
It is possible that some roads go through tunnels or over bridges (that is, the graph of squares and roads doesn't have to be planar).
It is not guaranteed that you are able to reach all the squares.
For each J (0 ≤ J < N), the shop at square J will close in D[J] seconds (if D[J] = −1, then the store is already closed);
it is possible to buy the food even if you reach the shop at the very last second, when it closes.
Write a function:

int solution(vector<int> &A, vector<int> &B, vector<int> &C, vector<int> &D);

that, given arrays A, B, C and D, returns the minimum time (in seconds) needed to reach an open store. If it is impossible, it should return −1.

For example, given:

  A[0] = 0    B[0] = 1    C[0] = 2    D[0] = -1   
  A[1] = 1    B[1] = 2    C[1] = 3    D[1] = 1  
  A[2] = 3    B[2] = 2    C[2] = 4    D[2] = 3  
  A[3] = 1    B[3] = 3    C[3] = 5    D[3] = 8  
  A[4] = 2    B[4] = 0    C[4] = 7 
  A[5] = 2    B[5] = 1    C[5] = 5 
  
  <img src="demo.png" align="center" />


the function should return 7. To reach the closest open shop you should follow the path: 0 −> 1 −> 3.

However, if given, for example:

  A[0] = 0     D[0] = -1
  B[0] = 1     D[1] = 6
  C[0] = 10    D[2] = 8
the function should return −1, as you will not be able to reach square 1 in less than 10 seconds, and you cannot reach square 2 at all.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [1..120];  
M is an integer within the range [0..N**2];  
each element of arrays A and B is an integer within the range [0..N - 1];  
each element of array C is an integer within the range [0..100,000];  
each element of array D is an integer within the range [−1..1,000,000,000].  
