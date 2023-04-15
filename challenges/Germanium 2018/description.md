You are playing a game with N cards. On both sides of each card there is a positive integer. The cards are laid on the table. The score of the game is the smallest positive integer that does not occur on the face-up cards. You may flip some cards over. Having flipped them, you then read the numbers facing up and recalculate the score. What is the maximum score you can achieve?

Write a function:

int solution(vector<int> &A, vector<int> &B);

that, given two arrays of integers A and B, both of length N, describing the numbers written on both sides of the cards, facing up and down respectively, returns the maximum possible score.

For example, given A = [1, 2, 4, 3] and B = [1, 3, 2, 3], your function should return 5, as without flipping any card the smallest positive integer excluded from this sequence is 5.

Given A = [4, 2, 1, 6, 5] and B = [3, 2, 1, 7, 7], your function should return 4, as we could flip the first card so that the numbers facing up are [3, 2, 1, 6, 5] and it is impossible to have both numbers 3 and 4 facing up.

Given A = [2, 3] and B = [2, 3] your function should return 1, as no matter how the cards are flipped, the numbers facing up are [2, 3].

Write an efficient algorithm for the following assumptions:

N is an integer within the range [1..100,000];
each element of arrays A and B is an integer within the range [1..100,000,000];
input arrays are of equal size.
