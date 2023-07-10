/*** 
 * @Author: LRL52
 * @Date: 2023-06-09 17:51:54
 * @LastEditTime: 2023-06-09 17:52:54
 */
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using pii = pair<int, int>;
const int N = 1e3 + 55, inf = 0x3f3f3f3f, MOD = 1e9 + 7;

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	i64 ans = 0, sum = 0;
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) {
        int x; cin >> x;
        ans += sum * x;
        sum += x;
    }
    cout << ans << '\n';
	return 0;
}