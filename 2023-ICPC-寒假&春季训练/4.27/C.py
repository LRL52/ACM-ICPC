import os, sys
import math, collections, itertools, functools, heapq, bisect, string


def read(fun=int, sep=" "):
    return list(map(fun, sys.stdin.readline().split(sep)))


def Main(testCase):
    n = read()[0]
    a = read()
    f = collections.Counter()
    for i in a:
        x = i
        j = 2
        while j * j <= x:
            if x % j:
                j += 1
                continue
            while x and x % j == 0:
                x //= j
                f[j] += 1
        if x > 1:
            f[x] += 1
    g, h, z = 0, 0, 0
    for i, j in f.items():
        # print(i, j)
        g += j // 2
        if j == 1:
            h += 1
        z += j % 2

    if h == 2 and g == 0:
        print(0)
    else:
        print(g + z // 3)


for testCase in range(int(input())):
    Main(testCase)
