//ID: LRL52  Date: 2022.10.4
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 5e5 + 55, M = 1e6 + 55, inf = 0x3f3f3f3f; char Buf[1 << 21], *_A = Buf, *_B = Buf, cc;
inline char gc() { return _A == _B && (_B = (_A = Buf) + fread(Buf, 1, 1 << 21, stdin), _A == _B) ? EOF : *_A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
struct Edge{
    int v, nxt;
}e[M], e2[M];
int n, m, co, DFN, Top; 
int head[N], low[N], dfn[N], stk[N], Size[N], scc[N];
int head2[N], f[N], fa[N];

inline void adde(int from, int to){
    static int et = 0;
    e[++et] = (Edge){to, head[from]};
    head[from] = et;
}

inline void adde2(int from, int to){
    static int et2 = 0;
    e2[++et2] = (Edge){to, head2[from]};
    head2[from] = et2;
}

void tarjan(int x){
    low[x] = dfn[x] = ++DFN; stk[Top++] = x;
    ee(i, x) {
        int v = e[i].v;
        if(!dfn[v]) {
            tarjan(v);
            low[x] = min(low[x], low[v]);
        } else
        if(!scc[v]) 
            low[x] = min(low[x], dfn[v]);
    }
    if(low[x] == dfn[x]) {
        ++co;
        do {
            int v = stk[--Top];
            scc[v] = co;
            Size[co]++;
        } while(stk[Top] != x);
    }
}

int dfs(int x) {
    if(f[x] != -1) return f[x];
    f[x] = Size[x];
    for(int i = head2[x]; i; i = e2[i].nxt) {
        int v = e2[i].v;
        f[x] += dfs(v);
    }
    return f[x];
}

int find(int x){return fa[x] == x ? x : fa[x] = find(fa[x]);}

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	rd(n), rd(m); int x, y;
    rep(i, 1, m) {
        rd(x);
        rep(i, 2, n) {
            rd(y);
            adde(x, y);
            x = y;
        }
    }
    rep(i, 1, n) if(!dfn[i]) tarjan(i);
    //rep(i, 1, n) printf("scc[%d] = %d\n", i, scc[i]); 
    rep(i, 1, co) f[i] = -1, fa[i] = i;
     rep(i, 1, n) {
        ee(j, i) {
            int v = e[j].v;
            if(scc[i] != scc[v] && find(scc[i]) != find(scc[v]))
                adde2(scc[i], scc[v]);
                fa[find(scc[i])] = find(scc[v]);
                //printf("%d %d\n", scc[i], scc[v]);
        }
    }
    rep(i, 1, co) dfs(i);
    rep(i, 1, n) printf("%d ", f[scc[i]] - 1);
	return 0;
}