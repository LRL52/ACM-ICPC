//ID: LRL52  Date: 2022.4.22
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <cmath>
#include <utility>
#include <assert.h>
#include <algorithm>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 405, N1 = N * N, N2 = N1 << 2; char ss[1 << 21], * A = ss, * B = ss, cc;
inline char gc() { return A == B && (B = (A = ss) + fread(ss, 1, 1 << 21, stdin), A == B) ? EOF : *A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
//注：小写的变量和函数均表示原图，大写的变量和函数均表示拆点图, Edge, Node表示两者
typedef long long LL;
int n, m;
int head[N1], pre[N1], vis[N][N], heng[N][N], shu[N][N], a[N][N];
int Head[N2];
LL dis[N1], Dis[N2];

struct Edge {
	int v, nxt, w, ban;
}e[4 * N * N], E[16 * N * N];
struct Node {
	int v; LL d;
	Node(int _v = 0, LL _d = 0LL) {
		v = _v, d = _d;
	}
	inline bool operator<(const Node& t)const {
		return d > t.d;
	}
};
priority_queue<Node> q;
pair<int, int> Z[N * N]; //拆点前的坐标 

inline void adde(int from, int to, int w) {
	static int et = 0;
	e[++et].v = to, e[et].nxt = head[from], e[et].w = w;
	head[from] = et;
	assert(et < 4 * N * N);
}

inline void Adde(int from, int to, int w) {
	static int Et = 0;
	E[++Et].v = to, E[Et].nxt = Head[from], E[Et].w = w;
	Head[from] = Et;
	assert(Et < 16 * N * N);
}

inline int getidx(int i, int j) {
	return (i - 1) * (m + 1) + j;
}

inline int Getidx(int i, int j, int k) {
	return getidx(i, j) + (k - 1) * (n + 1) * (m + 1);
}


void dij() {
	memset(dis, 0x3f, sizeof dis);
	int sts = getidx(1, 1);
	dis[sts] = 0LL; q.push(Node(sts, 0LL));
	while (!q.empty()) {
		Node qu = q.top(); q.pop();
		int now = qu.v;
		if (dis[now] != qu.d) continue;
		for (int i = head[now]; i; i = e[i].nxt) {
			int v = e[i].v;
			if (dis[now] + e[i].w < dis[v]) {
				dis[v] = dis[now] + e[i].w;
				pre[v] = now;
				q.push(Node(v, dis[v]));
			}
		}
	}
}

void DelEdge(int x, int y, int k1, int k2) {
	int u = Getidx(x, y, k1), v = Getidx(x, y, k2);
	int cnt = 0;
	for (int i = Head[u]; i; i = E[i].nxt) {
		int z = E[i].v;
		if (z == v) {
			E[i].ban = 1;
			++cnt;
			//break;
		}
	}
	assert(cnt == 1);
	cnt = 0;
	for (int i = Head[v]; i; i = E[i].nxt) {
		int z = E[i].v;
		if (z == u) {
			E[i].ban = 1;
			++cnt;
			//break;
		}
	}
	assert(cnt == 1);
}

void getpath(int x, int y) {
	if (x == 1 && y == 1) return;
	if (vis[x][y]) return;
	vis[x][y] = 1;
	int idx = getidx(x, y);
	int lx = Z[pre[idx]].first, ly = Z[pre[idx]].second; //lastX, lastY
	if (x == lx && abs(y - ly) == 1) {
		if (ly < y) {
			DelEdge(x, y, 1, 4);
			DelEdge(lx, ly, 2, 3);
		}
		else {
			DelEdge(x, y, 2, 3);
			DelEdge(lx, ly, 1, 4);
		}
	}
	else if (y == ly && abs(x - lx) == 1) {
		if (lx < x) {
			DelEdge(x, y, 1, 2);
			DelEdge(lx, ly, 4, 3);
		}
		else {
			DelEdge(x, y, 4, 3);
			DelEdge(lx, ly, 1, 2);
		}
	}
	else assert(0);
	getpath(lx, ly);
}

void Dij() {
	memset(Dis, 0x3f, sizeof Dis);
	int sts = Getidx(1, 1, 2);
	Dis[sts] = 0LL, q.push(Node(sts, 0LL));
	while (!q.empty()) {
		Node qu = q.top(); q.pop();
		int now = qu.v;
		if (Dis[now] != qu.d) continue;
		for (int i = Head[now]; i; i = E[i].nxt) {
			if (E[i].ban) continue;
			int v = E[i].v;
			if (Dis[now] + E[i].w < Dis[v]) {
				Dis[v] = Dis[now] + E[i].w;
				q.push(Node(v, Dis[v]));
			}
		}
	}
}

int main() {
#ifdef LRL52
	freopen("P.in", "r", stdin);
#endif
	rd(n), rd(m); int x;
	rep(i, 1, n)
		rep(j, 1, m)
			rd(a[i][j]);
	rep(i, 1, n)
		rep(j, 1, m + 1) {
			rd(x); shu[i][j] = x;
			int u = getidx(i, j), v = getidx(i + 1, j);
			adde(u, v, x), adde(v, u, x);
		}
	rep(i, 1, n + 1)
		rep(j, 1, m){
			rd(x); heng[i][j] = x;
			int u = getidx(i, j), v = getidx(i, j + 1);
			adde(u, v, x), adde(v, u, x);
		}
	dij();
	rep(i, 1, n + 1)
		rep(j, 1, m + 1)
			Z[getidx(i, j)] = make_pair(i, j);
	rep(i, 1, n + 1) {
		rep(j, 1, m + 1) {
			if (j < m + 1) {
				int u = Getidx(i, j, 2), v = Getidx(i, j + 1, 1), w = heng[i][j];
				Adde(u, v, w), Adde(v, u, w);
				u = Getidx(i, j, 3), v = Getidx(i, j + 1, 4);
				Adde(u, v, w), Adde(v, u, w);
			}
			if (i < n + 1) {
				int u = Getidx(i, j, 4), v = Getidx(i + 1, j, 1), w = shu[i][j];
				Adde(u, v, w), Adde(v, u, w);
				u = Getidx(i, j, 3), v = Getidx(i + 1, j, 2);
				Adde(u, v, w), Adde(v, u, w);
			}
			int u = Getidx(i, j, 1), v = Getidx(i, j, 2), y = Getidx(i, j, 3), z = Getidx(i, j, 4);
			Adde(u, v, 0), Adde(v, u, 0);
			Adde(v, y, 0), Adde(y, v, 0);
			Adde(y, z, 0), Adde(z, y, 0);
			Adde(z, u, 0), Adde(u, z, 0);
		}
	}
	rep(i, 1, n)
		rep(j, 1, n){
			if(a[i][j] == 0) continue;
			//删除最短路径上的跨越边
			getpath(i, j);
			//删除特殊格外圈连向内圈的边
			DelEdge(i, j, 3, 4);
			DelEdge(i, j, 3, 2);
			DelEdge(i, j + 1, 1, 4);
			DelEdge(i, j + 1, 4, 3);
			DelEdge(i + 1, j, 1, 2);
			DelEdge(i + 1, j, 2, 3);
			DelEdge(i + 1, j + 1, 1, 2);
			DelEdge(i + 1, j + 1, 1, 4);
		}
	DelEdge(1, 1, 1, 4);
	DelEdge(1, 1, 1, 2);
	Dij();
	int ed = Getidx(1, 1, 4);
	assert(Dis[ed] != Dis[0]);
	printf("%lld\n", Dis[ed]);
	return 0;
}