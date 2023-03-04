//ID: LRL52  Date: 2022.11.14
//比较不戳的期望 + 生成函数推式子题
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
using LL = long long;
const int N = 5e3 + 55, MOD = 1e9 + 7;
int n, K;
LL a[N], A[N];

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
	cin >> n >> K;
    A[0] = 1;
    rep(i, 1, n) {
        cin >> a[i];
        for(int j = i; j >= 1; --j)
            A[j] = (A[j] * a[i] % MOD - A[j - 1]) % MOD;
        A[0] = A[0] * a[i] % MOD;
    }
    LL ans = A[0], inv = 1, k = 1, inv_n = Inv(n);
    for(int i = 1; i <= min(K, n); ++i) {
        k = k * (K - i + 1) % MOD;
        inv = inv * inv_n % MOD;
        ans = (ans + A[i] * k % MOD * inv % MOD) % MOD;
    }
    LL t = 1;
    for(int i = 1; i <= n; ++i) t = t * a[i] % MOD;
    ans = ((t - ans) % MOD + MOD) % MOD;
    printf("%lld\n", ans);
	return 0;
} 
    