//�����㷨 ��С����ͼ
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
const int N = 105, M = 1e4 + 55, inf = 0x3f3f3f3f; char ss[1 << 21], * A = ss, * B = ss, cc;
inline char gc() { return A == B && (B = (A = ss) + fread(ss, 1, 1 << 21, stdin), A == B) ? EOF : *A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
int n, m, Ans, root;
int circle[N], belong[N], fa[N], minw[N];
struct Edge {
	int u, v, w;
}e[M];

int Solve() {
	int cntN;
	while (1) {
		cntN = 0;
		rep(i, 1, n) belong[i] = circle[i] = fa[i] = 0, minw[i] = inf;
		rep(i, 1, m) {
			int u = e[i].u, v = e[i].v;
			if (u != v && e[i].w < minw[v]) { //u != v ��ֹ�Ի���Ҳ�����������㷨����������������Ի�
				minw[v] = e[i].w;
				fa[v] = u;
			}
		}
		rep(i, 1, n) {
			if (i == root) continue;
			if (minw[i] == inf) return 0;
			Ans += minw[i];
			//�ⲿ�����Ҿ�����˼���Ǻ�����ĳ�����ӵ��Ż�д������֤ÿ�����ǹ��˾Ͳ����ٷ��ʣ��Ӷ���֤��O(n(n+m))�ĸ��Ӷ�
			//�ѵ��ñ��iȾɫ���Ӷ�ʹ�����������˳�ѭ�����u���ڻ��л����Ѿ����ʹ��ĵ�
			int u = i;
			for (; u != root && !belong[u]; u = fa[u]) //belong���൱��Ⱦɫ���һ��
				belong[u] = i;
			if (belong[u] == i) { //�ɻ�
				circle[u] = ++cntN;
				for (int v = fa[u]; v != u; v = fa[v]) circle[v] = cntN;
			}
		}
		if (!cntN) return 1;
		rep(i, 1, n)
			if (!circle[i])
				circle[i] = ++cntN;
		rep(i, 1, m) {
			int val = minw[e[i].v];
			int u = (e[i].u = circle[e[i].u]);
			int v = (e[i].v = circle[e[i].v]);
			if (u != v)
				e[i].w -= val;
		}
		n = cntN, root = circle[root];
	}
}


int main() {
#ifdef LRL52
	freopen("R.in", "r", stdin);
#endif
	rd(n), rd(m), rd(root);
	rep(i, 1, m) {
		rd(e[i].u), rd(e[i].v), rd(e[i].w);
	}
	if (Solve()) printf("%d\n", Ans);
	else puts("-1");
	return 0;
}