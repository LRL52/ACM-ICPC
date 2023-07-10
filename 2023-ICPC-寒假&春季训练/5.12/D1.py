import os, sys, io
import math, collections, itertools, functools, heapq, bisect, string, random


def read(fun=int, sep=" "):
    return list(map(fun, sys.stdin.readline().split(sep)))


def Main(testCase):
    n, _ = read()
    a = read()
    a.sort()
    K = read()
    ans = []
    for m in K:
        # h = []
        b = a[:]
        if m <= n:
            s, ng = 1, 0
        elif (m - n) % 2 == 0:
            s, ng = m - n + 1, (m - n) // 2
        else:
            s, ng = m - n + 2, (m - n + 1) // 2
        l = 0
        for i in range(s, m + 1)[::-1]:
            b[l] += i
            l += 1
        x = min(b)
        for i in range(n):
            ng -= b[i] - x
        if ng > 0:
            ans.append(x - ng // n - (1 if ng % n != 0 else 0))
        else:
            ans.append(x)
    print(*ans)


for testCase in range(1):
    Main(testCase)
