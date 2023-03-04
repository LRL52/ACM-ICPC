//ID: LRL52  Date: 2022.7.26
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
long double c[N];

void init(){
    c[1] = 1.0L / 3.0L;
    c[2] = sqrt(2.0L) / 2.0L;
    c[3] = sqrt(2.0L) / 3.0L;
    c[4] = (3.0L + sqrt(5.0L)) / (3.0L * (1.0L + sqrt(5.0L)));
    c[5] = sqrt((25.0L + 11.0L * sqrt(5.0L)) / (25.0L + 5.0L * sqrt(5.0L)));
}

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
    init();
	int Task; rd(Task);
	while(Task--){
        int n, a, K;
		rd(n), rd(a), rd(K);
        long double ans = a; int n2 = 0;
        if(n == 4){
            rep(i, 1, K)
                ans = ans * c[1], n2 = 4;
        } else
        if(n == 6){
            rep(i, 1, K){
                if(i & 1) ans = ans * c[2], n2 = 8;
                else ans = ans * c[3], n2 = 6;
            }
        } else
        if(n == 8){
            rep(i, 1, K){
                if(i & 1) ans = ans * c[3], n2 = 6;
                else ans = ans * c[2], n2 = 8;
            }
        } else
        if(n == 20){
            rep(i, 1, K){
                if(i & 1) ans = ans * c[4], n2 = 12;
                else ans = ans * c[5], n2 = 20;
            }
        } else
        if(n == 12){
            rep(i, 1, K){
                if(i & 1) ans = ans * c[5], n2 = 20;
                else ans = ans * c[4], n2 = 12;
            }
        }
        n2 == 0 ? puts("impossible") : printf("possible %d %.20Lf\n", n2, ans);
	}
	return 0;
}