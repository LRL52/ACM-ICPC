//ID: LRL52  Date: 2022.9.3
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 2e5 + 55, inf = 0x3f3f3f3f; char Buf[1 << 21], *_A = Buf, *_B = Buf, cc;
inline char gc() { return _A == _B && (_B = (_A = Buf) + fread(Buf, 1, 1 << 21, stdin), _A == _B) ? EOF : *_A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
#define int long long
int n, m, sum[N], a[N], vis[N];
struct Edge{
    int v, nxt;
}e[N << 1];
struct Node{
    int v, sum;
    inline bool operator<(const Node&t)const{
        return sum > t.sum;
    } 
};
priority_queue<Node> q;
int head[N];

inline void adde(int from, int to){
    static int et = 0;
    e[++et] = (Edge){to, head[from]};
    head[from] = et;
}

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	rd(n), rd(m); int x, y;
    rep(i, 1, n) rd(a[i]);
    rep(i, 1, m){
        rd(x), rd(y);
        adde(x, y), adde(y, x);
    }
    rep(i, 1, n){
        ee(j, i){
            int v = e[j].v;
            sum[i] += a[v];
        }
    }
    rep(i, 1, n) q.push({i, sum[i]});
    int ans = 0;
    while(!q.empty()){
        Node qu = q.top(); q.pop();
        int now = qu.v;
        if(vis[now]) continue;
        vis[now] = 1;
        ans = max(ans, sum[now]);
        ee(i, now){
            int v = e[i].v;
            if(vis[v]) continue;
            sum[v] -= a[now];
            q.push({v, sum[v]});
        }
    }
    printf("%lld\n", ans);
	return 0;
}