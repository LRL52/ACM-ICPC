//ID: LRL52  Date: 2023.1.15
//Andrew算法求凸包，第一遍求出下凸壳，第二遍求出上凸壳
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
const int N = 10000 + 55, M = 2e3 + 55, inf = 0x3f3f3f3f;
int n;
struct Point {
    double x, y;
    friend Point operator+(const Point &t1, const Point &t2) {
        return { t1.x + t2.x, t1.y + t2.y };
    }
    friend Point operator-(const Point &t1, const Point &t2) {
        return { t1.x - t2.x, t1.y - t2.y };
    }
}q[N], stk[N];

double cross(const Point &a, const Point &b) {
    return a.x * b.y - b.x * a.y; 
}

double area(const Point &a, const Point &b, const Point &c) {
    return cross(b - a, c - a);
}

double dist(const Point &t1, const Point &t2) {
    auto t = t2 - t1;
    return sqrt(t.x * t.x + t.y * t.y);
}

//能处理直线情况，不过目前封装还不太好
//传入的stk数组需要提前排序，求得的凸包中首尾结点都有1号点
int Andrew(Point stk[]) {
    int top = 0;
    for(int i = 1; i <= n; ++i) {
        while(top >= 2 && area(stk[top - 1], stk[top], q[i]) <= 0) //凸包边界上同一线段的点仅放入两端点，如果有重复点的话直接改成<会出问题
            --top;
        stk[++top] = q[i];
    }
    int k = top;
    for(int i = n - 1; i >= 1; --i) {
        while(top > k && area(stk[top - 1], stk[top], q[i]) <= 0)
            --top;
        stk[++top] = q[i];
    }
    return top;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n;
    rep(i, 1, n) cin >> q[i].x >> q[i].y;
    auto cmp = [](const Point &t1, const Point &t2)->bool {
        if(t1.x != t2.x) return t1.x < t2.x;
        return t1.y < t2.y;
    };
    sort(q + 1, q + n + 1, cmp);
    int top = Andrew(stk);
    double ans = 0.0;
    for(int i = 1; i < top; ++i)
        ans += dist(stk[i], stk[i + 1]);
    printf("%.2lf\n", ans);
	return 0;
}

//直线数据 18.0
/*
10
5 0
0 0
2 0
6 0
9 0
8 0
1 0
7 0
4 0
3 0
*/

//有重复点数据 14.62
/*
5
5 2
6 4
6 6
6 6
7 9
*/