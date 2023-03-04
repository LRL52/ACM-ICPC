//ID: LRL52  Date: 2022.5.10
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 5055; char ss[1 << 21], * A = ss, * B = ss, cc;
inline char gc() { return A == B && (B = (A = ss) + fread(ss, 1, 1 << 21, stdin), A == B) ? EOF : *A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
int n, qs;
int f[N][N], Ans[N][N];

int main() {
#ifdef LRL52
	freopen("I.in", "r", stdin);
#endif
    rd(n);
    rep(i, 1, n) rd(f[i][i]), Ans[i][i] = f[i][i];
    rep(len, 2, n){
        for(int i = 1; i + len - 1 <= n; ++i){
            int j = i + len - 1;
            f[i][j] = f[i][j - 1] ^ f[i + 1][j];
            Ans[i][j] = max(Ans[i][j - 1], max(Ans[i + 1][j], f[i][j]));
        }
    }
    rd(qs); int l, r;
    rep(i, 1, qs){
        rd(l), rd(r);
        printf("%d\n", Ans[l][r]);
    }
	return 0;
}