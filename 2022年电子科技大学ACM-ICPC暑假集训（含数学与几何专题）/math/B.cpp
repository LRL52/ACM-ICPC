//ID: LRL52  Date: 2022.7.17
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
typedef long long LL;
const LL INF = 0x3F3F3F3F3F3F3F3F;

void print(__int128_t x){
    if(x < 0) putchar('-'), x = -x;
    if(x > 9) print(x / 10);
    putchar('0' + x % 10);
}

LL gx(LL n, LL x){return n / x ? n / (n / x) : INF;}
__int128_t S2(LL n){return (__int128_t)n * (n + 1) * (2 * n + 1) / 6;}

signed main() {
	ios::sync_with_stdio(false);
    cin.tie(0);
    int Task; cin >> Task;
    while(Task--){
        LL n; cin >> n;
        __int128_t ans = (__int128_t)n * (n + 1) / 2 * n;
        __int128_t b = 0;
        for(LL l = 1, r; l <= n; l = r + 1){
            r = min(n, gx(n, l));
            b += (__int128_t)(l + r) * (r - l + 1) / 2 * (n / l);
        }
        b = b * (n + 1);
        for(LL l = 1, r; l <= n; l = r + 1){
            r = min(n, gx(n, l));
            b -= (__int128_t)(S2(r) - S2(l - 1)) * (1 + (n / l)) * (n / l) / 2;
        }
        ans = ans - b;
        print(ans); puts("");
    }
	return 0;
}