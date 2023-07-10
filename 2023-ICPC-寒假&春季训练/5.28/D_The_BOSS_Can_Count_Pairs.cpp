/*** 
 * @Author: LRL52
 * @Date: 2023-05-29 11:59:51
 * @LastEditTime: 2023-05-29 12:09:48
 */
//枚举 ai * aj 中较小的那个数的值，然后遍历数组计算，复杂度O(n * sqrt(n))
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
        vector<pii> c(n + 1);
        for (int i = 1; i <= n; ++i) cin >> c[i].first;
        for (int i = 1; i <= n; ++i) cin >> c[i].second;
        sort(c.begin() + 1, c.begin() + n + 1);
        i64 ans = 0;
        for (int x = 1; x * x <= 2 * n; ++x) {
            vector<int> Cnt(n + 1);
            for (int i = 1; i <= n; ++i) {
                auto y = 1LL * x * c[i].first - c[i].second;
                if (y >= 1 && y <= n)
                    ans += Cnt[y];
                if (c[i].first == x)
                    ++Cnt[c[i].second];
            }
        }
        cout << ans << '\n';
	}
	return 0;
}