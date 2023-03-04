//ID: LRL52  Date: 2022.11.6 ~ 11.7
//__int_128_t 做NTT
//SPOJ终于卡常数卡过了，真不懂为什么本机230ms交上去1.1s
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
using LL = long long;
const LL MOD = 75161927681LL, Gi = 25053975894LL;
const int G = 3, Dx = 20000, MAXN = Dx * 6;
namespace Poly{
    int tot, bit, rev[N];

    LL ksm(LL a, LL k){
        LL ret = 1;
        while(k){
            if(k & 1) ret = (__int128_t)ret * a % MOD;
            a = (__int128_t)a * a % MOD;
            k >>= 1;
        }
        return ret;
    }
    LL Inv(LL x){return ksm(x, MOD - 2);}

    long long modulos_mult(long long a,long long b,long long prime) {
		return (a*(b%100000)%prime+a*(b/100000%100000)%prime*100000%prime+a*(b/10000000000ll)%prime*100000%prime*100000%prime)%prime;
	}

    void NTT(LL *a, int sign){
        for(int i = 0; i < tot; ++i)
            if(i < rev[i])
                swap(a[i], a[rev[i]]);
        for(int L = 1; L < tot; L <<= 1){
            LL w1 = ksm(sign == 1 ? G : Gi, (MOD - 1) / (L << 1));
            for(int i = 0; i < tot; i += L << 1){
                LL wk = 1;
                for(int j = 0; j < L; ++j, wk = (__int128_t)wk * w1 % MOD){
                    LL x = a[i + j], y = (__int128_t)wk * a[i + j + L] % MOD;
                    a[i + j] = (x + y) % MOD, a[i + j + L] = (x - y + MOD) % MOD;
                }
            }
        }
        if(sign == 1) return;
        LL inv = ksm(tot, MOD - 2);
        for(int i = 0; i < tot; ++i) a[i] = (__int128_t)a[i] * inv % MOD;
    }

    void PolyMul(LL *a, LL *b, int n, int m){ // A(x) * B(x) mod x^n, 答案写入a, b保持不变
        static LL c[N]; tot = 1, bit = 0;
        while(tot < (n + m)) ++bit, tot <<= 1;
        for(int i = 0; i < tot; ++i) rev[i] = (rev[i >> 1] >> 1) | (i & 1) << (bit - 1);
        for(int i = 0; i < m; ++i) c[i] = b[i];
        for(int i = n; i < tot; ++i) a[i] = 0;
        for(int i = m; i < tot; ++i) c[i] = 0;
        NTT(a, 1); NTT(c, 1);
        for(int i = 0; i < tot; ++i) a[i] = (__int128_t)a[i] * c[i] % MOD;
        NTT(a, -1);
    }
}
using Poly::ksm;
using Poly::Inv;
int n;
long long A[N], a[N], b[N], f[N], g[N], h[N];

template<typename T>
void print(T x) {
    if(x < 0) putchar('-'), x = -x;
    if(x > 9) print(x / 10);
    putchar('0' + x % 10);
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    rd(n);
    //cin >> n;
    rep(i, 1, n) {
        rd(A[i]);
        //cin >> A[i];
        f[A[i] + Dx]++, a[A[i] + Dx]++;
        g[(A[i] + Dx) * 2]++;
        h[(A[i] + Dx) * 3]++;
    }
    Poly::PolyMul(f, a, 40001, 40001);
    Poly::PolyMul(f, a, 80001, 40001);
    Poly::PolyMul(g, a, 80001, 40001);
    for(int i = 0; i <= MAXN; ++i) {
        long long ans = f[i] - 3LL * g[i] + 2LL * h[i];
        ans /= 6;
        if(ans > 0) {
            //printf("%d : %lld\n", i - Dx * 3, ans);
            print(i - Dx * 3);
            putchar(' ');
            putchar(':');
            putchar(' ');
            print(ans);
            putchar('\n');
        }
    }
	return 0;
}