//ID: LRL52  Date: 2022.7.27
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
int n, Qs, dep[N], top[N], fa[N];
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
	dep[x] = depth; int size = 1, maxs = 0, tson = 0; top[x] = x;
	ee(i, x){
		int v = e[i].v;
		if(v == fa[x]) continue;
		fa[v] = x;
		int dx = dfs(v, depth + 1);
		size += dx;
		if(dx > maxs){
			maxs = dx;
			tson = v;
		}
	}
	if(tson) top[tson] = x;
	return size;
}

int find(int x){return top[x] == x ? x : top[x] = find(top[x]);}

int LCA(int x, int y){
	while(find(x) != find(y)){
		if(dep[top[x]] < dep[top[y]]) swap(x, y);
		x = fa[top[x]];
	}
	return dep[x] < dep[y] ? x : y;
}

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	rd(n), rd(Qs); int x, y;
    rep(i, 1, n - 1){
        rd(x), rd(y);
        adde(x, y), adde(y, x);
    }
    dfs(1, 0);
    rep(i, 1, Qs){
        rd(x), rd(y);
        int dis = dep[x] + dep[y] - 2 * dep[LCA(x, y)] + 1;
        //printf("LCA = %d dis = %d\n", LCA(x, y), dis);
        long long ans = n;
        ans += 1LL * dis * (dis - 1) / 2;
        printf("%lld\n", ans);
    }
    //rep(i, 1, n) printf("%d ", dep[i]);
	return 0;
}