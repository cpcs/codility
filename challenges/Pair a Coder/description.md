You are given a string S consisting of N lowercase letters. In one move you can remove any substring (consistent fragment) from S, which starts and ends with the same letter and is at least two letters long. What is the minimum number of letters that may remain in S after any number of such moves?

Write a function:

int solution(string &S);

that, given a string S, returns the length of the shortest string that can be obtained from S by applying any number of moves as described above.

Examples:

1. Given S = "abccac", the function should return 1. After removing the substring "abcca", there will be a single letter "c" remaining.

2. Given S = "abcdabcdabcd" ("abcd" stated three times), the function should return 2. To achieve that, you can, for example, remove the first five letters from S ("abcda") in the first move, and the last five letters ("dabcd") in the second move. The remaining fragment would be "bc".

3. Given S = "axaabyab", the function should return 0. It is possible to remove all letters by removing the substring "axaa" in the first move, and then "byab" in the second.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [1..100,000];
string S is made only of lowercase letters (a−z).
