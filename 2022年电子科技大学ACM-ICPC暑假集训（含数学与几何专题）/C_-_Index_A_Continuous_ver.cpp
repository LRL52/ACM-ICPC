//ID: LRL52  Date: 2022.9.3
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
int n, m;
int sum[N], a[N];

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	rd(n), rd(m);
    rep(i, 1, n) rd(a[i]), sum[i] = sum[i - 1] + a[i];
    int ans = 0, res = 0;
    rep(i, 1, m) res += i * a[i]; 
    ans = res;
    rep(i, m + 1, n){
        res -= sum[i - 1] - sum[i - 1 - m + 1 - 1];
        res += m * a[i];
        ans = max(ans, res);
    }
    printf("%lld\n", ans);
	return 0;
}