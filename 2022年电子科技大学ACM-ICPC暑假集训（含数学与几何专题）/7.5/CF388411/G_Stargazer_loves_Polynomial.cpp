//ID: LRL52  Date: 2022.7.5
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 2055; char ss[1 << 21], * A = ss, * B = ss, cc;
inline char gc() { return A == B && (B = (A = ss) + fread(ss, 1, 1 << 21, stdin), A == B) ? EOF : *A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
int n, m;
int a[N];

int main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	rd(n), rd(m);
    if(n > 2000){
        puts("0");
        return 0;
    }
    int ans = 1;
    rep(i, 1, n) rd(a[i]);
    rep(i, 1, n)
        rep(j, i + 1, n)
            ans = 1LL * ans * abs(a[i] - a[j]) % m;
    ans = (ans % m + m) % m;
    printf("%d\n", ans);
	return 0;
}
