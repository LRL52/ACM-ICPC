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


signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	int a, b, c;
    rd(a), rd(b), rd(c);
    b += c;
    if(b >= a) puts("NO");
    else{
        puts("YES");
        if(a == 1 && b == 0) puts("0");
        else if(b == 0) puts("1");
        else printf("%d\n", min(2 * b + 1, a + b));
    }
	return 0;
}