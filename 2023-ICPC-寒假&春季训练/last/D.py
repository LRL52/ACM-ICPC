import os, sys
import math, collections, itertools, functools, heapq, bisect


def read(fun = int, sep = ' '):
    return list(map(fun, sys.stdin.readline().split(sep)))


def Main(testCase):
    n,m=read()
    l=read()
    r=read()
    t=0
    js=0
    ans=0
    
    for i in range(n):
        if l[i]==r[i]:
            t+=1
        ans+=2
        if js+r[i]-l[i]+1>=m:
            w=l[i]+m-1-js
            ans+=w
            # print(ans,t,w,r[i])
            if t<=r[i]-w:
                ans-=t
            else:
                f=[r[i]-w]
                t-=r[i]-w
                for j in range(i+1,n):
                    if(l[j]==r[j]):
                        l[j]=l[j-1]
                        r[j]=r[j-1]
                        continue
                    if(t>=r[j]-l[j]+1):
                        f.append(r[j]-l[j]+1-(l[j]-r[j-1]-1)-2)
                        t-=r[j]-l[j]+1
                    else:
                        f.append(t-(l[j]-r[j-1]-1)-2)
                        break
                # print(f)
                f=itertools.accumulate(f)
                ans-=max(f)
           
            js=m
            break
        else:
            js+=r[i]-l[i]+1    
    if(js<m):
        print(-1)
    else:
        print(ans)

for testCase in range(int(input())):
    Main(testCase)