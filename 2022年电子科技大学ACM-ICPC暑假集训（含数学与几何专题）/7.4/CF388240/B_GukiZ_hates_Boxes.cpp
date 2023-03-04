//ID: LRL52  Date: 2022.7.4
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
int n, m;
int a[N], b[N];

int check(int endt){
    int p = n;
    rep(i, 1, n) b[i] = a[i];
    rep(i, 1, m){
        while(p > 0 && b[p] == 0) --p;
        int res = endt - p;
        while(res > 0 && p > 0){
            int k = min(res, b[p]);
            b[p] -= k, res -= k;
            while(p > 0 && b[p] == 0) --p;
        }
        if(p == 0) return 1;
    }
    return 0;
}

signed main() {
#ifdef LRL52
	freopen("B.in", "r", stdin);
#endif
	rd(n), rd(m); long long s = 0;
    rep(i, 1, n) rd(a[i]), s += a[i];
    int l = 0, r = s + n;
    while(l <= r){
        int mid = (l + r) >> 1;
        if(check(mid)) r = mid - 1;
        else l = mid + 1;
    }
    printf("%lld\n", l);
 	return 0;
}