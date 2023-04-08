A block is a word consisting of one type of letter. For example, aaaa and xx are blocks and bbbcc (two different letters) and xyz (three different letters) are not.

A string S consisting of N small letters from the English alphabet is given. We want to delete as few letters as possible from S to obtain a word composed of at most three blocks.

Write a function

int solution(string &S);

that, given a string S, returns the length of the longest word composed of at most three blocks, obtained by deleting some letters from S.

Examples:

1. Given S = "aabacbba", the function should return 6. After deleting letters 2 and 7 (counting from 0), we get "aaacbb" (composed of three blocks: "aaa|c|bb"). We can also obtain other solutions with six letters: "aaa|bb|a" and "aa|bbb|a".

2. Given S = "aabxbaba", the function should return 6. After deleting 'x' and the last 'b', we get "aabbaa" (composed of three blocks: "aa|bb|aa"). We can also obtain another solution with six letters: "aa|bbb|a".

3. Given S = "xxxyxxyyyxyyy", the function should return 11. After deleting the first 'y' and the last 'x', we get "xxxxxyyyyyy" (composed of two blocks: "xxxxx|yyyyyy"). It is the only solution in this case.

4. Given S = "atheaxbtheb", the function should return 5. The only solution is "aa|x|bb".

Write an efficient algorithm for the following assumptions:

N is an integer within the range [3..200,000];
string S is made only of lowercase letters (a−z).
