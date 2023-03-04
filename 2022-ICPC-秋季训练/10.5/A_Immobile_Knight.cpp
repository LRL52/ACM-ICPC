//ID: LRL52  Date: 2022.9.30
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
const int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
const int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	int Task; rd(Task);
	while (Task--) {
		int n, m;
        rd(n), rd(m);
        int ok = 0;
        rep(i, 1, n) {
            rep(j, 1, m) {
                int cnt = 0;
                for(int k = 0; k < 8; ++k) {
                    int x = i + dx[k], y = j + dy[k];
                    if (x < 1 || x > n || y < 1 || y > m) ++cnt;
                }
                if (cnt == 8) {
                    printf("%d %d\n", i, j);
                    ok = 1; break;
                }
            }
            if (ok) break;
        }
        if (!ok) printf("%d %d\n", 1, 1);
	}
	return 0;
}