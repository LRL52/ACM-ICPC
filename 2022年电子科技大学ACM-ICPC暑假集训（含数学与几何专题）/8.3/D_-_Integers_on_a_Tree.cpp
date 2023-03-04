//ID: LRL52  Date: 2022.8.2
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 1e3 + 55, M = 2055, inf = 0x3f3f3f3f; char Buf[1 << 21], *_A = Buf, *_B = Buf, cc;
inline char gc() { return _A == _B && (_B = (_A = Buf) + fread(Buf, 1, 1 << 21, stdin), _A == _B) ? EOF : *_A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
struct Edge{
    int v, nxt;
}e[M << 1];
int head[N];

inline void adde(int from, int to){
    static int et = 0;
    e[++et] = (Edge){to, head[from]};
    head[from] = et;
}

void dfs(int x, int far){
    if(!colored[x]) L[x] = -inf, R[x] = inf;
    else L[x] = R[x] = a[x];
    ee(i, x){
        int v = e[i].v;
        if(v == far) continue;
        dfs(v, x);
        L[x] = max(L[x], L[v] - 1);
        R[x] = min(R[x], R[v] + 1);
    }
}

void dfs2(int x, int far){
    if(
    ee(i, x){
        int v = e[i].v;
        if(v == far) continue;
        L[v] = max(L[v], L[x] - 1);
        R[v] = min(R[v], R[x] + 1);
        dfs2(v, x);
    }
}

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	rd(n), rd(K); int x, y;
    rep(i, 1, n - 1){
        rd(x), rd(y);
        adde(x, y), adde(y, x);
    }
    rep(i, 1, K){
        rd(x), rd(y);
        colored[x] = 1;
        a[x] = y;
    }
    dfs(1, -1);
    dfs2(1, -1);
        
	return 0;
}