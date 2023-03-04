//ID: LRL52  Date: 2023.2.28
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
using i64 = long long;
using pii = pair<int, int>;
const int N = 1e6 + 55, M = 2e3 + 55, inf = 0x3f3f3f3f, MOD = 998244353;
int lg[N];

typedef long long LL;
LL ksm(LL a, LL k){
    LL ret = 1;
    while(k){
        if(k & 1) ret = ret * a;
        a = a * a;
        k >>= 1;
    }
    return ret;
}

signed main() {
#ifdef LRL52
	freopen("D.in", "r", stdin);
#endif
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	lg[0] = -1;
    rep(i, 1, 1000000) lg[i] = lg[i >> 1] + 1;
    int Task; cin >> Task;
	while(Task--) {
		int l, r;
        cin >> l >> r;
        int k = lg[r / l];
        i64 ans = r / (1 << k) - l + 1;
        // cout << k + 1 << " " << r / (1 << k) - l + 1 << '\n';
        // for(int alpha = 2; ; alpha++) {
        //     auto d = ksm(alpha, k);
        //     auto t = r / d;
        //     if(t < l) break;
        //     ans = (ans + t - l + 1) % MOD;
        //     if(k == 0) break;
        // }
        // cout << k + 1 << " " << ans << '\n';
        if(k != 0) {
            auto t = r / ((1 << (k - 1)) * 3LL);
            if(t >= l) ans = (ans + (t - l + 1LL) * k % MOD) % MOD; 
        }
        cout << k + 1 << " " << ans << '\n';
	}
	return 0;
}