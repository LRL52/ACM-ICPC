/*** 
 * @Author: LRL52
 * @Date: 2023-05-27 13:15:11
 * @LastEditTime: 2023-05-27 13:39:10
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
        vector<pii> a(n + 1);
        for (int i = 1; i <= n; ++i) {
            int x; cin >> x;
            a[i] = {x, i};
        }
        sort(a.begin() + 1, a.begin() + n + 1);
        set<int> low{0, n + 1}, high{0, n + 1};
        i64 ans = 0;
        for (int i = 1; i <= n; ++i) {
            high.insert(i);
            ans += 1LL * (i - 1) * (n - i + 1);
        }
        for (int i = 1; i <= n; ++i) {
            auto &[val, idx] = a[i];
            high.erase(idx);
            auto y = *low.upper_bound(idx);
            auto k = *prev(low.upper_bound(idx));
            if (k == 0) {
                low.insert(idx);
                continue;
            }
            auto x = *prev(high.lower_bound(k));
            ans -= 1LL * (k - x) * (y - idx);
            low.insert(idx);
        }
        cout << ans << '\n';
	}
	return 0;
}