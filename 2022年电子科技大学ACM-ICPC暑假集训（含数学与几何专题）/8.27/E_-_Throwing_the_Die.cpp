//ID: LRL52  Date: 2022.8.27
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
#define double long double
double f[N];

signed main() {
#ifdef LRL52
	freopen("E.in", "r", stdin);
#endif
	int n; rd(n);
    f[1] = 3.5;
    double ans = 3.5;
    rep(i, 2, n){
        f[i] = 0.0;
        rep(j, 1, 6) f[i] += max((double)j, f[i - 1]);
        f[i] /= 6.0;
        ans = max(ans, f[i]);
    }
    printf("%.10Lf\n", ans);
	return 0;
}