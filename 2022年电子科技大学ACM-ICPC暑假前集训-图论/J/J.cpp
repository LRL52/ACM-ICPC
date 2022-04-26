#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 1055, M = 1e6 + 55; char ss[1 << 21], * A = ss, * B = ss, cc;
inline char gc() { return A == B && (B = (A = ss) + fread(ss, 1, 1 << 21, stdin), A == B) ? EOF : *A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
int n, m, top, edge_cnt, DFN, root, cnt;
int et = 1, ans = 0;
int low[N], dfn[N], stk[N], vis[N], is_dcc[N], head[N], cut[N], bridge[M << 1];
vector<int> dcc[N];
struct Edge {
	int v, nxt;
}e[M << 1];

inline void adde(int from, int to) {
	e[++et] = { to, head[from] };
	head[from] = et;
}

namespace Cut {
	void tarjan(int x) {
		dfn[x] = low[x] = ++DFN;
		int flag = 0;
		ee(i, x) {
			int v = e[i].v;
			if (!dfn[v]) {
				tarjan(v);
				low[x] = min(low[x], low[v]);
				if (low[v] >= dfn[x]) {
					++flag;
					if (x != root || flag > 1) cut[x] = 1;
				}
			}
			else low[x] = min(low[x], dfn[v]);
		}
	}
}

namespace Bridge {
	void tarjan(int x, int lst) {
		dfn[x] = low[x] = ++DFN;
		ee(i, x) {
			int v = e[i].v;
			if (!dfn[v]) {
				tarjan(v, i);
				low[x] = min(low[x], low[v]);
				if (low[v] > dfn[x])
					bridge[i] = bridge[i ^ 1] = 1;
			}
			else if (i != (lst ^ 1))
				low[x] = min(low[x], dfn[v]);
		}
	}
}

namespace vDCC {
	void tarjan(int x) {
		dfn[x] = low[x] = ++DFN;
		stk[++top] = x;
		if (x == root && head[x] == 0) {
			//dcc[++cnt].push_back(x);
			return;
		}
		int flag = 0;
		ee(i, x) {
			int v = e[i].v;
			if (!dfn[v]) {
				tarjan(v);
				low[x] = min(low[x], low[v]);
				if (low[v] >= dfn[x]) {
					flag++;
					if (x != root || flag > 1) cut[x] = 1;
					cnt++;
					int z;
					do
					{
						z = stk[top--];
						dcc[cnt].push_back(z);
					} while (z != v);
					dcc[cnt].push_back(x);
				}
			}
			else low[x] = min(low[x], dfn[v]);
		}
	}
	void dfs(int x) {
		vis[x] = 1;
		ee(i, x) {
			int v = e[i].v;
			if (!is_dcc[v]) continue;
			++edge_cnt;
			if (!vis[v])
				dfs(v);
		}
	}
}

int main() {
#ifdef LRL52
	freopen("J.in", "r", stdin);
#endif
	rd(n), rd(m); int x, y;
	rep(i, 1, m) {
		rd(x), rd(y);
		adde(x, y), adde(y, x);
	}
	rep(i, 1, n) {
		if (!dfn[i]) {
			root = i;
			Cut::tarjan(i);
		}
	}
	rep(i, 1, n) if (cut[i]) ++ans;
	printf("%d ", ans);
	memset(dfn, 0, sizeof dfn);
	memset(low, 0, sizeof low);
	DFN = 0;
	rep(i, 1, n) {
		if (!dfn[i])
			Bridge::tarjan(i, 0);
	}
	ans = 0;
	for (int i = 2; i < et; i += 2) if (bridge[i]) ++ans;
	printf("%d ", ans);
	memset(dfn, 0, sizeof dfn);
	memset(low, 0, sizeof low);
	DFN = 0;
	rep(i, 1, n) {
		if (!dfn[i]) {
			root = i;
			vDCC::tarjan(i);
		}
	}
	printf("%d ", cnt);
	ans = 0;
	for (int i = 1; i <= cnt; ++i) {
		for (int j = 0; j < dcc[i].size(); ++j) {
			x = dcc[i][j];
			is_dcc[x] = 1;
		}
		x = dcc[i][0];
		edge_cnt = 0;
		vDCC::dfs(x);
		ans = max(ans, edge_cnt/2);
		for (int j = 0; j < dcc[i].size(); ++j) {
			x = dcc[i][j];
			is_dcc[x] = vis[x] = 0;
		}
	}
	printf("%d\n", ans);
	return 0;
}