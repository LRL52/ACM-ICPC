#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <algorithm>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 1e5 + 55, M = 2e5 + 55; char ss[1 << 21], * A = ss, * B = ss, cc;
inline char gc() { return A == B && (B = (A = ss) + fread(ss, 1, 1 << 21, stdin), A == B) ? EOF : *A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
typedef long long LL;
int n, m, sts;
int head[N];
LL dis[N];
struct Edge {
	int v, nxt, w;
}e[M];
struct Node {
	int v; LL d;
	inline bool operator<(const Node& rhs)const {
		return d > rhs.d;
	}
};
priority_queue<Node> q;

inline void adde(int from, int to, int w) {
	static int et = 0;
	e[++et] = { to, head[from], w };
	head[from] = et;
}


int main() {
#ifdef LRL52
	freopen("O.in", "r", stdin);
#endif
	rd(n), rd(m), rd(sts); int x, y, z;
	rep(i, 1, m) {
		rd(x), rd(y), rd(z);
		adde(x, y, z);
	}
	memset(dis, 0x3f, sizeof dis);
	dis[sts] = 0;
	q.push({ sts, 0 });
	while (!q.empty()) {
		Node qu = q.top(); q.pop();
		if (qu.d != dis[qu.v]) continue;
		int now = qu.v;
		ee(i, now) {
			int v = e[i].v;
			if (dis[now] + e[i].w < dis[v]) {
				dis[v] = dis[now] + e[i].w;
				q.push({ v, dis[v] });
			}
		}
	}
	rep(i, 1, n) {
		if (dis[i] > 1e15) puts("-1");
		else printf("%lld\n", dis[i]);
	}
	return 0;
}