import os, sys
import math, collections, itertools, functools, heapq, bisect, string

sys.setrecursionlimit(5000)


def read(fun=int, sep=" "):
    return list(map(fun, sys.stdin.readline().split(sep)))


def Main(testCase):
    n, m = read()
    g = [[] for _ in range(n + 1)]
    a = []
    for i in range(m):
        x, y = read()
        g[x].append(y)
        g[y].append(x)

    ok = False

    for i in range(1, n + 1):
        if len(g[i]) < 4:
            continue
        sss = set()
        vis = [False] * (n + 1)

        for v in g[i]:
            sss.add(v)
        ans = []

        def dfs(u, pre):
            nonlocal ok
            nonlocal sss
            nonlocal ans
            if u in sss:
                sss.remove(u)
                if len(sss) < 2:
                    sss.add(u)
                    return
            vis[u] = True
            for v in g[u]:
                if v == pre or (vis[v] and v != i):
                    continue
                ans.append((u, v))
                if v == i:
                    ok = True
                    js = 2
                    for j in sss:
                        ans.append((i, j))
                        js -= 1
                        if js == 0:
                            break
                    print("YES")
                    print(len(ans))
                    for x, y in ans:
                        print(x, y)
                    return
                dfs(v, u)
                if ok:
                    return
                ans.pop()·

        dfs(i, 0)
        if ok:
            return
    print("NO")


for testCase in range(int(input())):
    Main(testCase)