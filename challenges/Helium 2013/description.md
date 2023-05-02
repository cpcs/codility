A prefix of a string S is any leading contiguous part of S. A suffix of the string S is any trailing contiguous part of S. For example, "c" and "cod" are prefixes, and "ty" and "ity" are suffixes of the string "codility". For simplicity, we require prefixes and suffixes to be non-empty and shorter than the whole string S.

A border of a string S is any string that is both a prefix and a suffix. For example, "cut" is a border of a string "cutletcut", and a string "barbararhubarb" has two borders: "b" and "barb".

We are looking for such borders of S that have at least three non-overlapping occurrences; that is, for some string that occurs as a prefix, as a suffix and elsewhere in between. For example, for S = "barbararhubarb", the only such string is "b".

In this problem we consider only strings that consist of lower-case English letters (a−z).

Write a function:

int solution(string &S);

that, given a string S consisting of N characters, returns the length of its longest border that has at least three non-overlapping occurrences in the given string. If there is no such border in S, the function should return 0.

For example, given a string S as follows:

if S = "barbararhubarb" the function should return 1, as explained above;
if S = "ababab" the function should return 2, as "ab" and "abab" are both borders of S, but only "ab" has three non-overlapping occurrences;
if S = "baaab" the function should return 0, as its only border "b" occurs only twice.
Write an efficient algorithm for the following assumptions:

N is an integer within the range [0..1,000,000];

string S is made only of lowercase letters (a−z).
