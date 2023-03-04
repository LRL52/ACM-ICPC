//ID: LRL52  Date: 2022.7.22
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
int n, K, a[N], Cnt[N];

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	rd(n), rd(K);
    rep(i, 1, n) rd(a[i]);
    int uqe = 0, l = 0, r = 0, len = inf;
    for(int i = 1, j = 0; i <= n; ++i){
        while(j < n && uqe < K){
            ++j;
            if(++Cnt[a[j]] == 1) ++uqe;
        }
        if(uqe == K && j - i + 1 < len){
            l = i, r = j, len = j - i + 1;
        }
        if(--Cnt[a[i]] == 0) --uqe;
    }
    if(len != inf) printf("%d %d\n", l, r);
    else puts("-1 -1");      
	return 0;
}