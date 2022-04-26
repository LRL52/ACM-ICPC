//ID: LRL52  Date: 2022.4.15
//B题数据太坑了，想了我好久，注意L = 0可能会造成计算重复！！！
#include <cstdio>
#include <cstdlib>
#include <cstring>
//#include <set>
#include <vector>
#include <algorithm>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
const int N = 2e5 + 55, M = 5e5 + 55; char ss[1 << 21], * A = ss, * B = ss, cc;
inline char gc() { return A == B && (B = (A = ss) + fread(ss, 1, 1 << 21, stdin), A == B) ? EOF : *A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
int n, m, L;
int fa[N], a[N];
struct Edge {
	int u, v, w;
	inline bool operator<(const Edge& t)const {
		return w < t.w;
	}
}e[M];
//草, multiset没法查询排名
//multiset<int> s[N];
//multiset<int>::iterator it1, it2;
vector<int> s[N];

int find(int x) {
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}

int main() {
#ifdef LRL52
	freopen("B.in", "r", stdin);
#endif
	rd(n), rd(m), rd(L);
	rep(i, 1, n) rd(a[i]);
	rep(i, 1, m) {
		rd(e[i].u), rd(e[i].v), rd(e[i].w);
	}
	sort(e + 1, e + m + 1);
	rep(i, 1, n) s[i].push_back(a[i]), fa[i] = i;
	int tot = 0; unsigned long long ans = 0LLu;
	rep(i, 1, m) {
		int fu = find(e[i].u), fv = find(e[i].v);
		if (fu == fv) continue;
		if (s[fu].size() > s[fv].size()) swap(fu, fv);
		unsigned long long cnt = 0;
		if (L != 0) {
			for (int j = 0; j < s[fu].size(); ++j) {
				int val = s[fu][j];
				int pos = upper_bound(s[fv].begin(), s[fv].end(), val - L) - s[fv].begin() - 1;
				cnt += max(0, pos + 1);
				pos = lower_bound(s[fv].begin(), s[fv].end(), val + L) - s[fv].begin();
				cnt += max(0, (int)s[fv].size() - pos);
			}
		}
		else
			cnt = s[fu].size() * s[fv].size();
		ans += cnt * e[i].w;
		for (int j = 0; j < s[fu].size(); ++j)
			s[fv].insert(lower_bound(s[fv].begin(), s[fv].end(), s[fu][j]), s[fu][j]);
		fa[fu] = fv;
		if (++tot == n - 1) break;
	}
	printf("%llu\n", ans);
	return 0;
}