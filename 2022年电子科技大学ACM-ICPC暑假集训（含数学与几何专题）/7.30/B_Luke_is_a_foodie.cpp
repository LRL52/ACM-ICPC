//ID: LRL52  Date: 2022.7.29
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
int n, a[N], X;

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	int Task; rd(Task);
	while(Task--){
		rd(n), rd(X);
        rep(i, 1, n) rd(a[i]);
        int ans = 0;
        for(int i = 1, j; i <= n; i = j + 1){
            ++ans;
            j = i;
            int l = a[i] - X, r = a[i] + X;
            while(j < n){
                int l1 = a[j + 1] - X, r1 = a[j + 1] + X;
                l1 = max(l, l1), r1 = min(r, r1);
                if(l1 <= r1){
                    l = l1, r = r1, ++j;
                    continue;
                } else 
                    break;
            }
        }
        printf("%d\n", ans - 1);
	}
	return 0;
}