//ID: LRL52  Date: 2022.7.9
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 1e6 + 55; char ss[1 << 21], * A = ss, * B = ss, cc;
inline char gc() { return A == B && (B = (A = ss) + fread(ss, 1, 1 << 21, stdin), A == B) ? EOF : *A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
#define int long long
const int N1 = 1e7, maxv = 1e6;
int sqr[N1 + 5], H[maxv + 5];
int n, a[N];

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	rd(n);
    rep(i, 1, n) rd(a[i]), H[a[i]] = 1;
    rep(i, 1, N1) sqr[i] = i * i;
    int ans = 0;
    for(int i = n; i >= 1; --i){
        int t = a[i] * a[i];;
        int idx = lower_bound(sqr + 1, sqr + N1 + 1, t) - sqr;
        for(int j = idx + 1; j <= N1; ++j){
            int aj = sqr[j] - t;
            if(aj > maxv) break;
            ans += H[aj];
        }
    }
    printf("%lld\n", ans);
	return 0;
}
