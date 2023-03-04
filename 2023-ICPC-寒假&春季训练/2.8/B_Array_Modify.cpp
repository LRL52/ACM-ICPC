//ID: LRL52  Date: 2023.2.8
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
using LL = long long;
using pii = pair<int, int>; char Buf[1 << 21], *_A = Buf, *_B = Buf, cc;
inline char gc() { return _A == _B && (_B = (_A = Buf) + fread(Buf, 1, 1 << 21, stdin), _A == _B) ? EOF : *_A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
const int N = 400000 + 55, MOD = 998244353, G = 3, Gi = 332748118;
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
}
int n, L, m;
LL a[N], b[N], c[N];
using Poly::ksm;
using Poly::Inv;

signed main() {
#ifdef LRL52
	freopen("B.in", "r", stdin);
#endif
	ios::sync_with_stdio(false); cin.tie(nullptr);
	int Task, tcnt = 0; //cin >> Task;
    rd(Task);
	while(Task--) {
        // cin >> n >> L >> m;
        rd(n), rd(L), rd(m);
        for(int i = 0; i < n; ++i) rd(a[i]);
        reverse(a, a + n);
        // b[0] = 1;
        // for(int i = 1; i < L; ++i) 
        //     b[i] = (m + i - 1) * Poly::Inv(i) % MOD * b[i - 1] % MOD
        for(int i = 0; i < L; ++i) b[i] = 1;
        for(int i = L; i < n; ++i) b[i] = 0;
        if(m <= MOD) Poly::PolyPow2(b, m, c, n);
        else Poly::PolyPow2(b, m, c, n, m % (MOD - 1));
        Poly::PolyMul(a, c, n);
        reverse(a, a + n);
        printf("Case %d: ", ++tcnt);
        for(int i = 0; i < n; ++i) printf("%lld ", a[i]);
        puts("");
	}
	return 0;
}