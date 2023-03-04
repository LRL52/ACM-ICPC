//ID: LRL52  Date: 2022.9.3
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

void dfs2(int x){
    v1[x] = v2[x] = x;
    ee(i, x){
        int v = e[i].v;
        if(v == fa[x][0]) continue;
        dfs2(v);
        if(f[v] + 1 > f[x]) {
            g[x] = f[x], v2[x] = v1[x];
            f[x] = f[v] + 1;
            v1[x] = v1[v];
        } else
        if(f[v] + 1 > g[x]) {
            g[x] = f[v] + 1,
            v2[x] = v1[v];
        }
    }
}

void dfs3(int x){
    ee(i, x){
        int v = e[i].v;
        if(v == fa[x][0]) continue;
        int d = 0, u = 0, flag = 0;
        if(f[x] != f[v] + 1){
            d = f[x] + 1, u = v1[x];
            flag = 1;
        } else {
            d = g[x] + 1, u = v2[x];
        }
        if(d > f[v]){
            g[v] = f[v], v2[v] = v1[v];
            f[v] = d, v1[v] = u;
        } else
        if(d > g[v]){
            g[v] = d, v2[v] = u;
        }
        if(flag)
            if(g[x] + 1 > g[v])
                g[v] = g[x] + 1, v2[v] = v2[x];
        dfs3(v);
    }
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
    dfs2(1);
    //F[1] = f[1], G[1] = g[1];
    dfs3(1);
    //rep(i, 1, n) printf("%d %d %d\n", i, v1[i], f[i]);
    int qs; rd(qs); int k;
    rep(i, 1, qs){
        rd(x), rd(k);
        y = v1[x];
        int lca = LCA(x, y);
        int d1 = dep[x] - dep[lca];
        if(d1 >= k){
            Jump(x, k);
            continue;
        }
        k -= d1;
        int d2 = dep[y] - dep[lca];
        if(k <= d2) Jump(y, d2 - k);
        else puts("-1");
    }
	return 0;
}