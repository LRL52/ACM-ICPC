//ID: LRL52  Date: 2022.9.15
//二项式反演 + 暴力卷积
//由于数据范围比较小，写得也很暴力，把4个EGF暴力乘起来即可
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 8e3 + 55, M = 2055, inf = 0x3f3f3f3f; char Buf[1 << 21], *_A = Buf, *_B = Buf, cc;
inline char gc() { return _A == _B && (_B = (_A = Buf) + fread(Buf, 1, 1 << 21, stdin), _A == _B) ? EOF : *_A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
using LL = long long;
const int MOD = 998244353, G = 3, Gi = 332748118;
namespace Poly{
    int tot, bit, rev[N];

    LL ksm(LL a, LL k){
        LL ret = 1;
        while(k){
            if(k & 1) ret = ret * a % MOD;
            a = a * a % MOD;
            k >>= 1;
        }
        return ret;
    }
    LL Inv(int x){return ksm(x, MOD - 2);}

    void NTT(LL *a, int sign){
        for(int i = 0; i < tot; ++i)
            if(i < rev[i])
                swap(a[i], a[rev[i]]);
        for(int L = 1; L < tot; L <<= 1){
            LL w1 = ksm(sign == 1 ? G : Gi, (MOD - 1) / (L << 1));
            for(int i = 0; i < tot; i += L << 1){
                int wk = 1;
                for(int j = 0; j < L; ++j, wk = wk * w1 % MOD){
                    int x = a[i + j], y = wk * a[i + j + L] % MOD;
                    a[i + j] = (x + y) % MOD, a[i + j + L] = (x - y + MOD) % MOD;
                }
            }
        }
        if(sign == 1) return;
        int inv = ksm(tot, MOD - 2);
        for(int i = 0; i < tot; ++i) a[i] = a[i] * inv % MOD;
    }

    void PolyMul(LL *a, LL *b, int n){ // A(x) * B(x) mod x^n, 答案写入a, b保持不变
        static LL c[N]; tot = 1, bit = 0;
        while(tot < (n << 1)) ++bit, tot <<= 1;
        for(int i = 0; i < tot; ++i) rev[i] = (rev[i >> 1] >> 1) | (i & 1) << (bit - 1);
        for(int i = 0; i < n; ++i) c[i] = b[i];
        for(int i = n; i < tot; ++i) c[i] = a[i] = 0;
        NTT(a, 1); NTT(c, 1);
        for(int i = 0; i < tot; ++i) a[i] = a[i] * c[i] % MOD;
        NTT(a, -1);
    }
}
LL f[N], a[N], b[N], c[N], d[N];
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

int S(int A, int B, int C, int D, int n){
    for(int i = 0; i <= A; ++i) a[i] = factinv[i];
    for(int i = 0; i <= B; ++i) b[i] = factinv[i];
    for(int i = 0; i <= C; ++i) c[i] = factinv[i];
    for(int i = 0; i <= D; ++i) d[i] = factinv[i];
    for(int i = A + 1; i <= n; ++i) a[i] = 0;
    for(int i = B + 1; i <= n; ++i) b[i] = 0;
    for(int i = C + 1; i <= n; ++i) c[i] = 0;
    for(int i = D + 1; i <= n; ++i) d[i] = 0;
    Poly::PolyMul(a, b, n + 1);
    Poly::PolyMul(a, c, n + 1);
    Poly::PolyMul(a, d, n + 1);
    return 1LL * a[n] * fact[n] % MOD;
} 

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
    int n, a, b, c, d;
	rd(n), rd(a), rd(b), rd(c), rd(d);
    int up = min(n/4, min(a, min(b, min(c, d))));
    Prework(a + b + c + d);
    for(int k = 0; k <= up; ++k)
        f[k] = 1LL * C(n - 3 * k, k) * S(a - k, b - k, c - k, d - k, n - 4 * k) % MOD;
    LL ans = 0;
    for(int i = 0; i <= up; ++i){
        if((i & 1) == 0) ans = (ans + f[i]) % MOD;
        else ans = (ans - f[i] + MOD) % MOD;
    }
    printf("%lld\n", ans);
	return 0;
}