//ID: LRL52  Date: 2022.8.27
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 1e5 + 55, M = 2055, inf = 0x3f3f3f3f; char Buf[1 << 21], *_A = Buf, *_B = Buf, cc;
inline char gc() { return _A == _B && (_B = (_A = Buf) + fread(Buf, 1, 1 << 21, stdin), _A == _B) ? EOF : *_A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
#define int long long
int n, f[N][5], a[N][5];

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	rd(n); int t, x, y;
    rep(i, 1, n){
        rd(t), rd(x), rd(y);
        a[t][x] += y;
    }
    memset(f, -0x3f, sizeof(f));
    f[0][0] = 0;
    const int TMAX = 1e5;
    for(int t = 0; t <= TMAX; ++t){
        for(int x = 0; x <= 4; ++x){
            f[t][x] += a[t][x];
            f[t + 1][x] = max(f[t + 1][x], f[t][x]);
            if(x > 0) f[t + 1][x - 1] = max(f[t + 1][x - 1], f[t][x]);
            if(x < 4) f[t + 1][x + 1] = max(f[t + 1][x + 1], f[t][x]);
        }
    }
    int ans = 0;
    rep(x, 0, 4) ans = max(ans, f[TMAX][x]);
    printf("%lld\n", ans);
	return 0;
}