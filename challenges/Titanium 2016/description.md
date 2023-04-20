A bracket sequence is considered to be a valid bracket expression if any of the following conditions is true:

it is empty;
it has the form "(U)" where U is a valid bracket sequence;
it has the form "VW" where V and W are valid bracket sequences.
For example, the sequence "(())()" is a valid bracket expression, but "((())(()" is not.

You are given a sequence of brackets S and you are allowed to rotate some of them. Bracket rotation means picking a single bracket and changing it into its opposite form (i.e. an opening bracket can be changed into a closing bracket and vice versa). The goal is to find the longest slice (contiguous substring) of S that forms a valid bracket sequence using at most K bracket rotations.

Write a function:

int solution(string &S, int K);

that, given a string S consisting of N brackets and an integer K, returns the length of the maximum slice of S that can be transformed into a valid bracket sequence by performing at most K bracket rotations.

For example, given S = ")()()(" and K = 3, you can rotate the first and last brackets to get "(()())", which is a valid bracket sequence, so the function should return 6 (notice that you need to perform only two rotations in this instance, though).

Given S = ")))(((" and K = 2, you can rotate the second and fifth brackets to get ")()()(", which has a substring "()()" that is a valid bracket sequence, so the function should return 4.

Given S = ")))(((" and K = 0, you can't rotate any brackets, and since there is no valid bracket sequence with a positive length in string S, the function should return 0.

Write an efficient algorithm for the following assumptions:

string S contains only brackets: '(' or ')';
N is an integer within the range [1..30,000];
K is an integer within the range [0..N].
