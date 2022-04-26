//ID: LRL52  Date: 2022.4.14
//Matrix-Tree 定理
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
const int N = 105, M = 1055; char ss[1 << 21], * A = ss, * B = ss, cc;
inline char gc() { return A == B && (B = (A = ss) + fread(ss, 1, 1 << 21, stdin), A == B) ? EOF : *A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
const int MOD = 10000;
int n, m, tot;
int fa[N], belong[N], a[N][N];
vector<int> W;
struct Edge {
	int u, v, w;
	inline bool operator<(const Edge& t)const {
		return w < t.w;
	}
}e[M], tree[M];

int find(int x) {
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}

void Kruskal() {
	rep(i, 1, n) fa[i] = i;
	rep(i, 1, m) {
		int u = e[i].u, v = e[i].v, w = e[i].w;
		int fu = find(u), fv = find(v);
		if (fu != fv) {
			fa[fu] = fv;
			if (W.size() == 0 || (w != W[W.size() - 1]))
				W.push_back(w);
			tree[++tot] = e[i];
		}
	}
	if (tot != n - 1) {
		puts("0");
		exit(0);
	}
}

void Union(int w) {
	rep(i, 1, n) fa[i] = i;
	rep(i, 1, tot) {
		if (tree[i].w == w) continue;
		int fu = find(tree[i].u), fv = find(tree[i].v);
		fa[fu] = fv;
	}
}

int AddEdge(int w) {
	memset(belong, 0, sizeof belong);
	int cntN = 0;
	rep(i, 1, n) {
		if (belong[find(i)] == 0)
			belong[find(i)] = ++cntN;
		belong[i] = belong[find(i)];
	}
	memset(a, 0, sizeof a);
	rep(i, 1, m) {
		if (e[i].w != w) continue;
		int u = belong[e[i].u], v = belong[e[i].v];
		++a[u][u], ++a[v][v], --a[u][v], --a[v][u]; //Matrix-Tree 定理
	}
	return cntN;
}

int Det(int n) {
	int f = 1; //正负标记，交换行列式两行，f *= -1;
	rep(i, 1, n) {
		rep(j, i + 1, n) {
			while (a[i][i]) { //辗转相减法，避免求逆元
				int div = a[j][i] / a[i][i];
				// a[j][i] = a[j][i] mod a[i][i]
				rep(k, i, n) {
					a[j][k] = (a[j][k] - 1LL * div * a[i][k] % MOD + MOD) % MOD;
				}
				swap(a[i], a[j]);
				f *= -1;
			}
			swap(a[i], a[j]);
			f *= -1;
		}
	}
	int ans = 1;
	rep(i, 1, n) ans = 1LL * ans * a[i][i] % MOD;
	return (ans * f % MOD + MOD) % MOD;
}

int main() {
#ifdef LRL52
	freopen("L.in", "r", stdin);
#endif
	rd(n), rd(m);
	rep(i, 1, m) {
		rd(e[i].u), rd(e[i].v), rd(e[i].w);
	}
	sort(e + 1, e + m + 1);
	Kruskal();
	int ans = 1;
	for (int i = 0; i < W.size(); ++i) {
		Union(W[i]);
		int _n = AddEdge(W[i]) - 1;
		ans = 1LL * ans * Det(_n) % MOD;
	}
	printf("%d\n", ans);
	return 0;
}