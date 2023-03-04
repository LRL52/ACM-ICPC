//ID: LRL52  Date: 2022.8.17
//离线求逆元的科技，先求出A = (a1...at)^(-1), 维护出前缀积、后缀积
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 5e6 + 55, M = 2055, inf = 0x3f3f3f3f; char Buf[1 << 21], *_A = Buf, *_B = Buf, cc;
inline char gc() { return _A == _B && (_B = (_A = Buf) + fread(Buf, 1, 1 << 21, stdin), _A == _B) ? EOF : *_A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
typedef long long LL;
int n, MOD, K, a[N], Suf[N], Pre[N];

LL ksm(LL a, LL k){
    LL ret = 1;
    while(k){
        if(k & 1) ret = ret * a % MOD;
        a = a * a % MOD;
        k >>= 1;
    }
    return ret;
}

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	rd(n), rd(MOD), rd(K);
    int A = 1;
    Pre[0] = Suf[n + 1] = 1;
    rep(i, 1, n){
        rd(a[i]);
        A = (LL)A * a[i] % MOD;
        Pre[i] = (LL)Pre[i - 1] * a[i] % MOD;
    }
    for(int i = n; i >= 1; --i)
        Suf[i] = (LL)Suf[i + 1] * a[i] % MOD;
    A = ksm(A, MOD - 2);
    int ans = 0, t = K;
    rep(i, 1, n){
        LL inv_ai = (LL)Pre[i - 1] * Suf[i + 1] % MOD * A % MOD;
        ans = (ans + (LL)inv_ai * t % MOD) % MOD;
        t = (LL)t * K % MOD;
    }
    printf("%d\n", ans);
	return 0;
}