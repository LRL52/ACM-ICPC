/*** 
 * @Author: LRL52
 * @Date: 2023-07-01 20:15:09
 * @LastEditTime: 2023-07-01 20:23:46
 */
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using pii = pair<int, int>;
const int N = 1e3 + 55, inf = 0x3f3f3f3f, MOD = 1e9 + 7;
char s[N];
bitset<N> f[N];

signed main() {
#ifdef LRL52
	freopen("G.in", "r", stdin);
#endif
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;
    cin >> (s + 1);
    for (int i = 1; i <= n * n; ++i) {
        f[0][n] = s[i] == '1';
        int ans = 0;
        for (int j = n; j >= 1; --j) {
            f[j] = f[j] << 1;
            f[j][n + 1] = 0;
            if (f[j - 1][n] == 1) f[j][1] = 1;
            ans += f[j].any() == true;
        }
        cout << ans << " \n"[i == n * n];
    }
	return 0;
}