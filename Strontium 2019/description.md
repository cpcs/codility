An array of N words is given. Each word consists of small letters ('a' − 'z'). Our goal is to concatenate the words in such a way as to obtain a single word with the longest possible substring composed of one particular letter. Find the length of such a substring.

Write a function:

int solution(vector<string> &words);

that, given an array words containing N strings, returns the length of the longest substring of a word created as described above.

Examples:

1. Given N=3 and words=["aabb", "aaaa", "bbab"], your function should return 6. One of the best concatenations is words[1] + words[0] + words[2] = "aaaaaabbbbab". The longest substring is composed of letter 'a' and its length is 6.

2. Given N=3 and words=["xxbxx", "xbx", "x"], your function should return 4. One of the best concatenations is words[0] + words[2] + words[1] = "xxbxxxxbx". The longest substring is composed of letter 'x' and its length is 4.

3. Given N=4 and words=["dd", "bb", "cc", "dd"], your function should return 4. One of the best concatenations is words[0] + words[3] + words[1] + words[2] = "ddddbbcc". The longest substring is composed of letter 'd' and its length is 4.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [1..100,000];
all the words are non−empty and consist only of lowercase letters (a−z);
S denotes the sum of the lengths of words; S is an integer within the range [1..100,000].
