//ID: LRL52  Date: 2022.8.16
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 1e3 + 55, M = 2055, inf = 0x3f3f3f3f; char Buf[1 << 21], *_A = Buf, *_B = Buf, cc;
inline char gc() { return _A == _B && (_B = (_A = Buf) + fread(Buf, 1, 1 << 21, stdin), _A == _B) ? EOF : *_A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
typedef long long LL;
const int MOD = 998244353, G = 3, Gi = 332748118;
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
LL a[N][N], b[N][N], P[N], Success;
const LL c[] = {0, MOD-1, 1, MOD-2, 2};

int check(LL *a, int n){
    if(a[n] != 1) return 0;
    for(int i = 0; i <= n; ++i)
        if(a[i] != 0 && a[i] != 1 && a[i] != MOD - 1) return 0;
    return 1;
}

void dfs(int deg){
    //printf("deg = %d\n", deg);
    if(deg > 150){
        Success = 1;
        return;
        //puts("Success!");
        //exit(0);
    }
    for(int k = 0; k < 5; ++k){
        for(int i = 0; i < deg; ++i) a[deg][i] = b[deg][i] = a[deg - 1][i];
        a[deg][deg] = 0;
        P[0] = c[k], P[1] = 1;
        Poly::PolyMul(a[deg], P, deg + 1);
        for(int i = 0; i <= deg; ++i) a[deg][i] = (a[deg][i] + b[deg - 1][i]) % MOD;
        //for(int i = 0; i <= deg; ++i) printf("%lld ", a[deg][i]); puts("");
        //for(int i = 0; i < deg; ++i) printf("%lld ", b[deg][i]); puts("");
        if(check(a[deg], deg)) 
            dfs(deg + 1);
        if(Success) return;
    }
}

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
    a[0][0] = 1, b[0][0] = 0;
    dfs(1);
    //puts("Fail!");
    int n; rd(n);
    printf("%d\n", n);
    for(int i = 0; i <= n; ++i){
        int x = (a[n][i] == MOD - 1) ? -1 : a[n][i];
        printf("%d ", x);
    }
    puts("");
    printf("%d\n", n - 1);
    for(int i = 0; i < n; ++i){
        int x = (b[n][i] == MOD - 1) ? -1 : b[n][i];
        printf("%d ", x);
    }
    puts("");
	return 0;
}