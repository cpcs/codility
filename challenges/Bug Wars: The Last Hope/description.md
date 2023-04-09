There are N cities arranged in a row (numbered from 0 to N−1). The K-th city is located at position X[K] and contains A[K] liters of fuel. Getting from city J to city K requires |X[J] − X[K]| liters of fuel.

Tom is planning a trip. He wants to visit as many cities as possible. Unfortunately, he is limited by the available fuel. To be precise, at the departure time from city J, leaving for city K, the tank should contain at least |X[J] − X[K]| liters of fuel. When Tom visits a city, he refuels his car with all the available fuel at this city. He can refuel at each city just once at most. The fuel tank has an infinite capacity.

Tom can arbitrarily choose the city from which to start his trip. Tom begins with an empty tank and immediately refuels his car at the starting city. He wants to know how many cities he can visit.

Write a function:

int solution(vector<int> &A, vector<int> &X);

that, given two arrays A, X consisting of N integers each, returns the maximum number of different cities that Tom can visit.

Examples:

1. Given A = [4, 1, 4, 3, 3], X = [8, 10, 11, 13, 100], the function should return 4. One of the possible trips is: 1 → 2 → 0 → 3.

Tom starts his trip in city number 1 and refuels 1 liter of fuel.
Then he drives to city number 2 (it costs |10 − 11| = 1 liter of fuel) and refuels 4 liters of fuel.
Next he drives to city number 0 (it costs |11 − 8| = 3 liters of fuel) and refuels 4 liters of fuel.
Finally he drives to city number 3 (it costs |8 − 13| = 5 liters of fuel) and refuels 3 liters of fuel.
Tom has insufficient fuel to reach city number 4.
The picture describes the first example test.

2. Given A = [0, 10, 0], X = [1, 2, 3], the function should return 3. Tom can start his trip in city number 1. Then he can visit city number 0 followed by city number 2 (or vice versa). It costs 3 liters of fuel in total.

3. Given A = [0, 1, 0, 1, 1, 1, 0], X = [1, 2, 3, 4, 5, 6, 7], the function should return 4. Tom can start his trip in city number 3. Then he visits cities 4, 5 and 6, respectively.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [1..700];
each element of array A is an integer within the range [0..1,000,000];
each element of array X is an integer within the range [1..1,000,000];
X[K] < X[K + 1] for each K within the range [0..N−2].
Copyright 2009–2023 by Codility Limited. All Rights Reserved. Unauthorized copying, publication or disclosure prohibited.
