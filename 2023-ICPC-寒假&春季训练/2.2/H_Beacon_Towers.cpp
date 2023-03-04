//ID: LRL52  Date: 2023.1.15
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
const int N = 500000 + 55, M = 2e3 + 55, inf = 0x3f3f3f3f, MOD = 1e9 + 7;
using LL = long long;
int n;
int H[N], Pos[N];
LL sum[N], f[N];

signed main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n;
    for(int i = 1; i <= n; ++i) cin >> H[i], Pos[H[i]] = i;;
    f[0] = sum[0] = 1;
    int maxh = 0;
    for(int i = 1; i <= n; ++i) {
        maxh = max(maxh, H[i]);
        int p = Pos[maxh];
        f[i] = sum[p - 1];
        sum[i] = (sum[i - 1] + f[i]) % MOD;
    }
    cout << f[n] << endl;
	return 0;
}