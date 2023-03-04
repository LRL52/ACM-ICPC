//ID: LRL52  Date: 2022.7.18
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
int a[N], b[N];

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
    int n, X, Y, m;
	rd(n), rd(X), rd(Y);
    rep(i, 1, n) rd(a[i]);
    rd(m);
    rep(i, 1, m) rd(b[i]);
    int ok = 1;
    int dx = (Y - X > 0) ? 1 : -1;
    for(int i = X + dx, p = 1; p <= m; i += dx, ++p){
        if(b[p] != a[i]){
            ok = 0;
            break;
        }
    }
    if(ok == 0){
        puts("Wrong");
        return 0;
    }
    int diff = 0;
    if(X - dx * m < 1 || X - dx * m > n) diff = 1;
    else {
        for(int i = X - dx, j = X + dx, p = 1; p <= m; i -= dx, j += dx, ++p){
            if(a[i] != a[j]){
                diff = 1;
                break;
            }
        }
    }
    if(diff) puts("Right");
    else puts("Unsure");
	return 0;
}