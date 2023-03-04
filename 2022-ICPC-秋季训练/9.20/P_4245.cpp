//ID: LRL52  Date: 2022.9.3
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

struct Poly{
    int MOD, G, Gi;
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
    LL Inv(LL x){return ksm(x, MOD - 2);}

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
}Poly1, Poly2, Poly3;
int n, m, P;
LL a[N], b[N], Ans1[N], Ans2[N], Ans3[N];

//注意不要溢出了
LL CRT(int i){
    static const int MOD1 = Poly1.MOD, MOD2 = Poly2.MOD, MOD3 = Poly3.MOD;
    static LL MOD12 = 1LL * MOD1 * MOD2;
    static const int invmod1 = Poly2.Inv(Poly1.MOD), invmod12 = Poly3.Inv(1LL * Poly1.MOD * Poly2.MOD % Poly3.MOD);
    LL k1 = (Ans2[i] - Ans1[i] + MOD2) % MOD2 * invmod1 % MOD2;
    LL x4 = (Ans1[i] + k1 * MOD1) % MOD12;
    LL k4 = (Ans3[i] - x4 % MOD3 + MOD3) % MOD3 * invmod12 % MOD3;
    LL ret = (x4 % P + MOD12 % P * k4 % P) % P;
    return ret;
} 

signed main() {
#ifdef LRL52
	freopen("P4245_1.in", "r", stdin);
    freopen("P4245.out", "w", stdout);
#endif
    Poly1.MOD = 998244353, Poly2.MOD = 1004535809, Poly3.MOD = 469762049;
    Poly1.G = Poly2.G = Poly3.G = 3;
    Poly1.Gi = 332748118, Poly2.Gi = 334845270, Poly3.Gi = 156587350;
    rd(n), rd(m), rd(P);
    rep(i, 0, n) rd(a[i]), Ans1[i] = Ans2[i] = Ans3[i] = a[i];
    rep(i, 0, m) rd(b[i]);
    int lim = max(n, m) + 1;
    Poly1.PolyMul(Ans1, b, lim);
    Poly2.PolyMul(Ans2, b, lim);
    Poly3.PolyMul(Ans3, b, lim);
    rep(i, 0, n + m) printf("%lld ", CRT(i));
    return 0;
}