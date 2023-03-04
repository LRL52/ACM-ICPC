//ID: LRL52  Date: 2022.7.15
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 2e5 + 55, M = 2055, inf = 0x3f3f3f3f; char Buf[1 << 21], *_A = Buf, *_B = Buf, cc;
inline char gc() { return _A == _B && (_B = (_A = Buf) + fread(Buf, 1, 1 << 21, stdin), _A == _B) ? EOF : *_A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
int n, a[N], b[N];

signed main() {
#ifdef LRL52
	freopen("read.in", "r", stdin);
#endif
	int Task; rd(Task);
	while(Task--){
		rd(n);
        rep(i, 1, n) rd(a[i]);
        a[n + 1] = 0; int ok = 0;
        for(int i = n; i >= 1; --i){
            int idx = upper_bound(a + 1, a + i + 1, 0) - a;
            if(idx >= i){
                printf("%d\n", a[i]);
                break;
            }
            int st = max(idx - 1, 1);
            //printf("%d %d\n", st, i);
            //rep(j, 1, 10) printf("%d ", a[j]);
            //puts("");
            for(int j = st; j < i; ++j){
                b[j] = a[j + 1] - a[j];
            }
            sort(b + st, b + i);
            for(int j = st; j < i; ++j){
                a[j] = b[j];
            }
            a[i] = 0;
        }

	}
	return 0;
}