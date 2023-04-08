You analyze the performance of a computer network. The network comprises nodes connected by peer-to-peer links. There are N links and N + 1 nodes. All pairs of nodes are (directly or indirectly) connected by links, and links don't form cycles. In other words, the network has a tree topology.

Your analysis shows that communication between two nodes performs much better if the number of links on the (shortest) route between the nodes is odd. Of course, the communication is fastest when the two nodes are connected by a direct link. But, amazingly, if the nodes communicate via 3, 5, 7, etc. links, communication is much faster than if the number of links to pass is even.

Now you wonder how this influences the overall network performance. There are N * (N + 1) / 2 different pairs of nodes. You need to compute how many of them are pairs of nodes connected via an odd number of links.

Nodes are numbered from 0 to N. Links are described by two arrays of integers, A and B, each containing N integers. For each 0 ≤ I < N, there is a link between nodes A[I] and B[I].

Write a function:

int solution(vector<int> &A, vector<int> &B);

that, given two arrays, A and B, consisting of N integers and describing the links, computes the number of pairs of nodes X and Y, such that 0 ≤ X < Y ≤ N, and X and Y are connected via an odd number of links.

For example, given N = 6 and the following arrays:

  A[0] = 0    B[0] = 3
  A[1] = 3    B[1] = 1
  A[2] = 4    B[2] = 3
  A[3] = 2    B[3] = 3
  A[4] = 6    B[4] = 3
  A[5] = 3    B[5] = 5


the function should return 6, since:

there are six pairs of nodes connected by direct links, and
all other pairs of nodes are connected via two links.
Given N = 5 and the following arrays:

  A[0] = 0    B[0] = 1
  A[1] = 4    B[1] = 3
  A[2] = 2    B[2] = 1
  A[3] = 2    B[3] = 3
  A[4] = 4    B[4] = 5


the function should return 9, since:

there are five pairs of nodes connected by direct links,
there are three pairs of nodes connected via three links, and
there is one pair of nodes connected via five links.
Given N = 7 and the following arrays:

  A[0] = 0    B[0] = 3
  A[1] = 4    B[1] = 5
  A[2] = 4    B[2] = 1
  A[3] = 2    B[3] = 3
  A[4] = 7    B[4] = 4
  A[5] = 6    B[5] = 3
  A[6] = 3    B[6] = 4


the function should return 16, since:

there are seven pairs of nodes connected by direct links, and
there are nine pairs of nodes connected via three links.
Write an efficient algorithm for the following assumptions:

N is an integer within the range [0..90,000];
each element of arrays A and B is an integer within the range [0..N];
the network has a tree topology;
any pair of nodes is connected via no more than 1000 links.
