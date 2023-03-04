//ID: LRL52  Date: 2022.7.21
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
int n, m, a[N], suf[N], pre[N];

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	rd(n), rd(m);
    rep(i, 1, n) rd(a[i]);
    rep(i, 2, n){
        pre[i] = pre[i - 1];
        if(a[i] < a[i - 1])
            pre[i] += a[i - 1] - a[i];
    }
    for(int i = n - 1; i >= 1; --i){
        suf[i] = suf[i + 1];
        if(a[i] < a[i + 1])
            suf[i] += a[i + 1] - a[i];
    }
    //rep(i, 1, n) printf("%lld ", pre[i]);
    int x, y;
    rep(i, 1, m){
        rd(x), rd(y);
        if(x < y) printf("%lld\n", pre[y] - pre[x]);
        else printf("%lld\n", suf[y] - suf[x]);
    } 
	return 0;
}