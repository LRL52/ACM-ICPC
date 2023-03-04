//ID: LRL52  Date: 2022.11.10
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
const int N = 2e3 + 55, MOD = 998244353;
int n, K;
int X[N], Y[N];

typedef long long LL;
LL ksm(LL a, LL k){
    LL ret = 1;
    while(k){
        if(k & 1) ret = ret * a % MOD;
        a = a * a % MOD;
        k >>= 1;
    }
    return ret;
}

LL Inv(LL x) { return ksm(x, MOD - 2); }

signed main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> K; LL ans = 0;
    for(int i = 1; i <= n; ++i) cin >> X[i] >> Y[i];
    for(int i = 1; i <= n; ++i) {
        LL s1 = 1, s2 = 1;
        for(int j = 1; j <= n; ++j)
            if(j != i) s1 = s1 * (K - X[j]) % MOD, s2 = s2 * (X[i] - X[j]) % MOD;
        (ans += Y[i] * s1 % MOD * Inv(s2) % MOD) %= MOD;
    }
    ans = (ans % MOD + MOD) % MOD; //X[i] - X[j]等过程可能产生负数
    printf("%lld\n", ans);
	return 0;
} 
    