//ID: LRL52  Date: 2022.9.3 ~ 9.4
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 2e5 + 55, M = 2055, inf = 0x3f3f3f3f; char Buf[1 << 21], *_A = Buf, *_B = Buf, cc;
inline char gc() { return _A == _B && (_B = (_A = Buf) + fread(Buf, 1, 1 << 21, stdin), _A == _B) ? EOF : *_A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
int n, fa[N][35], dep[N], Top[N], son[N], v1[N], v2[N], f[N], g[N], lg[N];
int maxd, u_;
struct Edge{
    int v, nxt;
}e[N << 1];
int head[N];

inline void adde(int from, int to){
    static int et = 0;
    e[++et] = (Edge){to, head[from]};
    head[from] = et;
}

int dfs(int x, int depth){
	dep[x] = depth, Top[x] = x; int tson = 0, maxs = 0, size = 1;
    for(int i = 1; i <= lg[depth]; ++i)
        fa[x][i] = fa[fa[x][i - 1]][i - 1];
	ee(i, x){
		int v = e[i].v;
		if(v == fa[x][0]) continue;
		fa[v][0] = x;
		int dx = dfs(v, depth + 1);
		size += dx;
		if(dx > maxs){
			maxs = dx;
			tson = v;
		}
	}
	if(tson) Top[tson] = x, son[x] = tson;
	return size;
}

int findtop(int x){return Top[x] == x ? x : Top[x] = findtop(Top[x]);}

int LCA(int x, int y){
	while(findtop(x) != findtop(y)){
		if(dep[Top[x]] < dep[Top[y]]) swap(x, y);
		x = fa[Top[x]][0];
	}
	return dep[x] < dep[y] ? x : y;
}

void Jump(int x, int K){
    int now = x;
    for(int i = lg[dep[x]]; i >= 0; --i){
        if(K >> i & 1){
            now = fa[now][i];
        }
    }
    printf("%d\n", now);
}

void dfs2(int x, int far, int d){
    if(d > maxd){
        maxd = d;
        u_ = x;
    }
    ee(i, x){
        int v = e[i].v;
        if(v == far) continue;
        dfs2(v, x, d + 1);
    }
}

int Solve(int x, int k, int y){
    int lca = LCA(x, y);
    int d1 = dep[x] - dep[lca];
    if(d1 >= k){
        Jump(x, k);
        return 1;
    }
    k -= d1;
    int d2 = dep[y] - dep[lca];
    if(k <= d2) {
        Jump(y, d2 - k);
        return 1;
    }
    return 0;
}

signed main() {
#ifdef LRL52
	freopen("F.in", "r", stdin);
#endif
	rd(n); int x, y; lg[1] = -1;
    rep(i, 1, n) lg[i] = lg[i >> 1] + 1;
    rep(i, 1, n - 1){
        rd(x), rd(y);
        adde(x, y), adde(y, x);
    }
    dfs(1, 0);
    maxd = 0, u_ = 1;
    dfs2(1, -1, 0);
    int u = u_; maxd = 0;
    dfs2(u, -1, 0);
    int v = u_;
    int qs; rd(qs); int k;
    rep(i, 1, qs){
        rd(x), rd(k);
        if(Solve(x, k, u)) continue;
        if(Solve(x, k, v)) continue;
        puts("-1");
    }
	return 0;
}