//#include <cstdio>
//#include <cstdlib>
//#include <cstring>
//#include <algorithm>
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 305, M = 1055; char ss[1 << 21], * A = ss, * B = ss, cc;
inline char gc() { return A == B && (B = (A = ss) + fread(ss, 1, 1 << 21, stdin), A == B) ? EOF : *A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
int n, m, ct, Ans = 0x3f3f3f3f;
int head[N], fa[N], dep[N], top[N], ufa[N], X[M], Y[M], use[M], f[N], order[M];
struct edge {
	int v, nxt;
}e[N << 1];

inline void adde(int from, int to) {
	e[++ct].v = to;
	e[ct].nxt = head[from];
	head[from] = ct;
}

int dfs(int x, int depth) {
	dep[x] = depth; int size = 1, maxs = 0, tson = 0; top[x] = x;
	ee(i, x) {
		int v = e[i].v;
		if (v == fa[x]) continue;
		fa[v] = x;
		int dx = dfs(v, depth + 1);
		size += dx;
		if (dx > maxs) {
			maxs = dx;
			tson = v;
		}
	}
	if (tson) top[tson] = x;
	return size;
}

int find(int x) { return top[x] == x ? x : top[x] = find(top[x]); }

int LCA(int x, int y) {
	while (find(x) != find(y)) {
		if (dep[top[x]] < dep[top[y]]) swap(x, y);
		x = fa[top[x]];
	}
	return dep[x] < dep[y] ? x : y;
}

int find2(int x) {
	return ufa[x] == x ? x : ufa[x] = find2(ufa[x]);
}

void dfs2(int x) {
	ee(i, x) {
		int v = e[i].v;
		if (v == fa[x]) continue;
		dfs2(v);
		f[x] += f[v];
	}
}

int Solve() {
	memset(fa, 0, sizeof fa);
	memset(head, 0, sizeof head);
	memset(use, 0, sizeof use);
	ct = 0;
	rep(i, 1, n) ufa[i] = i;
	for(int k = 1, i; k <= m; ++k) {
		i = order[k];
		int f1 = find2(X[i]), f2 = find2(Y[i]);
		if (f1 != f2) {
			use[i] = 1;
			ufa[f1] = f2;
			adde(X[i], Y[i]);
			adde(Y[i], X[i]);
			//printf("%d %d\n", X[i], Y[i]);
		}
	}
	dfs(1, 0);
	memset(f, 0, sizeof f);
	rep(i, 1, m) {
		if (use[i]) continue;
		int x = X[i], y = Y[i];
		int lca = LCA(x, y);
		++f[x], ++f[y], f[lca] -= 2;
	}
	dfs2(1);
	int ans = 0x3f3f3f3f;
	rep(i, 2, n) ans = min(ans, f[i]);
	return ans + 1;
}

int main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	clock_t t = clock();
	rd(n), rd(m);
	rep(i, 1, m) rd(X[i]), rd(Y[i]);
	rep(i, 1, m) order[i] = i;
	for (int times = 1;; ++times) {
		Ans = min(Ans, Solve());
		//if (clock() - t >= 950000) break;
		if ((double)(clock() - t) / CLOCKS_PER_SEC > 0.95) break;
		random_shuffle(order + 1, order + m + 1);
	}
	printf("%d\n", Ans);
	return 0;
}