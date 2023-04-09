You have to be at your work as soon as possible. The road on your route to work may consist of two types of surface: asphalt or sand. To simplify the description, it will be denoted by a string R consisting only of the letters: "A" for an asphalt segment and "S" for a sand segment. All segments represent the same distance. For example, R = "SAAS" describes a road comprising of sand, asphalt, asphalt and sand segments.

When you go on foot, you need 20 minutes to pass through an asphalt segment and 30 minutes through a sand segment. You also have an electric scooter, which needs 5 minutes to pass through an asphalt segment and 40 minutes through a sand segment.

You start your journey on the scooter, but at any point you can get off the scooter and go on foot for the rest of the journey. What is the shortest time in which you can get to work?

Write a function:

int solution(string &R);

that, given a string R of length N, representing the road to work, returns the minimum time that you need to get to work.

Examples:

1. Given R = "ASAASS", your function should return 115. You ride on the scooter over the first four segments ("ASAA") in 5 + 40 + 5 + 5 = 55 and then you go on foot through "SS" in 30 + 30 = 60. Altogether, your journey will take 55 + 60 = 115.

2. Given R = "SSA", the function should return 80. You do not ride on the scooter at all, and you go on foot in 30 + 30 + 20 = 80.

3. Given R = "SSSSAAA", the function should return 175. You ride on the scooter all the time in 40 + 40 + 40 + 40 + 5 + 5 + 5 = 175.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [1..100,000];
string R is made only of the characters 'S' and/or 'A'.
