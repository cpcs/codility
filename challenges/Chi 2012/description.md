A new kind of cannon is being tested. The cannon shoots cannonballs in a fixed direction. Each cannonball flies horizontally until it hits the ground, and then it rests there. Cannonballs are shot from different heights, so they hit the ground at different points.

You are given two arrays, A and B, containing M and N integers respectively. Array A describes the landscape in the direction along which the cannon is shooting. Elements of array A represent the height of the ground, going from the cannon outwards. Array B contains levels from which consecutive cannonballs are shot.

Assume that a cannonball is shot at level H.

Let I be the smallest index, such that 0 < I < M and A[I] ≥ H. The cannonball falls at position I − 1 and increases the ground level A[I−1] by 1.
If there is no such I, and H > A[I] for all 0 ≤ I < M, then the cannonball flies beyond the horizon and has no effect on the result.
If H ≤ A[0], then the cannonball ricochets away and has no effect on the result either.
Write a function:

vector<int> solution(vector<int> &A, vector<int> &B);

that, given arrays A and B, simulates the flight of the cannonballs and returns the final contents of array A (denoted by A1) representing the final shape of the ground along the line of fire.

For example, given the following arrays A and B, of size M = 9 and N = 11 respectively:

  A[0] = 1    A[1] = 2    A[2] = 0  
  A[3] = 4    A[4] = 3    A[5] = 2  
  A[6] = 1    A[7] = 5    A[8] = 7  

  B[0] = 2    B[1] = 8    B[2] = 0  
  B[3] = 7    B[4] = 6    B[5] = 5   
  B[6] = 3    B[7] = 4    B[8] = 5  
  B[9] = 6    B[10]= 5  
the function should return the following array A1 of M = 9 integers:

  A1[0] = 2    A1[1] = 2    A1[2] = 2  
  A1[3] = 4    A1[4] = 3    A1[5] = 3   
  A1[6] = 5    A1[7] = 6    A1[8] = 7  
Write an efficient algorithm for the following assumptions:

M and N are integers within the range [0..30,000];  
each element of arrays A 
