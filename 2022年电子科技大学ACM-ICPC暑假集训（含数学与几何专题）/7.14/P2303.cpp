//ID: LRL52  Date: 2022.7.14
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
#define int long long

signed main() {
#ifdef LRL52
	freopen("P2303.in", "r", stdin);
#endif
	int n; rd(n);
    int ans = n;
    for(int i = 2; i * i <= n; ++i){
        if(n % i == 0){
            int a = 0, p = i;
            while(n % i == 0) ++a, n /= i;
            ans = ans / p * (p + a * (p - 1));
        }
    }
    if(n != 1) ans = ans / n * (n + n - 1);
    printf("%lld\n", ans);
	return 0;
}