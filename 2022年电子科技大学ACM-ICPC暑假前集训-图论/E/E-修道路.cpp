//ID: LRL52  Date: 2022.4.16
//坑点：1.终点是1号点的时候输出a[1] 2. 点双缩点N, M开2倍空间！！！
//Lutece assert报错是MLE不是RE
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
//#include <assert.h>
#include <algorithm>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 2e5 + 55, M = 4e5 + 55, QN = 1e6 + 55; char ss[1 << 21], * A = ss, * B = ss, cc;
inline char gc() { return A == B && (B = (A = ss) + fread(ss, 1, 1 << 21, stdin), A == B) ? EOF : *A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
bool st;
int debug;
int n, m, DFN, top, root, cnt, et;
int head1[N], head2[N], low[N], dfn[N], Ans[N], Q[QN], stk[N], cut[N];
int W[N], a[N], belong[N];
int* head;
struct Edge {
	int v, nxt;
}e1[M << 1], e2[M << 1];
Edge* e;
vector<int> dcc[N];
bool ed;


inline void adde(int from, int to) {
	//static int et = 0;
	e[++et] = { to, head[from]};
	head[from] = et;
	//assert(et < (200055 << 1));
}

namespace vDCC {
	void tarjan(int x) {
		dfn[x] = low[x] = ++DFN;
		stk[++top] = x;
		if (x == root && head[x] == 0) {
			dcc[++cnt].push_back(x);
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
					cnt++; W[cnt] = a[x];
					int z;
					do
					{
						z = stk[top--];
						W[cnt] = min(W[cnt], a[z]);
						dcc[cnt].push_back(z);
						//assert(++debug < 100055);
					} while (z != v);
					dcc[cnt].push_back(x);
				}
			}
			else low[x] = min(low[x], dfn[v]);
		}
	}
}

void dfs(int x, int w, int far) {
	Ans[x] = w;
	ee(i, x) {
		int v = e[i].v;
		if (v == far) continue;
		dfs(v, min(w, W[v]), x);
	}
}

int main() {
#ifdef LRL52
	freopen("E.in", "r", stdin);
#endif
	int qs, x, y; head = head1, e = e1;
	rd(n), rd(m), rd(qs);
	rep(i, 1, m) {
		rd(x), rd(y);
		//assert(x < 0);
		//assert(y < 0);
		adde(abs(x), abs(y));
		adde(abs(y), abs(x));
	}
	rep(i, 1, n) rd(a[i]);
	rep(i, 1, qs) rd(Q[i]); //assert(Q[i] > 0);
	rep(i, 1, n) {
		if (!dfn[i]) {
			root = i;
			vDCC::tarjan(i);
		}
	}
	int numN = cnt;
	rep(i, 1, n)
		if (cut[i]) belong[i] = ++numN, W[numN] = a[i];
	et = 0, head = head2, e = e2;
	//assert(numN < 100055);
	rep(i, 1, cnt) {
		for (int j = 0; j < dcc[i].size(); ++j) {
			int x = dcc[i][j];
			if (cut[x]) {
				adde(i, belong[x]);
				adde(belong[x], i);
			}
			else belong[x] = i;
		}
	}
	//assert(et == ((numN-1) << 1));
	dfs(belong[1], W[belong[1]], -1);
	rep(i, 1, qs) {
		if (Q[i] == 1) printf("%d\n", a[1]);
		else {
			x = belong[Q[i]];
			printf("%d\n", Ans[x]);
		}
	}
	//printf("%.3lf MB\n", (double)(&ed - &st) / (1 << 20));
	return 0;
}
