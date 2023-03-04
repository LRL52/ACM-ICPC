//ID: LRL52  Date: 2022.8.16
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 1e5 + 55, M = 2055, inf = 0x3f3f3f3f; char Buf[1 << 21], *_A = Buf, *_B = Buf, cc;
inline char gc() { return _A == _B && (_B = (_A = Buf) + fread(Buf, 1, 1 << 21, stdin), _A == _B) ? EOF : *_A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
int n, a[N], f[N], sum[N];
map<int, int> H;

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	int Task; rd(Task);
	while(Task--){
		rd(n);
        rep(i, 1, n) rd(a[i]), sum[i] = sum[i - 1] ^ a[i];
        // int ans = 0;
        // rep(i, 1, n){
        //     if(a[i] != 0) ++ans, a[i + 1] ^= a[i];
        // }
        int minf = 0; H.clear();
        H[0] = 1;
        rep(i, 1, n){
            f[i] = minf + i;
            if(H.find(sum[i]) != H.end()) --f[i];
            /*for(int j = 0; j < i; ++j){
                if((sum[i] ^ sum[j]) == 0) f[i] = min(f[i], f[j] + (i - j - 1));
                else f[i] = min(f[i], f[j] + i - j);
            }*/
            if(f[i] - i < minf){
                minf = f[i] - i;
                H.clear();
                H[sum[i]] = 1;
            } else
            if(f[i] - i == minf)
                H[sum[i]] = 1;
        }
        printf("%d\n", f[n]);
	}
	return 0;
}