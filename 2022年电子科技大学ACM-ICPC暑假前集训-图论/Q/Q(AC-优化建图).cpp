//ID: LRL52  Date: 2022.4.16
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <algorithm>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 1e5 + 55, M = 57800055; char ss[1 << 21], * A = ss, * B = ss, cc;
inline char gc() { return A == B && (B = (A = ss) + fread(ss, 1, 1 << 21, stdin), A == B) ? EOF : *A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
typedef long long LL;
const LL INF = 0x3f3f3f3f3f3f3f3f;
int n, a[N], vis[N], head[N];
LL D, dis[N];
struct Edge {
	int v, nxt; LL w;
}e[M]; //Prim算法由于要建无向边，内存消耗是Kruskal的两倍，算了下999MB内存勉强够，但想练练Prim
struct Node {
	int v; LL d;
	Node(int _v, LL _d) {
		v = _v, d = _d;
	}
	inline bool operator<(const Node& t)const {
		return d > t.d;
	}
};
priority_queue<Node> q;

inline void adde(int from, int to, LL w) {
	static int et = 1;
	e[++et] = { to, head[from], w };
	head[from] = et;
}

void AddEdge(int l, int r) {
	if (l == r) return;
	int mid = (l + r) >> 1;
	//左半区间 aj - j * D 的最小值
	LL j = l, minw = INF;
	rep(k, l, mid)
		if (a[k] - k * D < minw) {
			minw = a[k] - k * D;
			j = k;
		}
	//右半区间 ai + i * D 的最小值
	LL i = mid + 1; minw = INF;
	rep(k, mid + 1, r)
		if (a[k] + k * D < minw) {
			minw = a[k] + k * D;
			i = k;
		}
	rep(k, mid + 1, r) {
		adde(j, k, (LL)a[j] + a[k] + (k - j) * D);
		adde(k, j, (LL)a[j] + a[k] + (k - j) * D);
	}
	rep(k, l, mid) {
		adde(k, i, (LL)a[k] + a[i] + (i - k) * D);
		adde(i, k, (LL)a[k] + a[i] + (i - k) * D);
	}
	AddEdge(l, mid);
	AddEdge(mid + 1, r);
}

int main() {
#ifdef LRL52
	freopen("Q.in", "r", stdin);
#endif
	rd(n), rd(D);
	rep(i, 1, n) rd(a[i]);
	AddEdge(1, n);
	LL ans = 0LL;
	memset(dis, 0x3f, sizeof dis);
	q.push(Node(1, 0)); int tot = 0;
	while (!q.empty()) {
		Node qu = q.top(); q.pop();
		int now = qu.v;
		if (vis[now]) continue;
		vis[now] = 1;
		ans += qu.d;
		if (++tot == n) break;
		ee(i, now) {
			int v = e[i].v;
			if (!vis[v] && e[i].w < dis[v]) {
				dis[v] = e[i].w;
				q.push(Node(v, dis[v]));
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}