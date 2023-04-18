def solution(A):
    # Implement your solution here{
    p = [[0, 0]]
    r, s = 0, 0
    for i in range(1, len(A) + 1):
        s += A[i - 1]
        if p[-1][1] > s:
            p.append([i, s])
        left, right = 0, len(p) - 1
        while left <= right:
            mid = (left + right) >> 1
            if p[mid][1] <= s:
                right = mid - 1
            else:
                left = mid + 1
        r = max(r, i - p[right + 1][0])
    return r
