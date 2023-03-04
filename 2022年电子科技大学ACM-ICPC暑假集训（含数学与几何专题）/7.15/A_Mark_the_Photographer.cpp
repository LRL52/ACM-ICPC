//ID: LRL52  Date: 2022.7.15
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 1055, M = 2055, inf = 0x3f3f3f3f; char Buf[1 << 21], *_A = Buf, *_B = Buf, cc;
inline char gc() { return _A == _B && (_B = (_A = Buf) + fread(Buf, 1, 1 << 21, stdin), _A == _B) ? EOF : *_A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
int n, X, a[N];

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	int Task; rd(Task);
	while(Task--){
        rd(n), rd(X);
        rep(i, 1, 2 * n) rd(a[i]);
        sort(a + 1, a + 2 * n + 1);
        int ok = 1;
        rep(i, 1, n){
            if(a[i + n] - a[i] < X){
                ok = 0;
                break;
            }
        }
        ok ? puts("YES") : puts("NO");
	}
	return 0;
}