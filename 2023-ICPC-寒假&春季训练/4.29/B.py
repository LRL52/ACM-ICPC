import os, sys
import math, collections, itertools, functools, heapq, bisect, string


def read(fun=int, sep=" "):
    return list(map(fun, sys.stdin.readline().split(sep)))


def Main(testCase):
    n = read()[0]
    if n == 1:
        print(1)
        return
    if n % 2 == 1:
        print(-1)
        return
    a = [i for i in range(1, n + 1)[::-1]]
    for i in range(0, n, 2):
        a[i], a[i + 1] = a[i + 1], a[i]
    print(*a)


for testCase in range(int(input())):
    Main(testCase)
