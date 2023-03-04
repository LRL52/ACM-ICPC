//ID: LRL52  Date: 2022.7.26
//NTT，快速数论变换入坑
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 3e6 + 55, M = 2055, inf = 0x3f3f3f3f; char Buf[1 << 21], *_A = Buf, *_B = Buf, cc;
inline char gc() { return _A == _B && (_B = (_A = Buf) + fread(Buf, 1, 1 << 21, stdin), _A == _B) ? EOF : *_A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
const int MOD = 998244353, G = 3, Gi = 332748118;
typedef long long LL;
int n, m, tot = 1, rev[N];
LL a[N], b[N];

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
}

int main() {
#ifdef LRL52
	freopen("NTT.in", "r", stdin);
#endif
	rd(n), rd(m); int bit = 0;
    for(int i = 0; i <= n; ++i) rd(a[i]);
    for(int i = 0; i <= m; ++i) rd(b[i]);
    while(tot < n + m + 1) ++bit, tot <<= 1;
    for(int i = 0; i < tot; ++i)
        rev[i] = (rev[i >> 1] >> 1) | (i & 1) << (bit - 1);
    NTT(a, 1); NTT(b, 1);
    for(int i = 0; i < tot; ++i) a[i] = a[i] * b[i] % MOD;
    NTT(a, -1);
    int inv = ksm(tot, MOD - 2);
    for(int i = 0; i <= n + m; ++i)
        printf("%lld ", a[i] * inv % MOD);
	return 0;
}