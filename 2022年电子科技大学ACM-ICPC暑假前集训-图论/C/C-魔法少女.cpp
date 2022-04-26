//ID:LRL52  Date: 2022.4.12
//万恶的网络瘤，太久没练了，想了好久才想出建模方法
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <algorithm>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
const int N = 505, maxn = 2 * N * N, inf = 0x3f3f3f3f;
struct Edge {
	int v, nxt, cap, w;
}e[10 * N * N];
deque<int> q;
int n, m, S, T, Fee;
int head[maxn], dis[maxn], cur[maxn], vis[maxn], inq[maxn];
char s[N];

inline void adde(int from, int to, int cap, int w) {
	static int et = 1;
	e[++et] = { to, head[from], cap, w };
	head[from] = et;
}

void Adde(int from, int to, int cap, int w) {
	adde(from, to, cap, w);
	adde(to, from, 0, -w);
}

inline int in_node(int i, int j) {
	return (i - 1) * (m + 1) + j;
}

inline int out_node(int i, int j) {
	return (n + 1) * (m + 1) + in_node(i, j);
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
	freopen("C.in", "r", stdin);
#endif
	scanf("%d%d", &n, &m);
	rep(i, 1, n) {
		scanf("%s", s + 1);
		rep(j, 1, m) {
			if (s[j] == '\\') {
				Adde(out_node(i, j), in_node(i + 1, j + 1), 1, 0);
				Adde(out_node(i + 1, j + 1), in_node(i, j), 1, 0);
				Adde(out_node(i + 1, j), in_node(i, j + 1), 1, 1);
				Adde(out_node(i, j + 1), in_node(i + 1, j), 1, 1);
			}
			else {
				Adde(out_node(i, j), in_node(i + 1, j + 1), 1, 1);
				Adde(out_node(i + 1, j + 1), in_node(i, j), 1, 1);
				Adde(out_node(i + 1, j), in_node(i, j + 1), 1, 0);
				Adde(out_node(i, j + 1), in_node(i + 1, j), 1, 0);
			}
		}
	}
	rep(i, 1, n + 1)
		rep(j, 1, m + 1)
			Adde(in_node(i, j), out_node(i, j), 1, 0);
	S = in_node(1, 1), T = out_node(n + 1, m + 1);
	int Flow = 0;
	while (SPFA()) {
		rep(i, 1, T) cur[i] = head[i];
		Flow += max_flow(S, inf);
	}
	//printf("%d %d\n", Flow, Fee);
	if (Flow > 0) printf("%d\n", Fee);
	else puts("NO SOLUTION");
	return 0;
}