//ID: LRL52  Date: 2022.7.27
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
typedef long long ll;

ll rnd(ll x){return (ll)RAND_MAX * rand() * rand() % x + 1;}

signed main() {
#ifdef LRL52
	freopen("H.in", "w", stdout);
#endif
    srand(time(NULL));
	int n = 10, m = 20;
    printf("%d %d\n", n, m);
    rep(i, 1, m){
        int u, v, type;
        while(1){
            u = rnd(n), v = rnd(n), type = rnd(2);
            if(u != v) break;
        }
        printf("%d %d %d\n", u, v, type);
    }   
	return 0;
}