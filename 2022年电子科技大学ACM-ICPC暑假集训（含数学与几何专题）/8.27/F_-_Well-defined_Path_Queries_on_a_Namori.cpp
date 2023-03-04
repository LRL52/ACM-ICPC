//ID: LRL52  Date: 2022.8.27
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
int n, Color[N], cir[N], ts[N], cnt, DFN, dfn[N], fa[N];
struct Edge{
    int v, nxt;
}e[N << 1];
int head[N];

inline void adde(int from, int to){
    static int et = 0;
    e[++et] = (Edge){to, head[from]};
    head[from] = et;
}

void GetLoop(int x){
	dfn[x] = ++DFN;
	ee(i, x){
		int v = e[i].v;
		if(dfn[v]){
			if(dfn[v] < dfn[x]) continue;
			cir[v] = 1, ts[++cnt] = v;
			for(; v != x; v = fa[v]) cir[fa[v]] = 1, ts[++cnt] = fa[v];
		}
		else{
			fa[v] = x; GetLoop(v);
		}
	}
}

void dfs(int x, int far, int col){
    Color[x] = col;
    ee(i, x){
        int v = e[i].v;
        if(v == far || cir[v]) continue;
        dfs(v, x, col);
    }
}

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	rd(n); int x, y;
    rep(i, 1, n){
        rd(x), rd(y);
        adde(x, y), adde(y, x);
    }
    GetLoop(1);
    rep(i, 1, cnt){
        int x = ts[i];
        dfs(x, -1, i);
    }
    int qs; rd(qs);
    rep(i, 1, qs){
        rd(x), rd(y);
        if(Color[x] == Color[y]) puts("Yes");
        else puts("No");
    }
	return 0;   
}