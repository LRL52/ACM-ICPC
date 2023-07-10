/*** 
 * @Author: LRL52
 * @Date: 2023-05-12 19:44:05
 * @LastEditTime: 2023-05-14 13:37:15
 */
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
using i64 = long long;
using pii = pair<int, int>;
const int N = 1e7 + 55, inf = 0x3f3f3f3f, MOD = 998244353;
int n, a[N], b[N][6];

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int x, y, m, K;
    cin >> n >> a[1] >> x >> y >> m >> K;
    for (int i = 2; i <= n; ++i) a[i] = (1LL * a[i - 1] * x % m + y) % m;
    // Prework(n);
    b[1][0] = b[1][1] = a[1];
    // for (int k = 0; k <= K; ++k) b[1][k] = 1LL * C(1, k) * a[1] % MOD;
    for (int i = 2; i <= n; ++i) {
        b[i][0] = (b[i - 1][0] + a[i]) % MOD;
        for (int k = 1; k <= K; ++k) {
            b[i][k] = (b[i - 1][k] + b[i - 1][k - 1]) % MOD;
            (b[i][k] += (k <= 1) ? a[i] : 0) %= MOD;
        }
    }
    i64 ans = 0;
    for (int i = 1; i <= n; ++i)
        ans ^= 1LL * i * b[i][K];
    cout << ans << "\n";
	return 0;
}