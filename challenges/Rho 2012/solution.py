# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")


def dfs(may, w, length):
    if len(may) > length:
        return False
    if may[-1] == w:
        return True
    if len(may) == length:
        return False
    for i in range(len(may) - 1, -1, -1):
        for j in range(i, -1, -1):
            x = may[i] + may[j]
            if x > w:
                continue
            if x <= may[-1] or x << (length - len(may) - 1) < w:
                break
            may.append(x)
            if dfs(may, w, length):
                return True
            may.pop()
    return False

def solution(A):
    # Implement your solution here
    r = [1]
    length = 1
    while not dfs(r, A, length):
        length += 1
    return r
