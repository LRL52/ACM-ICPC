//ID: LRL52  Date: 2022.8.13
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 3e5 + 55, M = 2055, inf = 0x3f3f3f3f; char Buf[1 << 21], *_A = Buf, *_B = Buf, cc;
inline char gc() { return _A == _B && (_B = (_A = Buf) + fread(Buf, 1, 1 << 21, stdin), _A == _B) ? EOF : *_A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
typedef long long LL;
namespace Poly{
//多项式数组暂时使用long long, 实测板子速度还不戳, 暂时不需要进一步卡常
//数组记得至少开3倍
//以下多项式所有操作请确保传入的两个数组地址不是同一个！
    typedef long long LL;
    const int MOD = 998244353, G = 3, Gi = 332748118;
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
}
int n, m;
LL a[N], b[N], rev_a[N];

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	rd(n), rd(m); LL sum_a2 = 0, sum_a = 0, sum_b2 = 0, sum_b = 0;
    rep(i, 1, n) rd(a[i]), sum_a += a[i], sum_a2 += a[i] * a[i];
    rep(i, 1, n) rd(b[i]), sum_b += b[i], sum_b2 += b[i] * b[i];
    LL b_ = sum_a - sum_b;
    LL c1, c2;
    //printf("b_ = %d, n = %d\n", b_, n);
    if(b_ >= 0) c1 = -(b_ / n), c2 = -((b_ + n - 1) / n);
    else c1 = -(b_ / n), c2 = -((b_ - n + 1) / n);
    //printf("c1, c2 = %d, %d\n", c1, c2);
    LL ans = min(n * c1 * c1 + 2LL * c1 * b_, n * c2 * c2 + 2LL * c2 * b_);
    ans += sum_a2 + sum_b2;
    //printf("ans = %d\n", ans);
    rep(i, 1, n) rev_a[n - i] = a[i], b[i + n] = b[i];
    //for(int i = 0; i < n; ++i) printf("%d ", rev_a[i]); puts("");
    //for(int i = 1; i <= 2 * n; ++i) printf("%d ", b[i]); puts("");
    Poly::PolyMul(rev_a, b, 2 * n);
    LL res = -1e18;
    for(int k = 0; k < n; ++k) res = max(res, rev_a[n + k]);
    //printf("rev_a[n + 1] = %d\n", rev_a[n + 1]);
    ans -= 2LL * res;
    printf("%lld\n", ans); 
	return 0;
}