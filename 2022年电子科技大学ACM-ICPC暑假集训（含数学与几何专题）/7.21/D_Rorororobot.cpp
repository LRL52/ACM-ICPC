//ID: LRL52  Date: 2022.7.21
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
int n, m, a[N], lg[N], f[N][32];

int query(int l, int r){
    int k = lg[r - l + 1];
    return max(f[l][k], f[r - (1 << k) + 1][k]);
}

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	rd(n), rd(m); lg[0] = -1;
    rep(i, 1, m) rd(a[i]), f[i][0] = a[i], lg[i] = lg[i >> 1] + 1;
    int qs; rd(qs);
    for(int k = 1; k <= lg[m]; ++k){
        for(int i = 1; i + (1 << k) - 1 <= m; ++i){
            f[i][k] = max(f[i][k - 1], f[i + (1 << (k-1))][k - 1]);
        }
    }
    while(qs--){
        int sx, sy, ex, ey, k;
        rd(sx), rd(sy), rd(ex), rd(ey), rd(k);
        if(sy > ey) swap(sx, ex), swap(sy, ey);
        int dx = abs(ex - sx), dy = abs(sy - ey);
        if((dx % k) || (dy % k)){
            puts("NO");
            continue;
        }
        int ym = max(sx, ex);
        int y = ym + (n - ym) / k * k;
        int hmax = query(sy, ey);
        hmax < y ? puts("YES") : puts("NO");
    }
	return 0;
}