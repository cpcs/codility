In the binary number "100100010000" there are at least two 0s between any two consecutive 1s.
In the binary number "100010000100010" there are at least three 0s between any two consecutive 1s.  
A positive integer N is called K-sparse if there are at least K 0s between any two consecutive 1s in its binary representation.  

For example, the binary number "100100010000" is 2-sparse. Similarly, "100010000100010" is 3-sparse. It is also 2-sparse, because 2 < 3. It is also 1-sparse and 0-sparse.  

We assume that any power of 2 (i.e. "1", "10", "100", "1000", ...) is K-sparse for any K.

Write a function:

int solution(string &S, string &T, int K);  

that, given:

string S containing a binary representation of some positive integer A,   
string T containing a binary representation of some positive integer B,   
a positive integer K.  
returns the number of K-sparse integers within the range [A..B] (both ends included). If the result exceeds 1,000,000,006,   
the function should return the remainder from the division of the result by 1,000,000,007.

For example, given S = "101" (A = 5), T = "1111" (B=15) and K=2, the function should return 2, because there are just two 2-sparse integers in the range [5..15], namely "1000" (i.e. 8) and "1001" (i.e. 9).  

Write an efficient algorithm for the following assumptions:

K is an integer within the range [1..30];  
the length of string S is within the range [1..300,000];  
the length of string T is within the range [1..300,000];  
string S is made only of the characters '0' and/or '1';  
string T is made only of the characters '0' and/or '1';  
S and T have no leading zeros;  
A ≤ B.  
