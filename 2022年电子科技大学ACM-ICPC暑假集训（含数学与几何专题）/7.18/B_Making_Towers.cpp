//ID: LRL52  Date: 2022.7.18
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 3e5 + 55, M = 2055, inf = 0x3f3f3f3f; char Buf[1 << 21], *_A = Buf, *_B = Buf, cc;
inline char gc() { return _A == _B && (_B = (_A = Buf) + fread(Buf, 1, 1 << 21, stdin), _A == _B) ? EOF : *_A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
int n, a[N], Ans[N], maxc[N][2];

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	int Task; rd(Task);
	while(Task--){
		rd(n);
        rep(i, 1, n) rd(a[i]);
        rep(i, 1, n) maxc[i][0] = maxc[i][1] = Ans[i] = 0;
        rep(i, 1, n){
            int c = a[i], res = 0;
            if(i & 1) res = maxc[c][0] + 1;
            else res = maxc[c][1] + 1;
            Ans[c] = max(Ans[c], res);
            maxc[c][i&1] = max(maxc[c][i&1], res);
        }
        rep(i, 1, n) printf("%d ", Ans[i]);
        puts("");
	}
	return 0;
}