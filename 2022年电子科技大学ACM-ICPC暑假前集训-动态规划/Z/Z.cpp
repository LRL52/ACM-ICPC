//ID: LRL52  Date: 2022.5.10
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 505, M = 50055; char ss[1 << 21], * A = ss, * B = ss, cc;
inline char gc() { return A == B && (B = (A = ss) + fread(ss, 1, 1 << 21, stdin), A == B) ? EOF : *A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
int n, m;
int val[N], V[N], f[M];

int main() {
#ifdef LRL52
	freopen("Z.in", "r", stdin);
#endif
    rd(n), rd(m);
    rep(i, 1, n) rd(val[i]);
    rep(i, 1, n) rd(V[i]);
    rep(i, 1, n){
        for(int j = m; j >= 0; --j){
            if(j - V[i] >= 0)
                f[j] = max(f[j], f[j - V[i]] +val[i]);
        }
    }
    int ans = 0;
    rep(i, 1, m) ans = max(ans, f[i]);
    printf("%d\n", ans);
	return 0;
}