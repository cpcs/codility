A few palindromic sentences exist in many languages. They look the same, regardless of whether they are read normally (from left to right) or backwards (from right to left). Here are some English examples:

was it a rat i saw
mr owl ate my metal worm
live on time emit no evil
Precisely speaking, a sentence is palindromic if, after removing all its spaces (and punctuation), it looks the same when read both left to right and right to left. For example, the second example sentence would become "mrowlatemymetalworm", which looks exactly the same when spelled backwards.

Tom just found a list of words in an old language, and he wonders if he can use them to create a palindromic sentence. Since he doesn't know the language, he will have to assume that any sequence of words from the list is a valid sentence. In order to create a palindromic sentence, he can use each word as many times as he wants. In particular, he may decide not to use some words at all.

Write a function:

string solution(string &S);

that, given a string S of length N containing a space-separated list of all the words in the language, returns any palindromic sentence built from the words in S. All of the words in the output sentence should be written in lower case and separated by single spaces. If no such sentence exists, the function should return the word "NO". The length of the sentence should not exceed 600,000 characters. You can assume that if a palindromic sentence can be constructed using the input words, then a palindromic sentence of length not greater than 600,000 characters can be constructed as well.

Examples:

1. Given S="by metal owl egg mr crow worm my ate", your function may return "mr owl ate my metal worm", "mr owl worm", or any other palindromic sentence built using the words from the list, that does not exceed 600,000 characters.

2. Given S="live on time emit no evil", your function may for example return "live on time emit no evil", "no on on no no on", "evil time emit live", or any other palindromic sentence built using the words from the list, that does not exceed 600,000 characters.

3. Given S="abcc bc ac", your function should return "NO", since no palindromic sentence may be constructed using words from the list.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [1..500];
string S consists only of lowercase letters (a−z) and spaces.
