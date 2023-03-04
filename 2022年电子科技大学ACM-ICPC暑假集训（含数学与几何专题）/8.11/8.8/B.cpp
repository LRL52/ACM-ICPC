//ID: LRL52  Date: 2022.8.8
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

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
    freopen("B.out", "w", stdout);
#endif
	int n = 100000, m = 65;
    int v = 100000 - 1, cnt = 0;
    //while(v > 1) v >>= 1, ++cnt;
    //printf("cnt = %d\n", cnt);
    //return 0;
    printf("%d\n", n);
    rep(i, 1, n - m) printf("%d ", 100000);
    int first = 1;
    rep(i, 1, m){
        if(first) printf("%d", 100000 - i), first = 0;
        else printf(" %d", 100000 - i);
    }
	return 0;
}