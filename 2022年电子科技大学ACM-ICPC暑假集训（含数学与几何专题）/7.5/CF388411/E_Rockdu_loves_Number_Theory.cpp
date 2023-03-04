//ID: LRL52  Date: 2022.7.5
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 2e5 + 55; char ss[1 << 21], * A = ss, * B = ss, cc;
inline char gc() { return A == B && (B = (A = ss) + fread(ss, 1, 1 << 21, stdin), A == B) ? EOF : *A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
#define int long long
int n, m;
int a[N];
int gcd(int a, int b){return a == 0 ? b : gcd(b % a, a);}

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	rd(n), rd(m); int x;
    rep(i, 1, n) rd(a[i]);
    int d = a[2] - a[1];
    rep(i, 2, n){
        if(i & 1) d = gcd(d, a[i] - a[1]);
        else d = gcd(d, a[i] - a[i - 1]);
    }
    rep(i, 1, m){
        rd(x);
        if(n == 1) printf("%lld ", a[1] + x);
        else {
            int ans = gcd(a[1] + x, d);
            printf("%lld ", ans > 0 ? ans : -ans);
        }
    }
	return 0;
}
