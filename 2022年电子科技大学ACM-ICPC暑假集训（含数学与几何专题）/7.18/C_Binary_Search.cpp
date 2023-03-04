//ID: LRL52  Date: 2022.7.18
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 1e3 + 55, M = 2055, inf = 0x3f3f3f3f; char Buf[1 << 21], *_A = Buf, *_B = Buf, cc;
inline char gc() { return _A == _B && (_B = (_A = Buf) + fread(Buf, 1, 1 << 21, stdin), _A == _B) ? EOF : *_A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
const int MOD = 1e9 + 7;
typedef long long LL;
int fact[N], factinv[N], inv[N];

void init(int n){
    inv[1] = factinv[1] = fact[1] = fact[0] = factinv[0] = 1;
    rep(i, 2, n) fact[i] = 1LL * fact[i - 1] * i % MOD;
    rep(i, 2, n) inv[i] = 1LL * (MOD - MOD / i) * inv[MOD % i] % MOD;
    rep(i, 2, n) factinv[i] = 1LL * factinv[i - 1] * inv[i] % MOD;
}

LL C(int n, int m){
    if(m > n) return 0;
    return 1LL * fact[n] * factinv[m] % MOD * factinv[n - m] % MOD;
}

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
    int n, X, Pos, cnt1 = 0, cnt2 = 0;
	rd(n), rd(X), rd(Pos);
    int l = 0, r = n;
    while(l < r){
        int mid = (l + r) / 2;
        if(mid == Pos) l = mid + 1;
        else if(mid < Pos) ++cnt1, l = mid + 1;
        else ++cnt2, r = mid;
    }
    init(n);
    LL ans = C(X - 1, cnt1) * fact[cnt1] % MOD;
    ans = ans * C(n - X, cnt2) % MOD * fact[cnt2] % MOD;
    ans = ans * fact[n - 1 - cnt1 - cnt2] % MOD;
    printf("%lld\n", ans);
	return 0;
}