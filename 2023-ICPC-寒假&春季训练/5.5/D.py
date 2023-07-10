import os, sys
import math, collections, itertools, functools, heapq, bisect, string


def read(fun=int, sep=" "):
    return list(map(fun, sys.stdin.readline().split(sep)))


def Main(testCase):
    n = read()[0]
    b = read()
    a = []
    c = []
    f = []
    for i in range(n):
        a.append(b[i] - i)
    for i in range(n):
        c.append(b[i] + i)
        if i:
            f.append(max(c[i], f[i - 1]))
        else:
            f.append(c[i])
    r = 1
    mc = c[0]
    ans = a[2] + b[r] + mc
    for i in range(3, n):
        # ans = max(ans, a[i] + b[r] + mc)
        if b[i - 1] + f[i - 2] > b[r] + mc:
            r = i - 1
            mc = f[i - 2]
        # print(ans, a[i], b[r], mc)
        ans = max(ans, a[i] + b[r] + mc)
    print(ans)


for testCase in range(int(input())):
    Main(testCase)
