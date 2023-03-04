//ID: LRL52  Date: 2022.7.18
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 2e5 + 55, M = 2055, inf = 0x3f3f3f3f; char Buf[1 << 21], *_A = Buf, *_B = Buf, cc;
inline char gc() { return _A == _B && (_B = (_A = Buf) + fread(Buf, 1, 1 << 21, stdin), _A == _B) ? EOF : *_A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
#define int long long
int n, a[N], pre[N], suf[N];

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	int Task; rd(Task);
	while(Task--){
		rd(n);
        rep(i, 1, n) rd(a[i]);
        int ans = 0x3F3F3F3F3F3F3F3F;
        if(n & 1){
            int res = 0;
            for(int i = 2; i <= n - 1; i += 2){
                int h = max(a[i - 1], a[i + 1]);
                if(a[i] <= h) res += h - a[i] + 1;
            }
            ans = res;
        } else{
            int res = 0; pre[0] = suf[n + 1] = 0;
            for(int i = 2; i <= n - 1; i += 2){
                pre[i] = pre[i - 2];
                int h = max(a[i - 1], a[i + 1]);
                if(a[i] <= h){
                    res += h - a[i] + 1;
                    pre[i] += h - a[i] + 1;
                }
            }
            ans = min(ans, res); res = 0;
            for(int i = n - 1; i >= 2; i -= 2){
                suf[i] = suf[i + 2];
                int h = max(a[i - 1], a[i + 1]);
                if(a[i] <= h){
                    res += h - a[i] + 1;
                    suf[i] += h - a[i] + 1;
                }
            }
            ans = min(ans, res);
            for(int i = 3; i + 2 <= n - 1; i += 2){
                ans = min(ans, pre[i - 1] + suf[i + 2]);
            }
        }
        printf("%lld\n", ans);
	}
	return 0;
}