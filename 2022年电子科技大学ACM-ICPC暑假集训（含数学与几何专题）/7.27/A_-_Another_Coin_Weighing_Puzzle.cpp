//ID: LRL52  Date: 2022.7.27
//思维题 + 莫比乌斯反演
//参见https://www.cnblogs.com/limil/p/15172239.html，写得不戳
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 1e6 + 55, M = 2055, inf = 0x3f3f3f3f; char Buf[1 << 21], *_A = Buf, *_B = Buf, cc;
inline char gc() { return _A == _B && (_B = (_A = Buf) + fread(Buf, 1, 1 << 21, stdin), _A == _B) ? EOF : *_A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
#define int long long
const int MOD = 998244353;
int m, K, Pcnt, prime[N], mu[N], st[N];

int ksm(int a, int k){
    int ret = 1;
    while(k){
        if(k & 1) ret = ret * a % MOD;
        a = a * a % MOD;
        k >>= 1;
    }
    return ret;
}

void init(int up){
    mu[1] = 1;
    rep(i, 2, up){
        if(!st[i]) prime[++Pcnt] = i, mu[i] = -1;
        for(int j = 1; prime[j] <= up / i; ++j){
            st[i * prime[j]] = 1;
            if(i % prime[j] == 0) break;
            mu[i * prime[j]] = -mu[i];
        }
    }
}

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
    rd(m), rd(K);
    init(K);
    int ans = 0;
    rep(i, 1, K){
        ans += mu[i] * (ksm(1 + 2LL * (K / i), m) - 1 + MOD) % MOD; //注意mu[i]可能为-1导致ans < 0
        ans %= MOD;
    }
    ans = (ans + 1) % MOD;
    printf("%lld\n", (ans % MOD + MOD) % MOD);
	return 0;
}