You are given a string S consisting of letters 'a' and 'b'. The task is to rearrange letters in S so that it contains three consecutive letters 'a' and three consecutive letters 'b'. What is the minimum necessary number of swaps of neighbouring letters to achieve this?

Write a function:

int solution(string &S);

that, given a string S of length N, returns the number of swaps after which S would contain "aaa" and "bbb" as substrings. If it's not possible to rearrange the letters in such a way, the function should return −1.

Examples:

1. Given S = "ababab", the function should return 3. The sequence of swaps could be as follows: ababab → abaabb → aababb → aaabbb.

2. Given S = "abbbbaa", the function should return 4. The sequence of four swaps is: abbbbaa → babbbaa → bbabbaa → bbbabaa → bbbbaaa.

3. Given S = "bbbababaaab", the function should return 0. S already contains both "aaa" and "bbb" as substrings.

4. Given S = "abbabb", the function should return −1. It is not possible to obtain the required result from S as there are only two letters 'a'.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [1..100,000];
string S is made only of the characters 'a' and/or 'b'.
