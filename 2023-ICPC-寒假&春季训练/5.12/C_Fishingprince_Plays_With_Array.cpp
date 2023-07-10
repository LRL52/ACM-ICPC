/*** 
 * @Author: LRL52
 * @Date: 2023-05-12 19:41:06
 * @LastEditTime: 2023-05-12 19:59:32
 */
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
using i64 = long long;
using pii = pair<int, int>;
const int N = 2e5 + 55, inf = 0x3f3f3f3f;
int n, m, K;
pii a[N], b[N];

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int Task; cin >> Task;
	while(Task--) { 
		cin >> n >> m;
		for (int i = 1; i <= n; ++i) {
			int x; cin >> x;
			int t = 1;
			while (x % m == 0) {
				x /= m;
				t *= m;
			}
			a[i] = {x, t}; 
		}
		cin >> K;
		for (int i = 1; i <= K; ++i) {
			int x; cin >> x;
			int t = 1;
			while (x % m == 0) {
				x /= m;
				t *= m;
			}
			b[i] = {x, t};
		}
		using pll = pair<i64, i64>;
		vector<pll> c, d;
		for (int i = 1, j; i <= n; i = j + 1) {
			j = i; i64 num = a[i].second;
			while (j < n && a[j + 1].first == a[i].first) {
				num += a[j + 1].second;
				++j;
			}
			c.emplace_back(a[i].first, num);
		}
		for (int i = 1, j; i <= K; i = j + 1) {
			j = i; i64 num = b[i].second;
			while (j < K && b[j + 1].first == b[i].first) {
				num += b[j + 1].second;
				++j;
			}
			d.emplace_back(b[i].first, num);
		}
		if (c == d) puts("Yes");
		else puts("No");
	}
	return 0;
}