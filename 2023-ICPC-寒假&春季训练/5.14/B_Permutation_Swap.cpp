/*** 
 * @Author: LRL52
 * @Date: 2023-05-14 22:41:30
 * @LastEditTime: 2023-05-14 22:44:46
 */
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
using i64 = long long;
using pii = pair<int, int>;
const int N = 2e5 + 55, inf = 0x3f3f3f3f, MOD = 1e9 + 7;
int n;
int a[N], b[N];;

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int Task; cin >> Task;
	while(Task--) { 
		cin >> n;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        for (int i = 1; i <= n; ++i) {
            int d = abs(a[i] - i);
            b[i] = d;
        }
        int ans = gcd(b[1], b[2]);
        for (int i = 3; i <= n; ++i) ans = gcd(ans, b[i]);
        cout << ans << '\n';
	}
	return 0;
}