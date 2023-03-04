//ID: LRL52  Date: 2022.8.9
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
#define int long long
int MOD;
map<int, int> H;

signed main() {
#ifdef LRL52
	freopen("K.in", "r", stdin);
#endif
	rd(MOD);
    int UP = min(MOD, 2000LL);
    for(int i = 0; i < UP; ++i){
        for(int j = 0; j < UP; ++j){
            int x = (i * i % MOD + j * j % MOD) % MOD;
            if(H.find(x) == H.end()) H[x] = min(i, j);
            else H[x] = min(H[x], min(i, j));
        }
    }
    int ans = 0;
    for(int i = 0; i < MOD; ++i) ans = max(ans, H[i]);
    printf("%lld\n", ans);
	return 0;
}