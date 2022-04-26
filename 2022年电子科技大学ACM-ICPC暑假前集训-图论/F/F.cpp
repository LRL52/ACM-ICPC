#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <algorithm>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 5e3 + 55, M = 5e3 + 55; char ss[1 << 21], * A = ss, * B = ss, cc;
inline char gc() { return A == B && (B = (A = ss) + fread(ss, 1, 1 << 21, stdin), A == B) ? EOF : *A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
typedef long long LL;
int n, m, sts;
int head[N], inq_cnt[N];
LL dis[N];
struct Edge {
	int v, nxt, w;
}e[M + N];
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
	freopen("F.in", "r", stdin);
#endif
	rd(n), rd(m); int x, y, z;
	rep(i, 1, m) {
		rd(x), rd(y), rd(z);
		adde(y, x, z);
	}
	rep(i, 1, n) adde(0, i, 0);
	memset(dis, 0x3f, sizeof dis);
	dis[0] = 0;
	q.push({ 0, 0 });
	while (!q.empty()) {
		Node qu = q.top(); q.pop();
		if (qu.d != dis[qu.v]) continue;
		int now = qu.v;
		ee(i, now) {
			int v = e[i].v;
			if (dis[now] + e[i].w < dis[v]) {
				dis[v] = dis[now] + e[i].w;
				q.push({ v, dis[v] });
				if (++inq_cnt[v] > n) {
					puts("NO");
					return 0;
				}
			}
		}
	}
	puts("YES");
	return 0;
}