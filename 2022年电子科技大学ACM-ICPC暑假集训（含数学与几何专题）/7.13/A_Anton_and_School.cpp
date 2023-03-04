//ID: LRL52  Date: 2022.7.13
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 400055; char ss[1 << 21], * A = ss, * B = ss, cc;
inline char gc() { return A == B && (B = (A = ss) + fread(ss, 1, 1 << 21, stdin), A == B) ? EOF : *A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
#define int long long
int n;
int a[N], b[N], c[N];

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	rd(n); int S = 0;
    rep(i, 1, n) rd(b[i]), S += b[i];
    rep(i, 1, n) rd(c[i]), S += c[i];
    if(S % (n + n)){
        puts("-1");
        return 0;
    }
    int ok = 1, sum = S / (n + n);
    rep(i, 1, n){
        int t = b[i] + c[i] - sum;
        if(t % n){
            ok = 0;
            break;
        }
        a[i] = t / n;
    }
    if(ok){
        rep(i, 1, n) printf("%lld ", a[i]);
    } else
        puts("-1");
	return 0;
}
