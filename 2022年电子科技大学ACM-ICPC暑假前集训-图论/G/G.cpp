//ID: LRL52  Date: 2022.4.20-4.21
#pragma GCC optimize(2)
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <algorithm>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 405 * 2; char ss[1 << 21], * A = ss, * B = ss, cc;
inline char gc() { return A == B && (B = (A = ss) + fread(ss, 1, 1 << 21, stdin), A == B) ? EOF : *A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
typedef long long LL;
const int _inf = 0xc1c1c1c1, inf = 0x3f3f3f3f; 
int n, S, T, Fee;
LL a[N], b[N], c[N];
int head[N], w[N], dis[N], inq[N], vis[N], cur[N], sum[N];
struct Edge {
	int v, nxt, cap, w;
}e[(N * N + 2 * N) * 2];
deque<int> q;
struct Node{
    LL c; int w;
    Node(LL _c = 0, int _w = 0){
        c = _c, w = _w;
    }
    inline bool operator<(const Node&t)const{
        return c < t.c;
    }
}U[N];

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
	memset(dis, -0x3f, sizeof dis);
	dis[S] = 0; q.push_front(S);
	while (!q.empty()) {
		int now = q.front(); q.pop_front();
		inq[now] = 0;
		for (int i = head[now]; i; i = e[i].nxt) {
			int v = e[i].v;
			if (e[i].cap > 0 && dis[now] + e[i].w > dis[v]) {
				dis[v] = dis[now] + e[i].w;
				if (!inq[v]) {
					inq[v] = 1;
					if (!q.empty() && dis[v] >= dis[q.front()]) q.push_front(v);
					else q.push_back(v);
				}
			}
		}
	}
	return dis[T] != _inf;
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
	freopen("G.in", "r", stdin);
#endif
    rd(n);
    rep(i, 1, n) rd(c[i]);
    rep(i, 1, n) rd(w[i]);
    rep(i, 1, n) rd(a[i]);
    rep(i, 1, n) rd(b[i]);
    rep(i, 1, n) U[i].c = c[i], U[i].w = w[i];
    sort(U + 1, U + n + 1);
    rep(i, 1, n) sum[i] = sum[i - 1] + U[i].w;
    rep(i, 1, n){
        rep(j, 1, n){
            LL d = a[i] + b[j];
            //int W = 0;
            /*rep(k, 1, n){
                if(d > c[k])
                    W += w[k];
            }*/
            int pos = lower_bound(U + 1, U + n + 1, Node(d, 0)) - U - 1;
            Adde(i, j + n, 1, sum[pos]);
            //printf("%d -> %d w = %d\n", i, j + n, W);
        }
    }
    S = 0, T = 2 * n + 1;
    rep(i, 1, n) Adde(S, i, 1, 0);
    rep(i, n + 1, 2 * n) Adde(i, T, 1, 0);
    int Flow = 0;
    while(SPFA()){
        rep(i, 0, T) cur[i] = head[i];
        Flow += max_flow(S, inf);
    }
    printf("%d\n", Fee);
	return 0;
}