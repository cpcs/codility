John takes computer security very seriously, so he has picked a very long password to secure his files. However, although the password is very strong, it is also hard to memorize.

John decides to create a new password which is easier to remember. Therefore, it must fulfill certain requirements: he wants each character (digit or letter) to appear in the new password an even number of times (possibly zero). Also, since he is so proud of his original password, he wants the new password to be a contiguous substring of the original password.

John has trouble finding such a substring. Help him by finding, for a given string, the length of the longest substring that fulfills the requirements set out above.

Write a function:

int solution(string &S);

that, given a non-empty string S consisting of N characters, returns the length of the longest contiguous substring (possibly empty) of string S in which every character occurs an even number of times.

For example, given S = "6daa6ccaaa6d", the function should return 8. The longest valid password taken from S is "a6ccaaa6"; it contains four letters a, and two each of the digit 6 and letter c. Any longer substring must contain either five letters a or one letter d. Given S = "abca", the function should return 0 (note that aa is not a contiguous substring of S).

Write an efficient algorithm for the following assumptions:

the length of string S is within the range [1..100,000];
S consists only of lowercase letters and digits.
