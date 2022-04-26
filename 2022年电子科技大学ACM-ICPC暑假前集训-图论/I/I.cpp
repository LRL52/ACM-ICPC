// ID: LRL52  Date: 2022.4.9
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 55, M = 1e6 + 55; char ss[1 << 21], * A = ss, * B = ss, cc;
inline char gc() { return A == B && (B = (A = ss) + fread(ss, 1, 1 << 21, stdin), A == B) ? EOF : *A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0; cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
struct Edge {
	int v, nxt;
}e[M << 1];
int dfn[N << 1], low[N << 1], n, m, scc[N << 1];
int clk, top, head[N << 1], ct, stk[N << 1], co;
template<typename T>inline T cmin(T& x, T y) { return y < x ? x = y : x; }

inline void adde(int from, int to) {
	e[++ct].v = to;
	e[ct].nxt = head[from];
	head[from] = ct;
}

void tarjan(int x) {
	low[x] = dfn[x] = ++clk; stk[top++] = x;
	ee(i, x) {
		int v = e[i].v;
		if (!dfn[v]) {
			tarjan(v);
			cmin(low[x], low[v]);
		}
		else if (!scc[v]) cmin(low[x], dfn[v]);
	}
	if (low[x] == dfn[x]) {
		++co;
		do {
			int v = stk[--top];
			scc[v] = co;
		} while (stk[top] != x);
	}
}

int main()
{
	freopen("I.in", "r", stdin);
	rd(n), rd(m); int x, y, a, b;
	rep(i, 1, m) {
		rd(x), rd(a), rd(y), rd(b);
		adde(x + n * (a & 1), y + n * (b ^ 1));
		adde(y + n * (b & 1), x + n * (a ^ 1));
	}
	rep(i, 1, n << 1) if (!dfn[i]) tarjan(i);
	rep(i, 1, n) {
		if (scc[i] == scc[i + n]) {
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	//rep(i, 1, n) printf("%d ", scc[i + n] > scc[i]);
	return 0;
}