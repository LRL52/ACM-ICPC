/*** 
 * @Author: LRL52
 * @Date: 2023-05-05 23:51:00
 * @LastEditTime: 2023-05-06 09:43:18
 */
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
using i64 = long long;
using pii = pair<int, int>;
const int N = 5e3 + 5, inf = 0x3f3f3f3f;
int n, m;
int a[N];
i64 f[N];
bitset<N> G[N];

i64 dfs(int x) {
	if (f[x]) return f[x];
	f[x] = a[x];
	for (int i = 1; i <= n; ++i) {
		if (G[x][i]) {
			dfs(i);
			f[x] = max(f[x], f[i] + a[x]);
		}
	}
	return f[x];
}

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> m >> n;
    for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; ++i) {
		G[i].set();
	}
	for (int i = 1; i <= m; ++i) {
		vector<pii> R(n + 1);;
		int x;
		for (int i = 1; i <= n; ++i) {
			cin >> x;
			// R.emplace_back(x, i);
			R[i] = {x, i};
		}
		sort(R.begin() + 1, R.end());
		bitset<N> mask;
		mask.set(); int p = 0;
		for (int i = 1; i <= n; ++i) {
			while (p < n && R[p + 1].first <= R[i].first) {
				++p;
				mask.set(R[p].second, 0);
			}
			G[R[i].second] &= mask;
		}
	}
	i64 ans = 0;
	for (int i = 1; i <= n; ++i) ans = max(ans, dfs(i));
	cout << ans << endl;
	return 0;
}