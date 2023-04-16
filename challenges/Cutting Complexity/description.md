A long time ago, when the most basic model of an HP3000 computer used to cost $95,000 (over half a million in today's dollars), a very wise man called Gordon Moore made predictions about how computers would become cheaper and more powerful each year. According to Moore, the number of components per integrated circuit would double every two years. Thanks to the creative, determined engineers working in circuit printing technology, we do indeed have smaller, cheaper and more powerful computers today.

Circuit printing, as we call photolithography, is an extremely complex yet rewarding field, and ASML needs the best software engineers in the world to make this magic happen. We work closely with our clients to help them print their circuits in the most effective way. One of our clients requests us to write a method to optimize their circuit efficiency. The circuit is represented as a string consisting of the letters "M" and "L", where M represents Memory units and L represents Logic units. The efficiency of the circuit is measured as the length of the longest interval of letters "M". For example, given input string "LMMMLMMMMLLLM", the longest interval is 4.

Our customer wants to change the circuit in such a way that the longest M-interval will be equal to K. We can change any unit at any position in the circuit, i.e. either we can change any "M" to "L" or any "L" to "M". The objective of this challenge is to calculate the minimum number of changes we have to make in order to achieve the desired longest M-interval length K.

Write a function:

int solution(string &S, int K);

where the first argument, S, represents the circuit as a string of length N that consists of only characters "M" and/or "L" and the second argument, K, is the desired longest M-interval in the string. The return value shall be the minimum number of changes to achieve K as the longest M-interval in the input string.

For example, given S = "MLMMLLM" and K = 3, your function should return 1. We can change the letter at position 4 (counting from 0) to obtain "MLMMMLM", in which the longest interval of letters "M" is exactly three characters long.

For another example, given S = "MLMMMLMMMM" and K = 2, your function should return 2. We can, for example, modify the letters at positions 2 and 7 to get the string "MLLMMLMLMM", which satisfies the desired property.

Write an efficient algorithm for the following assumptions:

string S is made only of the characters 'M' and/or 'L';
N is an integer within the range [1..100,000];
K is an integer within the range [0..N].
