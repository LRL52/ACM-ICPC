/*** 
 * @Author: LRL52
 * @Date: 2023-07-01 19:38:36
 * @LastEditTime: 2023-07-01 19:50:27
 */
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using pii = pair<int, int>;
const int N = 1e3 + 55, inf = 0x3f3f3f3f, MOD = 1e9 + 7;

// int F(int a, int b) {

// }

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int a, b, C, D;
    cin >> a >> b >> C >> D;
	auto g = [&](int x) {
		return (1LL * C * x % 10 + D) % 10;
	};
    // cout << F(a, b) << '\n';
	int n = 1 << (a - 1);
	int ans = b;
	for (int i = 1; i <= n; ++i) {
		ans = g(ans);
	}
	cout << ans << '\n';
	return 0;
}