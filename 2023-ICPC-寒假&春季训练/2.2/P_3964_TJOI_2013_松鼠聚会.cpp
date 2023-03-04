//ID: LRL52  Date: 2023.2.2
//切比雪夫距离转曼哈顿距离
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
using LL = long long;
const int N = 1e5 + 55;
int n;
int X[N], Y[N], a[N], b[N], _a[N], _b[N];
LL suma[N], sumb[N];

signed main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n;
    rep(i, 1, n) cin >> X[i] >> Y[i];
    rep(i, 1, n) a[i] = _a[i] = X[i] + Y[i], b[i] = _b[i] = X[i] - Y[i];
    sort(a + 1, a + n + 1);
    sort(b + 1, b + n + 1);
    rep(i, 1, n) {
        suma[i] = suma[i - 1] + a[i];
        sumb[i] = sumb[i - 1] + b[i];
    }
    LL ans = 1e18;
    for(int i = 1; i <= n; ++i) {
        int p = lower_bound(a + 1, a + n + 1, _a[i]) - a; 
        LL res = (LL)a[p] * (p - 1) - suma[p - 1] 
                - (LL)a[p] * (n - p) + (suma[n] - suma[p]);
        p = lower_bound(b + 1, b + n + 1, _b[i]) - b;
        res +=   (LL)b[p] * (p - 1) - sumb[p - 1] 
                - (LL)b[p] * (n - p) + (sumb[n] - sumb[p]);
        ans = min(ans, res / 2);
    }
    cout << ans << endl;
	return 0;
}