A prefix of a string S is any leading contiguous part of S. For example, "c" and "cod" are prefixes of the string "codility". For simplicity, we require prefixes to be non-empty.

The product of prefix P of string S is the number of occurrences of P multiplied by the length of P. More precisely, if prefix P consists of K characters and P occurs exactly T times in S, then the product equals K * T.

For example, S = "abababa" has the following prefixes:

* "a", whose product equals 1 * 4 = 4,
* "ab", whose product equals 2 * 3 = 6,
* "aba", whose product equals 3 * 3 = 9,
* "abab", whose product equals 4 * 2 = 8,
* "ababa", whose product equals 5 * 2 = 10
* "ababab", whose product equals 6 * 1 = 6,
* "abababa", whose product equals 7 * 1 = 7.

The longest prefix is identical to the original string. The goal is to choose such a prefix as maximizes the value of the product. In above example the maximal product is 10.

In this problem we consider only strings that consist of lower-case English letters (a−z).

Write a function

int solution(string &S);

that, given a string S consisting of N characters, returns the maximal product of any prefix of the given string. If the product is greater than 1,000,000,000 the function should return 1,000,000,000.

For example, for a string:

S = "abababa" the function should return 10, as explained above,
S = "aaa" the function should return 4, as the product of the prefix "aa" is maximal.
Write an efficient algorithm for the following assumptions:

N is an integer within the range [1..300,000];
string S is made only of lowercase letters (a−z).
