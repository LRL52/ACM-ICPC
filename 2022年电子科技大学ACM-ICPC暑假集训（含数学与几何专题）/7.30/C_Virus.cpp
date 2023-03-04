//ID: LRL52  Date: 2022.7.29
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
#define int long long
int n, a[N], b[N];

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	int Task; rd(Task);
	while(Task--){
		int n, m;
        rd(n), rd(m);
        rep(i, 1, m) rd(a[i]);
        sort(a + 1, a + m + 1);
        int p = 0;
        rep(i, 2, m){
            if(a[i] - a[i - 1] - 1 > 0){
                b[++p] = a[i] - a[i - 1] - 1;
            }
        }
        if(a[1] - 1 + n - a[m] > 0)
            b[++p] = a[1] - 1 + n - a[m];
        sort(b + 1, b + p + 1);
        int res = 0, d = 0;
        for(int i = p; i >= 1; --i){
            if(b[i] - d * 2 <= 0) break;
            b[i] -= d * 2;
            if(b[i] <= 2) res += 1, d += 1;
            else res += b[i] - 1, d += 2;
        }
        printf("%lld\n", n - res);
	}
	return 0;
}