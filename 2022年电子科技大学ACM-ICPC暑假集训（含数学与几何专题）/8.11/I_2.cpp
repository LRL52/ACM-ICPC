//ID: LRL52  Date: 2022.8.10
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = (1e3 + 55) * 2, M = 2055, inf = 0x3f3f3f3f; char Buf[1 << 21], *_A = Buf, *_B = Buf, cc;
inline char gc() { return _A == _B && (_B = (_A = Buf) + fread(Buf, 1, 1 << 21, stdin), _A == _B) ? EOF : *_A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
struct Node{
    int x, y, type;
    inline bool operator<(const Node&t)const{
        return x < t.x;
    }
}a[N];

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	int Task; rd(Task);
	while(Task--){
		rd(H);
        rd(n);
        rep(i, 1, n) rd(a[i].x), rd(a[i].y), a[i].type = 0;
        rd(m);
        rep(i, 1, m) rd(a[i].x), rd(a[i].y), a[i].type = 1;
        sort(a + 1, a + n + m + 1);
        
	}
	return 0;
}