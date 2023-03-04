//ID: LRL52  Date: 2023.2.12
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
using i64 = long long;
using pii = pair<int, int>;
const int N = 1e3 + 55, M = 2e3 + 55, inf = 0x3f3f3f3f, MOD = 1e9 + 7;
int n;
int a[N];
i64 f[N][N];

i64 F(int l, int r) {
    if(l >= r) return 1;
    auto &ret = f[l][r];
    if(ret != -1) return ret;
    ret = 0;
    int pos = l;
    rep(i, l, r)
        if(a[i] < a[pos])
            pos = i;
    for(int i = pos; i >= l; i--) {
        for(int j = pos; j <= r; ++j) {
            ret += F(l, i - 1) * F(j + 1, r) % MOD;
            ret %= MOD;
        }
    }
    return ret;
}

signed main() {
#ifdef LRL52
	freopen("D.in", "r", stdin);
#endif
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n;
    rep(i, 1, n) cin >> a[i];
    memset(f, -1, sizeof(f));
    cout << F(1, n) << endl;
	return 0;
}