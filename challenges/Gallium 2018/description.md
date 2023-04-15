Write a function:

int solution(vector<int> &A);

that, given an array of N positive integers, returns the maximum number of trailing zeros of the number obtained by multiplying three different elements from the array. Numbers are considered different if they are at different positions in the array.

For example, given A = [7, 15, 6, 20, 5, 10], the function should return 3 (you can obtain three trailing zeros by taking the product of numbers 15, 20 and 10 or 20, 5 and 10).

For another example, given A = [25, 10, 25, 10, 32], the function should return 4 (you can obtain four trailing zeros by taking the product of numbers 25, 25 and 32).

Write an efficient algorithm for the following assumptions:

N is an integer within the range [3..100,000];
each element of array A is an integer within the range [1..1,000,000,000].
