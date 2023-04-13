You are given a string S consisting of N characters and an integer K. You can modify string S by removing any substring of it. A substring is defined as a contiguous segment of a string.

The goal is to find the shortest substring of S that, after removal, leaves S containing exactly K different characters.

Write a function:

class Solution { public int solution(String S, int K); }

that, given a non-empty string S consisting of N characters and an integer K, returns the length of the shortest substring that can be removed. If there is no such substring, your function should return −1.

Examples:

1. Given S = "abaacbca" and K = 2, your function should return 3. After removing substring "cbc", string S will contain exactly two different characters: a and b.

2. Given S = "aabcabc" and K = 1, your function should return 5. After removing "bcabc", string S will contain exactly one character: a.

3. Given S = "zaaaa" and K = 1, your function should return 1. You can remove only one letter: z.

4. Given S = "aaaa" and K = 2, your function should return −1. There is no such substring of S that, after removal, leaves S containing exactly 2 different characters.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [1..1,000,000];
string S is made only of lowercase letters (a−z);
K is an integer within the range [0..26].
