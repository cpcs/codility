There are N points (numbered from 0 to N−1) on a plane. Each point is colored either red ('R') or green ('G'). The K-th point is located at coordinates (X[K], Y[K]) and its color is colors[K]. No point lies on coordinates (0, 0).

We want to draw a circle centered on coordinates (0, 0), such that the number of red points and green points inside the circle is equal. What is the maximum number of points that can lie inside such a circle? Note that it is always possible to draw a circle with no points inside.

Write a function:

int solution(vector<int> &X, vector<int> &Y, string &colors);

that, given two arrays of integers X, Y and a string colors, returns an integer specifying the maximum number of points inside a circle containing an equal number of red points and green points.

Examples:

1. Given X = [4, 0, 2, −2], Y = [4, 1, 2, −3] and colors = "RGRR", your function should return 2. The circle contains points (0, 1) and (2, 2), but not points (−2, −3) and (4, 4).

<img src="e1.png" align="center" /> 

2. Given X = [1, 1, −1, −1], Y = [1, −1, 1, −1] and colors = "RGRG", your function should return 4. All points lie inside the circle.

<img src="e2.png" align="center" /> 

3. Given X = [1, 0, 0], Y = [0, 1, −1] and colors = "GGR", your function should return 0. Any circle that contains more than zero points has an unequal number of green and red points.

<img src="e3.png" align="center" /> 

4. Given X = [5, −5, 5], Y = [1, −1, −3] and colors = "GRG", your function should return 2.

<img src="e4.png" align="center" /> 

5. Given X = [3000, −3000, 4100, −4100, −3000], Y = [5000, −5000, 4100, −4100, 5000] and colors = "RRGRG", your function should return 2.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [1..100,000];
each element of arrays X and Y is an integer within the range [−20,000..20,000];
string colors is made only of the characters 'R' and/or 'G';
no point lies on the coordinates (0, 0).
