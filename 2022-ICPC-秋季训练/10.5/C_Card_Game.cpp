//ID: LRL52  Date: 2022.9.30
//好具有迷惑性，明明O(n)就可以出解的
//可以大概推出来每次每个人都出点数最大的牌是最优的
//f(n) = C(n-1, n/2) + C(n-4, n/2 - 1)[n >= 6] + f(n - 4)
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 1e3 + 55, M = 2055, inf = 0x3f3f3f3f; char Buf[1 << 21], *_A = Buf, *_B = Buf, cc;
inline char gc() { return _A == _B && (_B = (_A = Buf) + fread(Buf, 1, 1 << 21, stdin), _A == _B) ? EOF : *_A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
const int MOD = 998244353;
int n, inv[N], fact[N], factinv[N];
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
    Prework(100);
	int Task; rd(Task);
	while (Task--) {
		rd(n); int t = n;
        long long ans = 0;
		for(; n > 0; n -= 4) {
			ans = (ans + C(n - 1, n / 2)) % MOD;
			if(n >= 6) ans = (ans + C(n - 4, n / 2 - 1)) % MOD;
		}
		long long lose = (C(t, t / 2) - 1 - ans + MOD + MOD) % MOD;
		printf("%lld %lld %lld\n", ans, lose, 1LL);
	}
	return 0;
}