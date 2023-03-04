//ID: LRL52  Date: 2022.7.12
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 1e5 + 55; char ss[1 << 21], * A = ss, * B = ss, cc;
inline char gc() { return A == B && (B = (A = ss) + fread(ss, 1, 1 << 21, stdin), A == B) ? EOF : *A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
#define int long long
int n, K, sum[N], a[N];

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	int Task; rd(Task);
	while(Task--){
        rd(n), rd(K);
        rep(i, 1, n) rd(a[i]), sum[i] = sum[i - 1] + a[i];
        /*int res = 0;
        for(int k = 0; k <= 32; ++k){
            rep(i, 1, n) b[i] = a[i];
            rep(i, 1, n){*/
        int ans = max(0LL, sum[n] - n * K);
        for(int i = n; i >= 1; --i){
            int res = sum[i - 1] - K * (i - 1);
            for(int j = i; j <= n; ++j){
                if(j - i + 1 > 32) break;
                a[j] /= 2;
                res += a[j];
            }
            ans = max(ans, res);
        }
        printf("%lld\n", ans);
	}
	return 0;
}
