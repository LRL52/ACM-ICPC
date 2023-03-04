//ID: LRL52  Date: 2022.7.26
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 1e6 + 55, M = 2055, inf = 0x3f3f3f3f; char Buf[1 << 21], *_A = Buf, *_B = Buf, cc;
inline char gc() { return _A == _B && (_B = (_A = Buf) + fread(Buf, 1, 1 << 21, stdin), _A == _B) ? EOF : *_A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
#define int long long
int pow10[N];

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	int n; rd(n);
    int now = 0, ans = 0;
    pow10[0] = 1;
    rep(i, 1, n) pow10[i] = pow10[i - 1] * 10LL % n;
    int lim = 0, x = 1;
    while(x < n) x = x * 10, lim++;
    rep(i, 1, n){
        for(int k = 0; ;k++){
            int val = (i - 1) * pow10[k] % n;
            int d = (i - val + n) % n;
            if(k >= lim || pow10[k] - 1 >= d){
                ans += k;
                break;
            }
        }
    } 
    printf("%lld\n", ans);       
	return 0;
}