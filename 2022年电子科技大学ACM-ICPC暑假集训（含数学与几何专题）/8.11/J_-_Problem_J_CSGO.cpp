//ID: LRL52  Date: 2022.8.10
//K维最长曼哈顿距离
//考虑两点之间的曼哈顿距离，两点每一维的贡献一定是一正一负，所以可以2^k枚举每一维+-，具体见代码
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 200000 + 55, M = 2055, inf = 0x3f3f3f3f; char Buf[1 << 21], *_A = Buf, *_B = Buf, cc;
inline char gc() { return _A == _B && (_B = (_A = Buf) + fread(Buf, 1, 1 << 21, stdin), _A == _B) ? EOF : *_A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
typedef long long LL;
const LL INF = 0x3f3f3f3f3f3f3f3f;
int n, m, K, a[N], X[N][7];
LL Maxv[N];

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	int Task; rd(Task);
	while(Task--){
		rd(n), rd(m), rd(K);
        rep(i, 1, n + m){
            rd(a[i]);
            for(int j = 0; j < K; ++j) rd(X[i][j]);
        }
        for(int s = 0; s < (1 << K); ++s){
            Maxv[s] = -INF;
            rep(i, 1, n){
                LL res = a[i];
                for(int j = 0; j < K; ++j){
                    if(s >> j & 1) res += X[i][j];
                    else res -= X[i][j];
                }
                Maxv[s] = max(Maxv[s], res);
            }
        }
        LL ans = -INF; int mask = (1 << K) - 1;
        for(int i = n + 1; i <= n + m; ++i){
            for(int s = 0; s < (1 << K); ++s){
                LL res = a[i];
                for(int j = 0; j < K; ++j){
                    if(s >> j & 1) res += X[i][j];
                    else res -= X[i][j];
                }
                int _s = (~s) & mask; //每一维+-相反的可以与它求和即是可能的曼哈顿距离的计算结果
                ans = max(ans, res + Maxv[_s]);
            }
        }
        printf("%lld\n", ans);       
	}
	return 0;
}