//ID: LRL52  Date: 2022.9.14
//二项式反演 + NTT
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 4e5 + 55, M = 1e7 + 55, inf = 0x3f3f3f3f; char Buf[1 << 21], *_A = Buf, *_B = Buf, cc;
inline char gc() { return _A == _B && (_B = (_A = Buf) + fread(Buf, 1, 1 << 21, stdin), _A == _B) ? EOF : *_A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
using LL = long long;
const int MOD = 1004535809, G = 3, Gi = 334845270;
namespace Poly{
//多项式数组暂时使用long long, 实测板子速度还不戳, 暂时不需要进一步卡常
//数组记得至少开3倍
//以下多项式所有操作请确保传入的两个数组地址不是同一个！
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
using Poly::ksm;
using Poly::Inv;
long long a[N], b[N], c[N], f[N];
int n, m, S;

int inv[M], fact[M], factinv[M];
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
	rd(n), rd(m), rd(S);
    int up = min(m, n / S);
    Prework(max(n, max(m, S)));
    for(int k = 0; k <= up; ++k){
        f[k] = 1LL * C(m, k) * fact[n] % MOD * ksm(factinv[S], k) % MOD * \
               factinv[n - S * k] % MOD * ksm(m - k, n - S * k) % MOD;
        a[k] = 1LL * fact[k] * f[k] % MOD;
        b[k] = 1LL * ((k&1) ? (MOD-1) : 1) * factinv[k] % MOD; 
    }
    for(int k = 0; k <= up; ++k) c[k] = a[up - k];
    Poly::PolyMul(c, b, up + 1);
    int w; LL ans = 0;
    rep(k, 0, m){
        rd(w);
        if(k > up) continue;
        LL res = c[up - k] * factinv[k] % MOD;
        ans += res * w % MOD;
        ans %= MOD;
    }
    printf("%lld\n", ans);
	return 0;
}