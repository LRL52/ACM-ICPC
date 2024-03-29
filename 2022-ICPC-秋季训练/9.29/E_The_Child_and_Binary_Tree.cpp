//ID: LRL52  Date: 2022.9.21
//不戳的生成函数题
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 4e5 + 55, inf = 0x3f3f3f3f; char Buf[1 << 21], *_A = Buf, *_B = Buf, cc;
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

    void PolyInv(LL *F, LL *G, int n){ // F^(-1)(x) mod x^n, 答案写入G, F保持不变
        static LL c[N];
        if(n == 1) return G[0] = ksm(F[0], MOD - 2), void();
        PolyInv(F, G, (n + 1) >> 1);
        tot = 1, bit = 0;
        while(tot < (n << 1)) tot <<= 1, ++bit;
        for(int i = 0; i < tot; ++i) rev[i] = (rev[i >> 1] >> 1) | (i & 1) << (bit - 1);
        for(int i = 0; i < n; ++i) c[i] = F[i];
        for(int i = (n + 1) >> 1; i < n; ++i) G[i] = 0;
        for(int i = n; i < tot; ++i) c[i] = G[i] = 0;
        NTT(c, 1); NTT(G, 1);
        for(int i = 0; i < tot; ++i)
            G[i] = (2LL - G[i] * c[i] % MOD + MOD) * G[i] % MOD;
        NTT(G, -1);
    }
           
    void PolySqrt(LL *a, LL *b, int n){ // sqrt(A(x)) mod x^n, 需要求a[0] = 1, 答案写入b, a保持不变
        static int inv2 = ksm(2, MOD - 2);
        static LL c[N]; b[0] = 1;
        for(int L = 2; ; L <<= 1){
            PolyInv(b, c, L);
            PolyMul(c, a, L);
            for(int i = 0; i < L; ++i) b[i] = (c[i] + b[i]) * inv2 % MOD;
            if(L >= n) break;
        }
    }
}
int n, m;
LL f[N], g[N];

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
    rd(n), rd(m); int x;
    rep(i, 1, n) rd(x), g[x] = 1;
    int MAXN = 100000;
    rep(i, 1, MAXN) g[i] = (MOD - 4) * g[i] % MOD;
    g[0] = 1;
    Poly::PolySqrt(g, f, MAXN + 1);
    f[0]++;
    Poly::PolyInv(f, g, MAXN + 1);
    for(int i = 0; i <= MAXN; ++i) f[i] = 2LL * g[i] % MOD;
    rep(i, 1, m) printf("%lld\n", f[i]);
	return 0;
}