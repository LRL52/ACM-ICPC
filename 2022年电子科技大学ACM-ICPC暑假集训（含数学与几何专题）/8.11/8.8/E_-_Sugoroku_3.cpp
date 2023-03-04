//ID: LRL52  Date: 2022.8.2
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 2e5 + 55, M = 2055, inf = 0x3f3f3f3f; char Buf[1 << 21], *_A = Buf, *_B = Buf, cc;
inline char gc() { return _A == _B && (_B = (_A = Buf) + fread(Buf, 1, 1 << 21, stdin), _A == _B) ? EOF : *_A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
#define int long long
const int MOD = 998244353;
int n, f[N], a[N], suf[N];
int ksm(int a, int k){
    int ret = 1;
    while(k){
        if(k & 1) ret = ret * a % MOD;
        a = a * a % MOD;
        k >>= 1;
    }
    return ret;
}

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	rd(n);
    rep(i, 1, n - 1) rd(a[i]);
    f[n] = suf[n] = 0;
    for(int i = n - 1; i >= 1; --i){
        int res = suf[i + 1] - suf[i + a[i] + 1] + a[i] + 1;
        res = (res % MOD + MOD) % MOD;
        f[i] = res * ksm(a[i], MOD - 2) % MOD;
        f[i] %= MOD;
        suf[i] = (suf[i + 1] + f[i]) % MOD;
        //printf("%lld\n", f[i]);
    }
    printf("%lld\n", f[1]);
	return 0;
}