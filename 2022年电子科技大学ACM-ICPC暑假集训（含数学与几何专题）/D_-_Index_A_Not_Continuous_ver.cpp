//ID: LRL52  Date: 2022.9.3
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 2e3 + 55, M = 2055, inf = 0x3f3f3f3f; char Buf[1 << 21], *_A = Buf, *_B = Buf, cc;
inline char gc() { return _A == _B && (_B = (_A = Buf) + fread(Buf, 1, 1 << 21, stdin), _A == _B) ? EOF : *_A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
#define int long long
int n, m;
int a[N], f[N][N];

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	rd(n), rd(m);
    rep(i, 1, n) rd(a[i]);
    memset(f, -0x3f, sizeof(f));
    f[0][0] = 0;
    rep(i, 1, n){
        f[i][0] = 0;
        rep(j, 1, m){
            f[i][j] = max(f[i - 1][j], f[i - 1][j - 1] + j * a[i]);
        }
    }
    int ans = -1e18;
    rep(i, 1, n) ans = max(ans, f[i][m]);
    printf("%lld\n", ans);
	return 0;
}