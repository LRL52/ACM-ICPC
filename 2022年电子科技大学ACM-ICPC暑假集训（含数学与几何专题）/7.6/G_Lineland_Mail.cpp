//ID: LRL52  Date: 2022.7.6
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
int n;
int a[N];

int main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	rd(n);
    rep(i, 1, n) rd(a[i]);
    rep(i, 1, n){
        int minv = 2000000005;
        if(i > 1) minv = min(minv, a[i] - a[i - 1]);
        if(i < n) minv = min(minv, a[i + 1] - a[i]);
        int maxv = max(a[i] - a[1],  a[n] - a[i]);
        printf("%d %d\n", minv, maxv);
    }
	return 0;
}
