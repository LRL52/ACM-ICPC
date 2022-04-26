//ID: LRL52  Date: 2022.4.18
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <assert.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
//using namespace std;
const int N = 2e6 + 55, M = 2e6 + 55; char ss[1 << 21], * A = ss, * B = ss, cc;
inline char gc() { return A == B && (B = (A = ss) + fread(ss, 1, 1 << 21, stdin), A == B) ? EOF : *A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
typedef long long LL;
int n, m, top, DFN, et, et2, Num, root;
int stk[N], a[N], low[N], dfn[N], head[N], head2[N], cut[N], size[N];
LL Ans, Sum, sum[N];
struct Edge {
	int v, nxt;
}e[M << 1], e2[M << 1];

inline void adde(int from, int to) {
	e[++et] = { to, head[from] };
	head[from] = et;
}

inline void adde2(int from, int to) {
	e2[++et2] = { to, head2[from] };
	head2[from] = et2;
}

void tarjan(int x) {
	dfn[x] = low[x] = ++DFN;
	stk[++top] = x;
	//if (x == root && head[x] == 0) {
	//	assert(0);
	//}
	int flag = 0;
	ee(i, x) {
		int v = e[i].v;
		if (!dfn[v]) {
			tarjan(v);
			low[x] = std::min(low[x], low[v]);
			if (low[v] >= dfn[x]) {
				flag++;
				if (x != root || flag > 1) cut[x] = 1;
				++Num;
				int z;
				do
				{
					z = stk[top--];
					adde2(z, Num);
					adde2(Num, z);
				} while (z != v);
				adde2(x, Num);
				adde2(Num, x);
			}
		}
		else low[x] = std::min(low[x], dfn[v]);
	}
}

void dfs(int x, int far) { 
	for (int i = head2[x]; i; i = e2[i].nxt) {
		int v = e2[i].v;
		if (v == far) continue;
		dfs(v, x);
		size[x] += size[v];
		sum[x] += sum[v];
	}
	if (x <= n) {
		size[x] += 1, sum[x] += a[x];
		LL ans = 0LL;
		for (int i = head2[x]; i; i = e2[i].nxt) {
			int v = e2[i].v;
			if (v == far) continue;
			if (size[v] & 1)
				ans -= sum[v];
			else
				ans += sum[v];
		}
		if ((n - size[x]) & 1)
			ans -= Sum - sum[x];
		else
			ans += Sum - sum[x];
		ans -= a[x];
		Ans = std::max(Ans, ans);
	}
}

void Solve() {
	rd(n), rd(m); Sum = 0LL;
	rep(i, 1, n) rd(a[i]), Sum += a[i];
	//memset(head, 0, sizeof head);
	rep(i, 0, n) head[i] = 0;
	et = 0; int x, y;
	rep(i, 1, m) {
		rd(x), rd(y);
		adde(x, y), adde(y, x);
	}
	if ((n & 1) == 0) {
		printf("%lld\n", Sum);
		return;
	}
	//memset(dfn, 0, sizeof dfn);
	//memset(low, 0, sizeof low);
	//memset(cut, 0, sizeof cut);
	rep(i, 0, n) dfn[i] = low[i] = cut[i] = head2[i] = 0;
	rep(i, n + 1, 2 * n) head2[i] = 0;
	//memset(head2, 0, sizeof head2);
	DFN = top = et2 = 0; Num = n;
	rep(i, 1, n) {
		if (!dfn[i]) {
			root = i;
			tarjan(i);
		}
	}
	rep(i, 0, 2 * n) size[i] = sum[i] = 0;
	//memset(size, 0, sizeof size);
	//memset(sum, 0, sizeof sum);
	Ans = -1e16;
	assert(et2 == (Num - 1) << 1);
	dfs(1, -1);
	printf("%lld\n", Ans);
}


int main() {
#ifdef LRL52
	freopen("H.in", "r", stdin);
	freopen("H.out", "w", stdout);
#endif
	int T; rd(T);
	while (T--) Solve();
	return 0;
}