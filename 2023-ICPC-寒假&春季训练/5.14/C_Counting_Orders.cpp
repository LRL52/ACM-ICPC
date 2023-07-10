/*** 
 * @Author: LRL52
 * @Date: 2023-05-14 22:49:50
 * @LastEditTime: 2023-05-14 22:53:28
 */
#include <algorithm>
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
using i64 = long long;
using pii = pair<int, int>;
const int N = 2e5 + 55, inf = 0x3f3f3f3f, MOD = 1e9 + 7;
int n, a[N], b[N];

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int Task; cin >> Task;
	while(Task--) { 
		cin >> n;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        for (int i = 1; i <= n; ++i) cin >> b[i];
        sort(a + 1, a + n + 1);
        sort(b + 1, b + n + 1);
        i64 ans = 1;
        for (int i = 1; i <= n; ++i) {
            int p = lower_bound(b + 1, b + n + 1, a[i]) - b - 1;
            int t = p - (i - 1); 
            ans = 1LL * ans * (t > 0 ? t : 0) % MOD;
        }
        cout << ans << '\n';
	}
	return 0;
}