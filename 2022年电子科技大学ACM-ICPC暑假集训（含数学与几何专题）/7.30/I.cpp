//ID: LRL52  Date: 2022.7.29
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 5e3 + 55, M = 2055, inf = 0x3f3f3f3f; char Buf[1 << 21], *_A = Buf, *_B = Buf, cc;
inline char gc() { return _A == _B && (_B = (_A = Buf) + fread(Buf, 1, 1 << 21, stdin), _A == _B) ? EOF : *_A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
int f[N];
const int D[] = {3, 5, 5, 3};

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
    f[1] = 0, f[2] = 1, f[0] = 0, f[3] = f[4] = f[6] = 1;
    /*rep(i, 7, 5000){
        //if(f[i - 2] == 0 || f[i - 3] == 0) f[i] = 1;
        //else f[i] = 0;
        for(int j = 0; j <= i - 2; ++j){
            if(f[j] == 0 && f[i - 2 - j] == 0) f[i] = 1;
        }
    }*/
    int t = 6, p = 0;
    while(t <= 5000){
        int L = D[p]; p = (p + 1) % 4;
        rep(j, 1, L) f[t + j - 1] = 1;
        t += L + 1;
    }
    //rep(i, 1, 100) printf("f[%d] = %d\n", i, f[i]);
	int Task; rd(Task);
	while(Task--){
		int n;
        rd(n);
        f[n] ? puts("First") : puts("Second");
	}
	return 0;
}