# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")

def solution(A):
    # Implement your solution here
    # 5 ^ 12 = 244140625
    dp = [[-1] * 37 for i in range(4)]
    dp[0][0] = 0
    for x in A:
        num2, num5 = 0, 0
        while (x & 1) == 0:
            x >>= 1
            num2 += 1
        while x % 5 == 0:
            x /= 5
            num5 += 1
        for i in range(3, 0, -1):
            for j in range(i * 12, num5 - 1, -1):
                if dp[i - 1][j - num5] >= 0:
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - num5] + num2)
    r = 0
    for i in range(len(dp[3])):
        r = max(r, min(dp[3][i], i))
    return r
