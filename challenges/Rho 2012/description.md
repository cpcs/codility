Do you like puzzles? Here is one for you. You are given a positive integer A. The goal is to construct the shortest possible sequence of integers ending with A, using the following rules:

the first element of the sequence is 1,
each of the successive elements is the sum of any two preceding elements (adding a single element to itself is also permissible),
each element is larger than all the preceding elements; that is, the sequence is increasing.
For example, for A = 42, a possible solution is [1, 2, 3, 6, 12, 24, 30, 42]. Another possible solution is [1, 2, 4, 5,  8, 16, 21, 42].

Write a function:

vector<int> solution(int A);

that, given an integer A, returns the shortest possible sequence of integers satisfying the above conditions and ending with A.
Result array should be returned as a vector of integers.

For example, given A = 42, the function may return the sequence [1, 2, 3, 6, 12, 24, 30, 42], as explained above.

Write an efficient algorithm for the following assumptions:

A is an integer within the range [1..600].
  
