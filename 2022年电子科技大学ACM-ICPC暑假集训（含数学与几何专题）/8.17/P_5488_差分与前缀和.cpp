//ID: LRL52  Date: 2022.8.15
//k次前缀和就是乘以(1-x)^(-k), k次差分就是乘以(1-x)^k
//(1-x)^k和(1-x)^(-k)在x^n项以内的系数可以通过组合数递推出来
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int MOD = 1004535809, G = 3, Gi = 334845270;
const int N = 4e5 + 55, inf = 0x3f3f3f3f; char Buf[1 << 21], *_A = Buf, *_B = Buf, cc;
inline char gc() { return _A == _B && (_B = (_A = Buf) + fread(Buf, 1, 1 << 21, stdin), _A == _B) ? EOF : *_A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); x %= MOD; cc = gc(); } x *= f;
}
typedef long long LL;
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
}
int n, type;
LL K, a[N], b[N];

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	rd(n), rd(K), rd(type);
    rep(i, 1, n) rd(a[i]);
    b[0] = 1;
    rep(i, 1, n){
        if(type == 0) b[i] = (K + i - 1) * Poly::Inv(i) % MOD * b[i - 1] % MOD;
        else b[i] = (K - i + 1) * Poly::Inv(i) % MOD * b[i - 1] % MOD;
    }
    if(type == 1)
        for(int i = 1; i <= n; i += 2)
            b[i] = MOD - b[i];
    Poly::PolyMul(a, b, n + 1);
    rep(i, 1, n) printf("%lld ", a[i]);
	return 0;
}