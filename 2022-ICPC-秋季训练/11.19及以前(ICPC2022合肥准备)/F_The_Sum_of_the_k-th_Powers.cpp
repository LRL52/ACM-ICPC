//ID: LRL52  Date: 2022.11.10
//经典k次幂求和，拉格朗日插值，且 x 取值连续，可以 O(n) 求出任意一个点值
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
const int N = 1e6 + 55, MOD = 1e9 + 7;
typedef long long LL;
int n, K;
LL _pre[N], suf[N], _fact[N];
LL *pre = &_pre[1], *fact = &_fact[1];


LL ksm(LL a, LL k){
    if(a == 0 && k == 0) return 0; //0^0 = 0，题目 K = 0 时 f(n) = n，故 f(0) = 0
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
    cin >> n >> K; //注意n其实是要带入的值，m才是拉格朗日插值中的点值数量
    int m = K + 1;
    //取点值0 ~ K + 1, 即 K + 2 个点确定一个 K + 1 次多项式
    pre[-1] = fact[-1] = fact[0] = 1; //利用指针的技巧支持负数下标
    for(int i = 0; i <= m; ++i) {
        pre[i] = pre[i - 1] * (n - i) % MOD;
        if(i > 0) fact[i] = fact[i - 1] * i % MOD;
    }
    suf[m + 1] = 1;
    for(int i = m; i >= 0; --i)
        suf[i] = suf[i + 1] * (n - i) % MOD;
    LL ans = 0, y = 0;
    for(int i = 0; i <= m; ++i) {
        y = (y + ksm(i, K)) % MOD;
        LL res = y * pre[i - 1] % MOD * suf[i + 1] % MOD;
        res = res * Inv(fact[i] * fact[m - i] % MOD) % MOD;
        if(abs(m - i) & 1) res = res * (MOD - 1) % MOD;
        (ans += res) %= MOD;
    }
    ans = (ans % MOD + MOD) % MOD;
    printf("%lld\n", ans);
	return 0;
} 
    