//ID: LRL52  Date: 2022.8.3
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
#define int long long
int n, K;

int gx(int k, int i){
    return (k / i) ? k / (k / i) : inf;
}

int Search(int a, int d, int l, int r){
    while(l <= r){
        int mid = (l + r) >> 1;
        int val = a - d * mid;
        if(val >= K) l = mid + 1;
        else r = mid - 1;
    }
    return r;
}

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	int n; rd(n), rd(K);
    int ans = 0;
    for(int a = 1; a <= n; ++a){
        for(int l = 1, r; l <= n; l = r + 1){
            r = min(n, gx(a, l));
            int idx = Search(a, a / l, l, r);
            //printf("l = %lld r = %lld idx = %d\n", l, r, idx);
            if(idx >= l && idx <= r) ans += idx - l + 1;
        }
    }
    printf("%lld\n", ans);
	return 0;
}