//ID: LRL52  Date: 2022.7.17
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 1e7 + 55, M = 2055, inf = 0x3f3f3f3f; char Buf[1 << 21], *_A = Buf, *_B = Buf, cc;
inline char gc() { return _A == _B && (_B = (_A = Buf) + fread(Buf, 1, 1 << 21, stdin), _A == _B) ? EOF : *_A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
typedef long long LL;
const int MOD = 20101009, inv2 = 10050505;
int mu[N], prime[N], vm[N], Pcnt;
LL sum[N];

void init(int n){
    mu[1] = 1;
    for(int i = 2; i <= n; ++i){
        if(!vm[i]) vm[i] = prime[++Pcnt] = i, mu[i] = -1;
        for(int j = 1; prime[j] <= n / i; ++j){
            int x = i * prime[j];
            if(i % prime[j]){
                vm[x] = prime[j];
                mu[x] = -mu[i];
            } else{
                vm[x] = vm[i] * prime[j];
                break;
            }
        }
    }
    //rep(i, 1, 10) printf("%d ", mu[i]); puts("");
    rep(i, 1, n) sum[i] = (sum[i - 1] + 1LL * mu[i] * i * i % MOD) % MOD; //mu[i] * i^2 前缀和需要预处理
}

inline LL gx(LL n, LL x){return n / x ? n / (n / x) : inf;}

LL f(int n, int m){
    LL ret = 0, up = min(n, m);
    for(LL l = 1, r; l <= up; l = r + 1){
        r = min(up, min(gx(n, l), gx(m, l)));
        //ret += (sum[r] - sum[l - 1] + MOD) * (S2(r) - S2(l - 1) + MOD) % MOD * 
        ret += (sum[r] - sum[l - 1] + MOD) * 
               (1 + n / l) % MOD * (n / l) % MOD * inv2 % MOD * 
               (1 + m / l) % MOD * (m / l) % MOD * inv2 % MOD;
        ret %= MOD;
    }
    return ret;
}


signed main() {
#ifdef LRL52
	freopen("P1824.in", "r", stdin);
#endif
    int n, m;
	rd(n), rd(m);
    init(max(n, m));
    LL ans = 0LL, up = min(n, m);
    for(LL l = 1, r; l <= up; l = r + 1){
        r = min(up, min(gx(n, l), gx(m, l)));
        ans += (l + r) * (r - l + 1) / 2 % MOD * f(n / l, m / l) % MOD;
        ans %= MOD;
    }
    printf("%lld\n", (ans % MOD + MOD) % MOD);
	return 0;
}