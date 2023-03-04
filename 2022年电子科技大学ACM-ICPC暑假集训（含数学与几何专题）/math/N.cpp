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

signed main() {
#ifdef LRL52
    freopen("N.in", "r", stdin);
#endif
    int n, Task; rd(Task);
    while(Task--){
        rd(n); int x;
        int cnt1 = 0;
        rep(i, 1, n){
            rd(x);
            cnt1 += x == 1;
        }
        if(n - cnt1 > 0) cnt1 & 1 ? puts("Lose") : puts("Win");
        else cnt1 & 1 ? puts("Win") : puts("Lose");
    }
    return 0;
}