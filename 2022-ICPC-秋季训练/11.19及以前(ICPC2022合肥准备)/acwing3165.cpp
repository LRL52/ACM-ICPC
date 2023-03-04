//ID: LRL52  Date: 2022.11.1
#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 55, MOD = 1e9 + 7;
int f[N][N];

signed main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	int n, m; cin >> n >> m;
    f[0][0] = 1;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            f[i][j] = (f[i - 1][j - 1] + (i - 1LL) * f[i - 1][j]) % MOD;
    printf("%d\n", f[n][m]);
	return 0;
}