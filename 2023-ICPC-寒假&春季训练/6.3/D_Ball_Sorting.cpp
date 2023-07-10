/*** 
 * @Author: LRL52
 * @Date: 2023-06-04 12:32:52
 * @LastEditTime: 2023-06-04 13:11:24
 */
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
using i64 = long long;
using pii = pair<int, int>;
const int N = 1e3 + 55, inf = 0x3f3f3f3f, MOD = 1e9 + 7;

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int Task; cin >> Task;
	while(Task--) { 
		int n; cin >> n;
		vector<int> a(n + 1);
		for (int i = 1; i <= n; ++i) cin >> a[i];
		vector<vector<int> > f(n + 1, vector<int>(n + 1, -inf));
		f[0][0] = 0;
		for (int i = 1; i <= n; ++i) {
			for (int j = 0; j <= i; ++j) {
				if (a[i - 1] < a[i] && f[i - 1][j] != -inf) {
					f[i][j] = max(f[i][j], f[i - 1][j] + 1);
				}
				if (j == 0) continue;
				for (int k = 0; k < i - 1; ++k) {
					if (a[k] < a[i] && f[k][j - 1] != -inf) {
						f[i][j] = max(f[i][j], f[k][j - 1] + 1);
					}
				}
			}
		}
		vector<int> Ans(n + 1, n);
		for (int i = 1; i <= n; ++i) {
			for (int j = 0; j <= i; ++j) {
				auto cnt = j + (i < n);
				Ans[cnt] = min(Ans[cnt], n - f[i][j]);
				// if (cnt == 1) {
				// 	printf("i = %d j =%d f[%d][%d] = %d\n", i, j, i, j, f[i][j]);
				// }
			}
		}
		for (int i = 1; i <= n; ++i) Ans[i] = min(Ans[i], Ans[i - 1]);
		for (int i = 1; i <= n; ++i) cout << Ans[i] << " \n"[i == n];
	}
	return 0;
}