//ID: LRL52  Date: 2022.8.2
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 3e5 + 55, inf = 0x3f3f3f3f; char Buf[1 << 21], *_A = Buf, *_B = Buf, cc;
inline char gc() { return _A == _B && (_B = (_A = Buf) + fread(Buf, 1, 1 << 21, stdin), _A == _B) ? EOF : *_A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
namespace Cipolla{
//这是一个二次剩余的板子, 仅仅在多项式开根(加强版)的时候有用, 其余情况可删去
#define int long long
    int i_i, P, N;
    struct comp{
        int x, y;
        comp(int _x = 0, int _y = 0){
            x = _x, y = _y;
        }
    };

    inline comp operator*(const comp&t1, const comp&t2){
        comp ret;
        ret.x = (1LL*t1.x*t2.x%P + 1LL*t1.y*t2.y%P*i_i%P)%P;
        ret.y = (1LL*t1.x*t2.y%P + 1LL*t2.x*t1.y%P)%P;
        return ret;
    }

    comp ksm(comp a, int b){
        comp ret = comp(1, 0);
        while(b){
            if(b & 1) ret = ret * a;
            a = a * a;
            b >>= 1;
        }
        return ret;
    }

    int qp(int a, int b){
        int ret = 1;
        while(b){
            if(b & 1) ret = 1LL * ret * a % P;
            a = 1LL * a * a % P;
            b >>= 1;
        }
        return ret;
    }

    int is_residue(int x){
        return qp(x, (P-1)>>1) == 1;
    }
    int Solve(){
        if(N == 0){puts("0");return 0;}
        if(!is_residue(N)){puts("Hola!");return 0;}
        int a = 1LL * rand() * rand() % P;
        i_i = (1LL * a * a % P - N + P) % P; 
        while(is_residue(i_i)){
            a = 1LL * rand() * rand() % P;
            i_i = (1LL * a * a % P - N + P) % P; 
        }
        comp ans = ksm(comp(a, 1), (P+1)>>1);
        int ans1 = ans.x, ans2 = -ans1 + P;
        if(ans1 > ans2) std::swap(ans1, ans2);
        //printf("%lld %lld\n", ans1, ans2);
        return ans1;
    }
#undef int
}

const long long MOD = 998244353;
namespace Poly{
//多项式数组暂时使用long long, 实测板子速度还不戳, 暂时不需要进一步卡常
//数组记得至少开3倍
//以下多项式所有操作请确保传入的两个数组地址不是同一个！
    typedef long long LL;
    const LL G = 3, Gi = 332748118;
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

    void PolyInv(LL *F, LL *G, int n){ // F^(-1)(x) mod x^n, 答案写入G, F保持
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
            

    void PolyDer(LL *a, LL *b, int n){ // 对a逐项求导, 答案写入b, a保持不变
        for(int i = 1; i < n; ++i) b[i - 1] = a[i] * i % MOD;
        b[n - 1] = 0;
    }

    void PolyInter(LL *a, LL *b, int n){// 对a逐项积分, 积分后常数b[0] = 0, 答案写入b, a保持不变
        for(int i = n - 1; i >= 0; --i) b[i + 1] = a[i] * ksm(i + 1, MOD - 2) % MOD;
        b[0] = 0;
    }

    void PolyLn(LL *a, LL *b, int n){ // ln(A(x)) mod x^n, 需要求a[0] = 1, 答案写入b, a保持不变
        static LL c[N], d[N];
        PolyDer(a, c, n);
        PolyInv(a, d, n);
        PolyMul(c, d, n);
        PolyInter(c, b, n);
    }

    void PolyExp(LL *a, LL *b, int n){ // exp(A(x)) mod x^n, 需要求a[0] = 0, 答案写入b, a保持不变
        static LL c[N]; b[0] = 1;
        for(int L = 2; ; L <<= 1){
            PolyLn(b, c, L);
            for(int i = 0; i < L; ++i) c[i] = ((i == 0) + MOD - c[i] + a[i]) % MOD;
            PolyMul(b, c, L);
            if(L >= n) break;
        }
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

    void PolySqrt2(LL *a, LL *b, int n){ // sqrt(A(x)) mod x^n, 需要求a[0]是模MOD下的二次剩余, 答案写入b, a保持不变
        static int inv2 = ksm(2, MOD - 2);
        static LL c[N]; 
        Cipolla::N = a[0], Cipolla::P = MOD;
        b[0] = Cipolla::Solve();
        for(int L = 2; ; L <<= 1){
            PolyInv(b, c, L);
            PolyMul(c, a, L);
            for(int i = 0; i < L; ++i) b[i] = (c[i] + b[i]) * inv2 % MOD;
            if(L >= n) break;
        }
    }

    void PolyPow(LL *a, LL k, LL *b, int n){ // 请使用PolyPow2, A^(k)(x) mod x^n, 需满足a[0] = 1, 答案写入b, a保持不变
        static LL c[N];
        PolyLn(a, c, n);
        for(int i = 0; i < n; ++i) c[i] = c[i] * k % MOD;
        PolyExp(c, b, n);
    }

    void PolyPow2(LL *a, LL k, LL *b, int n, LL k1 = -1){ // A^(k)(x) mod x^n, 答案写入b, a保持不变
    //可以不需要a[0] = 1, 但k > MOD时, 需传入k1 = k mod phi(MOD), k为快速幂的指数
        static LL c[N]; int t = -1;
        for(int i = 0; i < n; ++i) b[i] = 0;
        for(int i = 0; i < n; ++i){if(a[i] != 0){t = i; break;}}
        if(t == -1){ if(k == 0) b[0] = ksm(a[0], (k1 == -1 ? k : k1)); return;}
        for(int i = 0; i < n; ++i) a[i] = (i + t >= n) ? 0 : a[i + t];
        int inv_at = ksm(a[0], MOD - 2), at_k = ksm(a[0], (k1 == -1 ? k : k1));
        for(int i = 0; i < n; ++i) a[i] = a[i] * inv_at % MOD;
        PolyPow(a, k, c, n);
        for(int i = 0; i + k * t < n; ++i) b[i + k * t] = c[i] * at_k % MOD;
    }

    void PolySin(LL *a, LL *b, int n){ // sin(A(x)) mod x^n, 答案写入b, a保持不变
        static LL c[N], d[N], c1[N], d1[N];
        static LL _i = ksm(G, (MOD - 1) >> 2), inv_i = ksm(_i, MOD - 2), inv2 = ksm(2, MOD - 2); //_i是虚数单位, 在mod P下即g^((p-1)/4))
        for(int i = 0; i < n; ++i) c[i] = a[i] * _i % MOD, d[i] = a[i] * (MOD - _i) % MOD;
        PolyExp(c, c1, n);
        PolyExp(d, d1, n);
        for(int i = 0; i < n; ++i) b[i] = (c1[i] - d1[i] + MOD) * inv2 % MOD * inv_i % MOD;
    }

    void PolyCos(LL *a, LL *b, int n){ // cos(A(x)) mod x^n, 答案写入b, a保持不变
        static LL c[N], d[N], c1[N], d1[N];
        static LL _i = ksm(G, (MOD - 1) >> 2), inv2 = ksm(2, MOD - 2); //_i是虚数单位, 在mod P下即g^((p-1)/4))
        for(int i = 0; i < n; ++i) c[i] = a[i] * _i % MOD, d[i] = a[i] * (MOD - _i) % MOD;
        PolyExp(c, c1, n);
        PolyExp(d, d1, n);
        for(int i = 0; i < n; ++i) b[i] = (c1[i] + d1[i]) * inv2 % MOD;
    }

    void PolyAsin(LL *a, LL *b, int n){ // arcsin(A(x)) mod x^n, 答案写入b, a保持不变
        static LL c[N], d[N];
        for(int i = 0; i < n; ++i) c[i] = d[i] = a[i];
        PolyMul(c, d, n);
        for(int i = 0; i < n; ++i) c[i] = ((i == 0) - c[i] + MOD) % MOD;
        PolySqrt(c, d, n);
        PolyInv(d, c, n);
        PolyDer(a, d, n);
        PolyMul(c, d, n);
        PolyInter(c, b, n);
    }

    void PolyAtan(LL *a, LL *b, int n){ // arctan(A(x)) mod x^n, 答案写入b, a保持不变
        static LL c[N], d[N];
        for(int i = 0; i < n; ++i) c[i] = d[i] = a[i];
        PolyMul(c, d, n);
        for(int i = 0; i < n; ++i) c[i] = ((i == 0) + c[i] + MOD) % MOD;
        PolyInv(c, d, n);
        PolyDer(a, c, n);
        PolyMul(c, d, n);
        PolyInter(c, b, n);
    }
}
long long a[N], b[N];

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
//调用示例, P5265 多项式反三角函数
	int n, type;
    n = 100;
    a[0] = 1, a[1] = MOD - 1, a[2] = MOD - 1;
    Poly::PolyInv(a, b, n);
    for(int i = 0; i < n; ++i) printf("%lld ", b[i]);
	return 0;
}