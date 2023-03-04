//ID: LRL52  Date: 2022.10.5
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = (1e5 + 55) * 2, inf = 0x3f3f3f3f; char Buf[1 << 21], *_A = Buf, *_B = Buf, cc;
inline char gc() { return _A == _B && (_B = (_A = Buf) + fread(Buf, 1, 1 << 21, stdin), _A == _B) ? EOF : *_A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
using LL = long long;
const LL INF = 0x3f3f3f3f3f3f3f3f;
int n, un, T;
int Val[N], vis[N];
LL dis[N];
struct Node {
    LL x, y;
    char dir;
}a[N], b[N];
struct NodeX {
    int i;
    inline bool operator<(const NodeX&t) const {
        return a[i].y < a[t.i].y;
    }
};
struct NodeY {
    int i;
    inline bool operator<(const NodeY&t) const {
        return a[i].x < a[t.i].x;
    }
};
set<NodeX> X[N];
set<NodeY> Y[N];
struct NodeD {
    int i; long long d;
    inline bool operator<(const NodeD&t) const {
        return d > t.d;
    }
};
priority_queue<NodeD> q;

signed main() {
#ifdef LRL52
	freopen("I-Robots.in", "r", stdin);
#endif
	rd(n), rd(T);
    rep(i, 1, n) {
        rd(a[i].x), rd(a[i].y);
        while(cc != 'U' && cc != 'D' && cc != 'L' && cc != 'R') cc = gc();
        a[i].dir = cc;
        Val[++un] = a[i].x, Val[++un] = a[i].y;
        b[i] = a[i];
    }
    sort(Val + 1, Val + un + 1);
    un = unique(Val + 1, Val + un + 1) - Val - 1;
    rep(i, 1, n) {
        int t = lower_bound(Val + 1, Val + un + 1, a[i].x) - Val;
        X[t].insert((NodeX){i});
        t = lower_bound(Val + 1, Val + un + 1, a[i].y) - Val;
        Y[t].insert((NodeY){i});
    }
    memset(dis, 0x3f, sizeof(dis));
    dis[1] = 0;
    q.push((NodeD){1, 0});
    while(!q.empty()) {
        auto [now, d] = q.top(); q.pop();
        int t1 = lower_bound(Val + 1, Val + un + 1, a[now].x) - Val;
        int t2 = lower_bound(Val + 1, Val + un + 1, a[now].y) - Val;
        if(!vis[now]) {
            vis[now] = 1; 
            auto it1 = X[t1].find((NodeX){now});
            X[t1].erase(it1);
            auto it2 = Y[t2].find((NodeY){now});
            Y[t2].erase(it2);
        }
        if(a[now].dir == 'U') {
            auto it = X[t1].upper_bound((NodeX){now});
            if(it != X[t1].end() && d + (a[it->i].y - a[now].y) < dis[it->i]) {
                dis[it->i] = d + (a[it->i].y - a[now].y);
                q.push((NodeD){it->i, dis[it->i]});
                a[now].x = a[it->i].x, a[now].y = a[it->i].y;
                q.push((NodeD){now, dis[it->i]});
            }
        }
        if(a[now].dir == 'D') {
            auto it = X[t1].lower_bound((NodeX){now});
            if(it != X[t1].begin()) {
                --it;
                if(d + (a[now].y - a[it->i].y) < dis[it->i]) {
                    dis[it->i] = d + (a[now].y - a[it->i].y);
                    q.push((NodeD){it->i, dis[it->i]});
                    a[now].x = a[it->i].x, a[now].y = a[it->i].y;
                    q.push((NodeD){now, dis[it->i]});
                }
            }
        }
        if(a[now].dir == 'R') {
            auto it = Y[t2].upper_bound((NodeY){now});
            if(it != Y[t2].end() && d + (a[it->i].x - a[now].x) < dis[it->i]) {
                dis[it->i] = d + (a[it->i].x - a[now].x);
                q.push((NodeD){it->i, dis[it->i]});
                a[now].x = a[it->i].x, a[now].y = a[it->i].y;
                q.push((NodeD){now, dis[it->i]});
            }
        }
        if(a[now].dir == 'L') {
            auto it = Y[t2].lower_bound((NodeY){now});
            if(it != Y[t2].begin()) {
                --it;
                if(d + (a[now].x - a[it->i].x) < dis[it->i]) {
                    dis[it->i] = d + (a[now].x - a[it->i].x);
                    q.push((NodeD){it->i, dis[it->i]});
                    a[now].x = a[it->i].x, a[now].y = a[it->i].y;
                    q.push((NodeD){now, dis[it->i]});
                }
            }
        }
    }
    rep(i, 1, n) {
        LL delta = 0;
        if(dis[i] != INF) delta = T - dis[i];
        if(b[i].dir == 'U') b[i].y += delta;
        if(b[i].dir == 'D') b[i].y -= delta;
        if(b[i].dir == 'L') b[i].x -= delta;
        if(b[i].dir == 'R') b[i].x += delta;
        printf("%lld %lld\n", b[i].x, b[i].y);
    }
	return 0;
}