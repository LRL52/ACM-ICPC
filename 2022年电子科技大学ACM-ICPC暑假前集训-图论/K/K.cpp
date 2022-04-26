//ID: LRL52  Date: 2022.4.9
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
#include<bits/stdc++.h>
using namespace std;
const int N = 500055; char ss[1 << 21], * A = ss, * B = ss, cc;
inline char gc() { return A == B && (B = (A = ss) + fread(ss, 1, 1 << 21, stdin), A == B) ? EOF : *A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0; cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = (x << 3) + (x << 1) + (cc ^ 48); cc = gc(); } x *= f;
}
int n, m, root, ct, head[N];
int dep[N], fa[N], top[N];
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

int main() {
	freopen("K.in", "r", stdin);
	rd(n), rd(m); int x, y;
	rep(i, 1, n - 1) {
		rd(x), rd(y);
		adde(x, y), adde(y, x);
	}
	dfs(1, 0);
	rep(i, 1, m) {
		rd(x), rd(y);
		printf("%d\n", dep[x] + dep[y] - 2 * dep[LCA(x, y)]);
	}
	return 0;
}