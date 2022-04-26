//ID: LRL52  Date: 2022.4.14
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
const int N = 555, M = 125555; char ss[1 << 21], * A = ss, * B = ss, cc;
inline char gc() { return A == B && (B = (A = ss) + fread(ss, 1, 1 << 21, stdin), A == B) ? EOF : *A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
typedef long long LL;
int n, m, Now, rk[N][N];
LL dis[N][N];
struct Edge {
	int u, v, w;
}e[M];

struct cmp {
	inline bool operator()(const int& t1, const int& t2)const {
		return dis[Now][t1] < dis[Now][t2];
	}
};

int main() {
#ifdef LRL52
	freopen("N.in", "r", stdin);
#endif
	rd(n), rd(m); int u, v, w;
	memset(dis, 0x3f, sizeof dis);
	rep(i, 1, n) dis[i][i] = 0;
	rep(i, 1, m) {
		rd(u), rd(v), rd(w);
		dis[u][v] = dis[v][u] = min(dis[u][v], (LL)w);
		e[i] = { u, v, w };
	}
	for (int k = 1; k <= n; ++k)
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
	rep(i, 1, n) {
		rep(j, 1, n)
			rk[i][j] = j;
		Now = i;
		sort(rk[i] + 1, rk[i] + n + 1, cmp());
	}
	LL ans = 0x3f3f3f3f3f3f3f3f;
	//图的中心在点上
	rep(i, 1, n) 
		ans = min(ans, 2LL * dis[i][rk[i][n]]); //离图的中心最远的点至少有2个, 因此如果图的中心如果真的在点上，这样算不会错
	//图的中心在边上
	rep(k, 1, m) {
		int u = e[k].u, v = e[k].v, w = e[k].w;
		for (int p = n, i = n - 1; i >= 1; --i) {
			if (dis[v][rk[u][i]] > dis[v][rk[u][p]]) {
				ans = min(ans, dis[u][rk[u][i]] + w + dis[v][rk[u][p]]);
				p = i;
				//break; 感觉只可能更新一次呀
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}