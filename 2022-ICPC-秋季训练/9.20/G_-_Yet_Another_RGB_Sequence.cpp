//ID: LRL52  Date: 2022.9.15
//二项式反演直接秒掉，比用容斥简单多了
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 3e6 + 55, M = 2055, inf = 0x3f3f3f3f; char Buf[1 << 21], *_A = Buf, *_B = Buf, cc;
inline char gc() { return _A == _B && (_B = (_A = Buf) + fread(Buf, 1, 1 << 21, stdin), _A == _B) ? EOF : *_A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
int R, G, B, K;
const int MOD = 998244353;
int inv[N], fact[N], factinv[N];
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
	rd(R), rd(G), rd(B), rd(K);
    int up = min(R, G);
    Prework(R + G + B);
    long long ans = 0;
    for(int i = K; i <= up; ++i){
        int res = 1LL * C(i, K) * fact[R + G + B - i] % MOD * factinv[i] % MOD * \
                  factinv[R - i] % MOD * factinv[G - i] % MOD * factinv[B] % MOD;
        if((i - K) & 1) ans = (ans - res + MOD) % MOD;
        else ans = (ans + res) % MOD;
    }
    printf("%lld\n", ans);
	return 0;
}