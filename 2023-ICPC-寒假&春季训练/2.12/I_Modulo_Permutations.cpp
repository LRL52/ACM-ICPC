//ID: LRL52  Date: 2023.2.12
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
using i64 = long long;
using pii = pair<int, int>;
const int N = 1e6 + 55, inf = 0x3f3f3f3f, MOD = 1e9 + 7;
int a[N];
typedef long long LL;
// LL f[N][2];
LL F[N];

// LL ksm(LL a, LL k){
//     LL ret = 1;
//     while(k){
//         if(k & 1) ret = ret * a % MOD;
//         a = a * a % MOD;
//         k >>= 1;
//     }
//     return ret;
// }

signed main() {
// #ifdef LRL52
// 	freopen("D.in", "r", stdin);
// #endif
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    // // LL n = 1000000;
	// // cout << n * n % MOD * (n - 2) % MOD << endl;
    // int n = 8, ans = 0;
    // rep(i, 1, n) a[i] = i;
    // do {
    //     int ok = 1;
    //     rep(i, 1, n - 1) if((a[i] % a[i + 1]) > 2) ok = 0;
    //     if((a[n] % a[1]) > 2) ok = 0;
    //     ans += ok;
    // }while(next_permutation(a + 1, a + n + 1));
    // cout << ans << endl;
    // int n; cin >> n;
    // f[0][0] = f[0][1] = 1;
    // for(int i = 1; i <= n; ++i) {
    //     // (f[i][2] += f[i - 1][0]) %= MOD;
    //     (f[i][1] += f[i - 1][0]) %= MOD;
    //     (f[i][0] += f[i - 1][1]) %= MOD;
    //     // (f[i][3] += f[i - 1][1]) %= MOD;
    // }
    // cout << (LL)n * (f[n - 2][0] + f[n - 2][1] + f[n - 3][0] + f[n - 3][1]) % MOD << endl;
    int n; cin >> n;
    if(n == 1) {
        puts("1");
        return 0;
    }
    if(n == 2) {
        puts("2");
        return 0;
    }
    F[2] = 1;
    for(int i = 2; i <= n; ++i) {
        // for(int k = 2; k < i; ++k) {
        //     if((k <= 2) || ((i + 1) % k) <= 2)
        //         (F[i] += F[k]) %= MOD;
        // }
        for(int j = i; j <= n; j += i) {
            if(j - 1 > i && i > 2) (F[j - 1] += F[i]) %= MOD;
            if(j > i) (F[j] += F[i]) %= MOD;
            (F[j + 1] += F[i]) %= MOD;
        }
    }
    LL ans = 0;
    for(int j = 0; j < n; ++j) (ans += F[j]) %= MOD;
    cout << ans * 2LL % MOD * n % MOD << endl;
	return 0;
}