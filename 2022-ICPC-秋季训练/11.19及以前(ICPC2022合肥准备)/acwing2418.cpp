//ID: LRL52  Date: 2022.11.4
#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 55, M = 2055, inf = 0x3f3f3f3f;
int n, MOD;
int C[N][N], g[N], f[N][N];

void Init() {
    for(int i = 0; i <= n; ++i)
        for(int j = 0; j <= i; ++j)
            if(!j) C[i][j] = 1;
            else C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
    
    g[1] = 1, g[3] = 3;
    for(int i = 4; i <= n; ++i) g[i] = 1LL * g[i - 1] * i % MOD;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n >> MOD;
    Init();

    f[0][0] = 1;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= i; ++j)
            for(int k = 1; k <= i - j + 1; ++k)
                f[i][j] = (f[i][j] + 1LL * f[i - k][j - 1] * C[i - 1][k - 1] % MOD * g[k] % MOD) % MOD;
    long long res = g[n - 1], p = 1;

    for(int k = 2; k <= n; ++k) {
        res += f[n][k] * p % MOD;
        res %= MOD;
        p = p * n % MOD;
    }

    printf("%lld\n", res);
	return 0;
}
    