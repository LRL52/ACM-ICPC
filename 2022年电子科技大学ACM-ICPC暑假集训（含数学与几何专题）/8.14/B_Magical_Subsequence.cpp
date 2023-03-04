//ID: LRL52  Date: 2022.8.13
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
int n, Pos[N], f[N], a[N];

int Solve(int K){
    f[0] = 0;
    rep(i, 0, 100) Pos[i] = 0;
    rep(i, 1, n){
        f[i] = f[i - 1];
        if(K - a[i] >= 1 && Pos[K - a[i]]){
            int t = Pos[K - a[i]];
            f[i] = max(f[i], f[t - 1] + 2);
        }
        Pos[a[i]] = i;
    }
    return f[n];
}

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	rd(n);
    rep(i, 1, n) rd(a[i]);
    int ans = 0;
    rep(i, 2, 200){
        int res = Solve(i);
        ans = max(ans, res);
    }
    printf("%d\n", ans);
	return 0;
}