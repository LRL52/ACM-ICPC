/*** 
 * @Author: LRL52
 * @Date: 2023-05-20 00:00:51
 * @LastEditTime: 2023-05-21 12:15:16
 */
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
using i64 = long long;
using pii = pair<int, int>;
const int N = 2e5 + 55, inf = 0x3f3f3f3f, MOD = 1e9 + 7;
int n, m;
int a[N];

int inv[N], fact[N], factinv[N];
void Prework(int n){
    fact[0] = fact[1] = inv[1] = inv[0] = factinv[0] = factinv[1] = 1;
    rep(i, 2, n) fact[i] = 1LL * fact[i - 1] * i % MOD;
    rep(i, 2, n) inv[i] = 1LL * (MOD - MOD/i) * inv[MOD % i] % MOD;
    rep(i, 2, n) factinv[i] = 1LL * factinv[i - 1] * inv[i] % MOD;
}

int C(int n, int m){
    if(m > n || n < 0 || m < 0) return 0;
    return 1LL * fact[n] * factinv[n - m] % MOD * factinv[m] % MOD;
}

signed main() {
#ifdef LRL52
	freopen("F.in", "r", stdin);
#endif
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    Prework(N - 55);
	int Task; cin >> Task;
	while(Task--) { 
		cin >> n >> m;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        sort(a + 1, a + n + 1);
        int p = 0; i64 ans = 0, mulval = 1;
        map<int, int> Cnt; int sz = 0;
        for (int i = 1; i <= n; ++i) {
            while (p < n && a[p + 1] - a[i] < m) {
                ++p;
                ++Cnt[a[p]];
                auto t = Cnt[a[p]];
                mulval = mulval * inv[t - 1] % MOD;
                mulval = mulval * t % MOD;
                if (t == 1) ++sz;
            }
            auto t = Cnt[a[i]]; --Cnt[a[i]];
            mulval = mulval * inv[t] % MOD;
            if (sz == m) {
                ans += mulval;
                ans %= MOD;
            }
            if (t - 1 > 0) mulval = mulval * (t - 1) % MOD;
            if (t == 1) --sz;
        }
        cout << ans << '\n';
	}
	return 0;
}