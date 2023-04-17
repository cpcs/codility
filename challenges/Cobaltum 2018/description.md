You have two sequences A and B consisting of integers, both of length N, and you would like them to be (strictly) increasing, i.e. for each K (0 ≤ K < N − 1), A[K] < A[K + 1] and B[K] < B[K + 1]. Thus, you need to modify the sequences, but the only manipulation you can perform is to swap an arbitrary element in sequence A with the corresponding element in sequence B. That is, both elements to be exchanged must occupy the same index position within each sequence.

For example, given A = [5, 3, 7, 7, 10] and B = [1, 6, 6, 9, 9], you can swap elements at positions 1 and 3, obtaining A = [5, 6, 7, 9, 10], B = [1, 3, 6, 7, 9].

Your goal is make both sequences increasing, using the smallest number of moves.

Write a function:

int solution(vector<int> &A, vector<int> &B);

that, given two arrays A, B of length N, containing integers, returns the minimum number of swapping operations required to make the given arrays increasing. If it is impossible to achieve the goal, return −1.

For example, given:

A[0] = 5        B[0] = 1   
A[1] = 3        B[1] = 6   
A[2] = 7        B[2] = 6   
A[1] = 3        B[1] = 6   
A[3] = 7        B[3] = 9   
A[4] = 10       B[4] = 9   
  
your function should return 2, as explained above.

Given:

A[0] = 5        B[0] = 2   
A[1] = -3       B[1] = 6      
A[2] = 6        B[2] = -5   
A[3] = 4        B[3] = 1   
A[4] = 8        B[4] = 0   
your function should return −1, since you cannot perform operations that would make the sequences become increasing.

Given:

A[0] = 1        B[0] = -2   
A[1] = 5        B[1] = 0   
A[2] = 6        B[2] = 2   
your function should return 0, since the sequences are already increasing.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [2..100,000];
each element of arrays A and B is an integer within the range [−1,000,000,000..1,000,000,000];
A and B have equal lengths.
