There are N obligatory books in a school program syllabus. The program also defines the order in which books should be read. Each book comes from a specific age, such as the enlightenment or the baroque period. The more books in a row the students read from any given age, the more they learn about it. Moreover, if they read a book from a different age, they will get distracted.

Teachers are allowed to replace K books from the program with alternatives. They want students to learn as much as possible from a single age (although they have not picked a particular specific age). The amount learned can be measured by the number of consecutive books from the same age read by the students. What is the maximum number of consecutive books from the same age after replacing at most K of them?

Note that the new books (after replacement) can be any books from the chosen age. They do not need to be listed in the syllabus, so the teacher can always find K books from the same age.

Write a function:

int solution(vector<int> &A, int K);

that, given an array of integers A of length N, representing the ages of consecutive books from the school program syllabus, and an integer K, returns the maximum number of consecutive books from the same age after replacing at most K of them.

Examples:

1. Given A = [1, 1, 3, 4, 3, 3, 4] and K = 2, the function should return 5. Teachers can replace books from age 4 with books from age 3.

2. Given A = [4, 5, 5, 4, 2, 2, 4] and K = 0, the function should return 2. Teachers are not allowed to replace any books.

3. Given A = [1, 3, 3, 2] and K = 2, the function should return 4. Teachers can replace all the books from other ages with books from age 3.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [1..100,000];
K is an integer within the range [0..N];
each element of array A is an integer within the range [1..100,000].
