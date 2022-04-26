//ID: LRL52  Date:2022.4.13
#include <bits/stdc++.h>
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
LL Ans1, Ans2 = 1e18;
clock_t start;
struct Node {
	int u, v; LL w; //u�������������ĵ㣬v�ǵ�ǰ��u������С�ĵ�
	Node(int _u = 0, int _v = 0, LL _w = 0) {
		u = _u, v = _v, w = _w;
	}
	inline bool operator<(const Node& t)const {
		return w < t.w;
	}
};
multiset<Node> s;
multiset<Node>::iterator it;

LL rnd(LL x) { return (LL)RAND_MAX * rand() * rand() % x + 1; }

inline LL cost(int i, int j) { //����ֻ����a[i]�Ĺ���
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

void Solve(int st) {
	LL w = 1e18; int u = 2; LL ans = 0LL;
	rep(i, 1, n) {
		if (i == st) continue;
		if (cost(st, i) + a[i] < w) {
			w = cost(st, i) + a[i];
			u = i;
		}
	}
	ans += w - a[u] - a[st];
	rep(i, 1, n) vis[i] = l[i] = r[i] = Nxt[i] = 0;
	s.clear();
	update(st);
	update(u);
	for (int times = 3; times <= n; ++times) {
		it = s.begin();
		ans += it->w;
		update(it->v);
		if ((double)(clock() - start) / CLOCKS_PER_SEC > 1.95) {
			printf("%lld\n", Ans1 + Ans2);
			exit(0);
		}
	}
	Ans2 = min(Ans2, ans);
}

int main() {
//#ifdef LRL52
	freopen("in.in", "r", stdin);
	freopen("me.out", "w", stdout);
//#endif
	start = clock();
	rd(n), rd(D);
	rep(i, 1, n) rd(a[i]), Ans1 += a[i];
	while (1) {
		Solve(rnd(n));
	}
	//printf("%lld\n", ans);
	return 0;
}