//ID: LRL52  Date: 2023.2.4
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
using LL = long long;
using pii = pair<int, int>;
const int N = 2e5 + 55, M = 2e3 + 55, MOD = 998244353;
int n;
char s[N];
LL f[N], sum[N][12];

signed main() {
#ifdef LRL52
	freopen("D.in", "r", stdin);
#endif
	ios::sync_with_stdio(false); cin.tie(nullptr);
	int n;
    cin >> n >> (s + 1);
    f[0] = 1; f[1] = s[1] - '0';
    for(int k = 1; k <= 9; ++k) {
        sum[0][k] = f[0] * k;
        sum[1][k] = sum[0][k] + f[1] * k;
    }
    for(int i = 2; i <= n; ++i) {
        int a_i = s[i] - '0';
        f[i] = (10LL * f[i - 1] % MOD + sum[i - 1][a_i]) % MOD;
        for(int k = 1; k <= 9; ++k)
            sum[i][k] = (sum[i - 1][k] + f[i] * k % MOD) % MOD;
    }
    cout << f[n] << '\n';
	return 0;
}
