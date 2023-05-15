Neverland has very interesting topography. It is a flat land, but it seems to be the surface of a torus. That is, its map is a rectangle, but its northern edge is adjacent to its southern edge and, at the same time, its western edge is adjacent to its eastern edge. That is why it is so difficult to escape from Neverland...

Recently, the land in Neverland has gone up for sale. It has been divided into a grid of unit squares, comprising M rows and N columns. Rows are numbered on the map from 0 to M − 1, from north to south, and columns are numbered on the map from 0 to N − 1, from west to east. Row M − 1 is adjacent to row 0 and column N − 1 is adjacent to column 0.

You are allowed to buy one rectangular lot, which you plan to divide into smaller lots and sell for a profit. Note that your lot can overlap the edges of the map.

A zero-indexed matrix C of integers, consisting of M rows and N columns, is given. C[I][J] equals the expected profit that you can make on the unit square in row I and column J.

Write a function:

int solution(vector< vector<int> > &C);

that, given such a matrix C, returns the maximum possible profit that you can make. If there is no profitable lot for you to buy, the function should return 0.

For example, consider the following matrix C, consisting of three rows and three columns:

  C[0][0] = 1    C[0][1] = -1   C[0][2] = 2  
  C[1][0] = -1   C[1][1] = -1   C[1][2] = -1  
  C[2][0] = 3    C[2][1] = -1   C[2][2] = 4  
The unit squares in row 1 and column 1 are not profitable. Only the unit squares in the corners of the map are profitable, and they form a 2 × 2 square. So, this 2 × 2 square is the optimal lot, and the profit it can earn for you is 10.

Now consider the following matrix C, consisting of two rows and two columns:

  C[0][0] = 1     C[0][1] = -3  
  C[1][0] = -2    C[1][1] = 3  
In this example there are only two single unit square lots that are profitable, and the maximum profit is 3.

Write an efficient algorithm for the following assumptions:  

M and N are integers within the range [1..100];  
each element of matrix C is an integer within the range [−10,000..10,000].  
