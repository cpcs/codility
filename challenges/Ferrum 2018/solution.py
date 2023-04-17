# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")

def solution(A):
    have = {0:0}
    r, s = 0, 0
    for i in range(1, len(A) + 1):
        s += A[i - 1]
        if s in have:
            r = max(r, i - have[s])
        else:
            have[s] = i
    return len(A) if s > 0 else r
