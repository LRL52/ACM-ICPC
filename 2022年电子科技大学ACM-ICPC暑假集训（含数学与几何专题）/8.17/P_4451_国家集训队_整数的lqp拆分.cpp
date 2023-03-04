//ID: LRL52  Date: 2022.8.16
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int MOD = 1e9 + 7, sqrt2 = 59713600, Phi = 1e9 + 6;
const int N = 1e3 + 55, M = 2055, inf = 0x3f3f3f3f; char Buf[1 << 21], *_A = Buf, *_B = Buf, cc;
inline char gc() { return _A == _B && (_B = (_A = Buf) + fread(Buf, 1, 1 << 21, stdin), _A == _B) ? EOF : *_A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); x %= Phi; cc = gc(); } x *= f;
}
typedef long long LL;
LL ksm(LL a, LL k){
	LL ret = 1;
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
	LL n; rd(n);
	LL ans = (ksm(sqrt2 + 1, n) - ksm(MOD - sqrt2 + 1, n) + MOD) % MOD;
	ans = ans * ksm(2, MOD - 2) % MOD * ksm(sqrt2, MOD -2) % MOD;
	printf("%lld\n", ans);
	return 0;
}