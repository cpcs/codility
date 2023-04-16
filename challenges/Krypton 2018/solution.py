# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")

def solution(A):
    # Implement your solution here
    n = len(A)
    # minimum number of 2 and 5.
    dp = [[float('inf')] * 2 for i in range(n)]
    z = False;
    for i in range(n):
        for j in range(n):
            v = [0] * 2
            if A[i][j] == 0:
                v[0] = v[1] = 1
                z = True
            else:
                while (A[i][j] & 1) == 0:
                    A[i][j] >>= 1
                    v[0] += 1
                while A[i][j] % 5 == 0:
                    A[i][j] /= 5
                    v[1] += 1
            if i == 0 and j == 0:
                dp[j] = v
                continue
            if j > 0:
                dp[j][0] = min(dp[j][0], dp[j - 1][0])
                dp[j][1] = min(dp[j][1], dp[j - 1][1])
            dp[j] = [dp[j][0] + v[0], dp[j][1] + v[1]]
    r = min(dp[n - 1][0], dp[n - 1][1])
    return min(r, 1) if z else r
