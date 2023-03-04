//ID: LRL52  Date: 2022.5.10
//草，不看题解还不会了
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
int n, W;
int a[N], f[N];

int main() {
#ifdef LRL52
	freopen("L.in", "r", stdin);
#endif
    rd(n), rd(W);
    rep(i, 1, n) rd(a[i]), a[i] -= i;
    memset(f, 0x3f, sizeof f);
    rep(i, 1, n) *upper_bound(f + 1, f + n + 1, a[i]) = a[i];
    int ans = lower_bound(f + 1, f + n + 1, 0x3f3f3f3f) - f - 1;
    printf("%lld\n", (long long)(n - ans) * W);
	return 0;
}