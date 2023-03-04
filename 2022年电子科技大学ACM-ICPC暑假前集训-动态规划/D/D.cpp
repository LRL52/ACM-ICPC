//ID: LRL52  Date: 2022.5.10
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 3055; char ss[1 << 21], * A = ss, * B = ss, cc;
inline char gc() { return A == B && (B = (A = ss) + fread(ss, 1, 1 << 21, stdin), A == B) ? EOF : *A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
const int inf = 0x3f3f3f3f;
int n, m;
int a[N], f[N][N];

inline int dist(int x, int y){return min(abs(y - x), m - abs(y - x));}

int main() {
#ifdef LRL52
	freopen("D.in", "r", stdin);
#endif
    rd(n), rd(m); int x, y, z;
    rd(x), rd(y), rd(z);
    rep(i, 1, n) rd(a[i]);
    memset(f, 0x3f, sizeof f);
    f[2][x] = min(dist(y, a[1]) + dist(z, a[2]), dist(y, a[2]) + dist(z, a[1]));
    f[2][y] = min(dist(x, a[1]) + dist(z, a[2]), dist(x, a[2]) + dist(z, a[1]));
    f[2][z] = min(dist(x, a[1]) + dist(y, a[2]), dist(x, a[2]) + dist(y, a[1]));
    //f[i][j] (i >= 2), 三根指针分别在a_i, a_{i-1} 和 j 上
    for(int i = 2; i < n; ++i){
        for(int j = 1; j <= m; ++j){
            if(f[i][j] == inf) continue;
            //移动 a_{i-1} 到 a_{i+1}
            f[i + 1][j] = min(f[i][j] + dist(a[i-1], a[i+1]), f[i + 1][j]);
            //移动 j 到 a_{i+1}
            f[i + 1][a[i-1]] = min(f[i][j] + dist(j, a[i+1]), f[i + 1][a[i-1]]);
        }
    }
    int ans = inf;
    rep(i, 1, m) ans = min(ans, f[n][i]);
    printf("%d\n", ans);
	return 0;
}