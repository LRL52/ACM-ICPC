//最小路径覆盖问题
//最小路径覆盖=点的总数-网络最大流
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <algorithm>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
const int N = 255, M = 6055, _N = N * 2, inf = 0x3f3f3f3f; char ss[1 << 21], * A = ss, * B = ss, cc;
inline char gc() { return A == B && (B = (A = ss) + fread(ss, 1, 1 << 21, stdin), A == B) ? EOF : *A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
struct Edge {
	int v, nxt, cap, w;
}e[2 * M + 4 * N];
deque<int> q;
int n, m, S, T, Fee;
int head[_N], dis[_N], inq[_N], in[_N], vis[_N], Nxt[_N], cur[_N];

inline void adde(int from, int to, int cap, int w) {
	static int et = 1;
	e[++et] = { to, head[from], cap, w };
	head[from] = et;
}

void Adde(int from, int to, int cap, int w) {
	adde(from, to, cap, w);
	adde(to, from, 0, -w);
}

int SPFA() {
	memset(dis, 0x3f, sizeof dis);
	dis[S] = 0; q.push_front(S);
	while (!q.empty()) {
		int now = q.front(); q.pop_front();
		inq[now] = 0;
		for (int i = head[now]; i; i = e[i].nxt) {
			int v = e[i].v;
			if (e[i].cap > 0 && dis[now] + e[i].w < dis[v]) {
				dis[v] = dis[now] + e[i].w;
				if (!inq[v]) {
					inq[v] = 1;
					if (!q.empty() && dis[v] <= dis[q.front()]) q.push_front(v);
					else q.push_back(v);
				}
			}
		}
	}
	return dis[T] != inf;
}

int max_flow(int now, int flow) {
	if (now == T) return flow;
	int t = flow; vis[now] = 1;
	for (int& i = cur[now]; i; i = e[i].nxt) {
		int v = e[i].v;
		if (!vis[v] && e[i].cap > 0 && dis[now] + e[i].w == dis[v]) {
			int dx = max_flow(v, min(flow, e[i].cap));
			flow -= dx, e[i].cap -= dx;
			e[i ^ 1].cap += dx;
			Fee += dx * e[i].w;
			if (flow == 0) break;
		}
	}
	vis[now] = 0;
	return t - flow;
}

int main() {
#ifdef LRL52
	freopen("T.in", "r", stdin);
#endif
	rd(n), rd(m); int x, y;
	rep(i, 1, m) {
		rd(x), rd(y);
		Adde(x, y + n, 1, 0);
	}
	S = 0, T = 2 * n + 1;
	rep(i, 1, n) {
		Adde(S, i, 1, 0);
		Adde(i + n, T, 1, 0);
	}
	int Flow = 0;
	while (SPFA()) {
		rep(i, S, T) cur[i] = head[i];
		Flow += max_flow(S, inf);
	}
	//for (x = 1; x <= n; ++x) {
	//	for (int j = head[x]; j; j = e[j].nxt) {
	//		if (e[j].v == S) continue;
	//		int v = e[j].v - n;
	//		if (e[j].cap == 0) {
	//			Nxt[x] = v;
	//			++in[v];
	//		}
	//	}
	//}
	//for (x = 1; x <= n; ++x) {
	//	if (in[x] != 0) continue;
	//	y = x;
	//	while (y) {
	//		printf("%d ", y);
	//		y = Nxt[y];
	//	}
	//	putchar('\n');
	//}
	printf("%d\n", n - Flow);
	return 0;
}