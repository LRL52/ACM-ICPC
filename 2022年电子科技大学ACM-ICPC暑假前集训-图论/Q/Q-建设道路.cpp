//ID: LRL52  Date:2022.4.13
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <set>
#include <algorithm>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
const int N = 1e5 + 55, inf = 0x3f3f3f3f; char ss[1 << 21], * A = ss, * B = ss, cc;
inline char gc() { return A == B && (B = (A = ss) + fread(ss, 1, 1 << 21, stdin), A == B) ? EOF : *A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
typedef long long LL;
int n, D;
int a[N], vis[N], l[N], r[N], Nxt[N];
struct Node {
	int u, v; LL w; //u是已在生成树的点，v是当前离u代价最小的点
	Node(int _u = 0, int _v = 0, LL _w = 0) {
		u = _u, v = _v, w = _w;
	}
	inline bool operator<(const Node& t)const {
		return w < t.w;
	}
};
multiset<Node> s;
multiset<Node>::iterator it;

inline LL cost(int i, int j) { //这里只计算a[i]的贡献
	return (LL)abs(i - j) * D + a[i];
}

void chk(int i) {
	int nxt = 0;
	if ((l[i] > 0 ? i - l[i] : inf) < (r[i] <= n ? r[i] - i : inf))
		nxt = l[i];
	else
		nxt = r[i];
	if (nxt != Nxt[i]) {
		it = s.lower_bound(Node(i, Nxt[i], cost(i, Nxt[i])));
		for (; it != s.end(); it++) {
			if (it->u != i) continue;
			s.erase(it);
			Nxt[i] = nxt;
			s.insert(Node(i, Nxt[i], cost(i, Nxt[i])));
			break;
		}
	}
}

void update(int u) {
	if (!vis[u - 1]) l[u] = u - 1;
	else l[u] = l[u - 1];
	if (!vis[u + 1]) r[u] = u + 1;
	else r[u] = r[u + 1];
	for (int i = u - 1; i >= 1; --i) {
		if (!vis[i]) break;
		r[i] = r[u];
		chk(i);
	}
	for (int i = u + 1; i <= n; ++i) {
		if (!vis[i]) break;
		l[i] = l[u];
		chk(i);
	}
	vis[u] = 1;
	if ((l[u] > 0 ? u - l[u] : inf) < (r[u] <= n ? r[u] - u : inf))
		Nxt[u] = l[u];
	else
		Nxt[u] = r[u];
	s.insert(Node(u, Nxt[u], cost(u, Nxt[u])));
}

int main() {
//#ifdef LRL52
	freopen("in.in", "r", stdin);
	//freopen("me.out", "w", stdout);
//#endif
	rd(n), rd(D); int u = 2; LL ans = 0LL, w = 1e18;
	rep(i, 1, n) rd(a[i]), ans += a[i];
	rep(i, 2, n) {
		if (cost(1, i) + a[i] < w) {
			w = cost(1, i) + a[i];
			u = i;
		}
	}
	ans += w - a[u] - a[1];
	update(1);
	update(u);
	for (int times = 3; times <= n; ++times) {
		it = s.begin();
		ans += it->w;
		update(it->v);
	}
	printf("%lld\n", ans);
	return 0;
}