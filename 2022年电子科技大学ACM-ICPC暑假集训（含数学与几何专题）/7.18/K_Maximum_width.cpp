//ID: LRL52  Date: 2022.7.18
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 2e5 + 55, M = 2055, inf = 0x3f3f3f3f; char Buf[1 << 21], *_A = Buf, *_B = Buf, cc;
inline char gc() { return _A == _B && (_B = (_A = Buf) + fread(Buf, 1, 1 << 21, stdin), _A == _B) ? EOF : *_A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
int n, m, f[N], g[N];
char s[N], t[N];

int search(int k){
    int l = 1, r = n;
    while(l <= r){
        int mid = (l + r) >> 1;
        if(g[mid] >= k) l = mid + 1;
        else r = mid - 1;
    }
    return r;
}

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> s + 1 >> t + 1;
    rep(i, 1, n){
        int p = f[i - 1];
        if(p < m && s[i] == t[p + 1]) f[i] = p + 1;
        else f[i] = p;
    }
    g[n + 1] = 0;
    for(int i = n; i >= 1; --i){
        int p = g[i + 1];
        if(p < m && s[i] == t[m - (p + 1) + 1]) g[i] = p + 1;
        else g[i] = p;
    }
    int ans = 1;
    for(int i = 1; i < m; ++i){
        int l = lower_bound(f + 1, f + n + 1, i) - f;
        int r = search(m - i);
        ans = max(ans, r - l);
    }
    printf("%d\n", ans);
	return 0;
}