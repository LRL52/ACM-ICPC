/* ID: LRL52  Date: 2022.4.9  */
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
#include<bits/stdc++.h>
using namespace std;
const int N = 5055, M = 200055; char ss[1 << 21], * A = ss, * B = ss, cc;
inline char gc() { return A == B && (B = (A = ss) + fread(ss, 1, 1 << 21, stdin), A == B) ? EOF : *A++; }
template<class T>inline void rd(T & x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
int K, ct = 0, head[N], ct2 = 0, head2[N], n, m, ans = 0;
int f[N];
struct edge {
	int v, nxt, w;
}e[M], e2[M];

struct node {
	int v, dis, dx;
	inline bool operator<(const node& rhs)const {
		return dis + dx > rhs.dis + rhs.dx;
	}
	node(int _v = 0, int _dis = 0, int _dx = 0) {
		v = _v; dis = _dis; dx = _dx;
	}
};
priority_queue<node> q;

inline void adde(int from, int to, int w) {
	e[++ct].v = to;
	e[ct].nxt = head[from];
	e[ct].w = w;
	head[from] = ct;
}

inline void adde2(int from, int to, int w) {
	e2[++ct2].v = to;
	e2[ct2].nxt = head2[from];
	e2[ct2].w = w;
	head2[from] = ct2;
}

int main()
{
	freopen("M.in", "r", stdin);
	rd(n), rd(m), rd(K);
	int x, y, z;
	rep(i, 1, m) {
		rd(x), rd(y), rd(z);
		adde(x, y, z); adde2(y, x, z);
	}
	rep(i, 1, n) f[i] = 2000000055;
	//Dijkstra求出估价函数f(x)
	f[n] = 0; q.push(node(n, 0, 0));
	while (!q.empty()) {
		node qu = q.top(); q.pop(); int x = qu.v;
		if (qu.dis > f[x]) continue;
		for (int i = head2[x]; i; i = e2[i].nxt) {
			int v = e2[i].v; int w = e2[i].w;
			if (f[x] + w < f[v]) {
				f[v] = f[x] + w;
				q.push(node(v, f[v], 0));
			}
		}
	}
	//A* BFS() 求K短路
	q.push(node(1, 0, f[1])); int outq = 0;
	while (!q.empty()) {
		node qu = q.top(); q.pop(); x = qu.v;
		if (x == n && ++outq == K) {
			printf("%d\n", qu.dis);
			return 0;
		}
		ee(i, x) {
			int v = e[i].v; int w = e[i].w;
			q.push(node(v, qu.dis + w, f[v]));
			//printf("v = %d  dis = %.2lf dx = %.2lf\n", v, qu.dis + w, f[v]);
		}
	}
	return 0;
}