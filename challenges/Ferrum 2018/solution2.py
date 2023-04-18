def solution(A):
    n = len(A)
    # 前缀和数组
    p = [0] * (n + 1)
    # 以这一项结尾的子数组的最大和
    best = [0] * n
    length, m = 0, 0
    for i in range(1, n + 1):
        p[i] = p[i - 1] + A[i - 1]
        best[i - 1] = p[i] - p[m]
        while length < i and best[i - length - 1] + p[i] - p[i - length] >= 0:
             length += 1
        if p[i] < p[m]:
            m = i
    return length
