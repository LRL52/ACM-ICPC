//ID: LRL52  Date: 2023.2.4
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
using LL = long long;
using pii = pair<int, int>;
const int N = 5e3 + 55, M = 2e3 + 55, inf = 0x3f3f3f3f;
int n, m;
int a[N], c[N], sel[N];
LL f[N][N], cost[N][N];

signed main() {
#ifdef LRL52
	freopen("D.in", "r", stdin);
#endif
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n >> m;
    rep(i, 1, n) cin >> a[i];
    rep(i, 1, n) cin >> c[i];
    rep(i, 1, m) {
        int x; cin >> x;
        sel[x] = 1;
    }
    // memset(cost, 0x3f, sizeof(cost));
    rep(i, 1, n) {
        cost[i][0] = a[i] + c[i];
        for(int j = 1; j < i; ++j) {
            cost[i][j] = min(cost[i][j - 1], (LL)a[i] + c[i - j]);
        }
    }
    memset(f, 0x3f, sizeof(f));
    f[0][0] = 0;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j <= i; ++j) {
            f[i + 1][j + 1] = min(f[i + 1][j + 1], f[i][j] + cost[i + 1][j]);
            if(!sel[i + 1])
                f[i + 1][j] = min(f[i + 1][j], f[i][j]);
        }
    }
    LL ans = 1e18;
    for(int j = 0; j <= n; ++j) ans = min(ans, f[n][j]);
    cout << ans << '\n';
	return 0;
}