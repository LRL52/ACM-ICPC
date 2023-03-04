//ID: LRL52  Date: 2022.9.20
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
constexpr int N = 5e6 + 55, M = 2055, inf = 0x3f3f3f3f; char Buf[1 << 21], *_A = Buf, *_B = Buf, cc;
inline char gc() { return _A == _B && (_B = (_A = Buf) + fread(Buf, 1, 1 << 21, stdin), _A == _B) ? EOF : *_A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
using LL = long long;
constexpr int MOD = 998244353;
int inv[N], fact[N], factinv[N], pow2[N], g[N];
void Prework(int n){
    fact[0] = fact[1] = inv[1] = factinv[0] = factinv[1] = 1;
    rep(i, 2, n) fact[i] = 1LL * fact[i - 1] * i % MOD;
    rep(i, 2, n) inv[i] = 1LL * (MOD - MOD/i) * inv[MOD % i] % MOD;
    rep(i, 2, n) factinv[i] = 1LL * factinv[i - 1] * inv[i] % MOD;
}

int C(int n, int m){
    if(m > n || n < 0 || m < 0) return 0;
    return 1LL * fact[n] * factinv[n - m] % MOD * factinv[m] % MOD;
}

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
    constexpr int MAXN = 5e6;
	Prework(MAXN);
    pow2[0] = 1;
    rep(i, 1, MAXN) pow2[i] = 2LL * pow2[i - 1] % MOD;
    g[0] = 1, g[1] = 0;
    rep(i, 2, MAXN)
        g[i] = 4LL * i * (i - 1) % MOD * (g[i - 1] + 2LL * (i - 1) * g[i - 2] % MOD) % MOD;
    int Task; rd(Task);
    while (Task--) {
        int n, K;
        rd(n), rd(K);
        LL ans = 1LL * C(n, K) * fact[n] % MOD * factinv[n - K] % MOD * pow2[K] % MOD * g[n - K] % MOD;
        printf("%lld\n", ans);
    }
	return 0;
}