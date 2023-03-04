//ID: LRL52  Date: 2022.8.16
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 2e5 + 55, M = 2055, inf = 0x3f3f3f3f; char Buf[1 << 21], *_A = Buf, *_B = Buf, cc;
inline char gc() { return _A == _B && (_B = (_A = Buf) + fread(Buf, 1, 1 << 21, stdin), _A == _B) ? EOF : *_A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
int n, K;
int a[N], b[N];

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	int Task; rd(Task);
	while(Task--){
		rd(n), rd(K);
        int ok = 1;
        if(K & 1){
            int p = 0;
            for(int i = 1; i <= n; i += 2)
                a[++p] = i, b[p] = i + 1;
        } else {
            int t = 1, p = 0;
            for(int i = 2; i <= n; i += 2){
                if(i % 4 == 0){
                    a[++p] = t, b[p] = i;
                    t += 2;
                } else{
                    if((i + K) % 4 == 0){
                        a[++p] = i, b[p] = t;
                        t += 2;
                    } else {
                        ok = 0;
                        break;
                    }
                }
            }
        }
        if(ok){
            puts("YES");
            rep(i, 1, n / 2) printf("%d %d\n", a[i], b[i]);
        } else
            puts("NO");
	}
	return 0;
}