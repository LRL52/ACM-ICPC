//ID: LRL52  Date: 2022.8.8 ~ 8.9
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 1e5 + 55, M = 2055, inf = 0x3f3f3f3f; char Buf[1 << 21], *_A = Buf, *_B = Buf, cc;
inline char gc() { return _A == _B && (_B = (_A = Buf) + fread(Buf, 1, 1 << 21, stdin), _A == _B) ? EOF : *_A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
#define int long long
int n, a[N], tail[N], f[N][20][20], g[N][20], Cnt[N][20], h[N][20];
struct Node{
    int a, val, j, k;
    inline bool operator<(const Node&t)const{
        return a < t.a;
    }
}v[2][405];

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	int Task; rd(Task);
    const int UP = 17, MAXVAL = 100000;
	while(Task--){
		rd(n);
        rep(i, 1, n) rd(a[i]), tail[i] = 0;
        for(int j = 0; j <= UP; ++j)
            for(int k = 0; k <= UP; ++k){
                f[1][j][k] = j + k;
                v[1][++tail[1]] = {(a[1] >> j) << k, j + k, j, k};
                //printf("v[1].val, j, k = %lld %lld %lld\n", v[1][].val, a[1].j, a[1].k);
            }
        sort(v[1] + 1, v[1] + tail[1] + 1);
        for(int i = 2; i <= n; ++i){
            int now = i & 1, lst = now ^ 1;
            //#define v[i] v[now]
            //#define v[i-1] v[lst]
            for(int j = 0; j <= UP; ++j){
                for(int k = 0; k <= UP; ++k){
                    f[i][j][k] = inf;
                    v[now][++tail[i]] = {(a[i] >> j) << k, 0, j, k};
                }
            }
            assert(tail[i] < 400);
            sort(v[now] + 1, v[now] + tail[i] + 1);
            int p = 0, fval = inf;
            for(int t = 1; t <= tail[i]; ++t){
                int j = v[now][t].j, k = v[now][t].k;
                while(p < tail[i - 1] && v[lst][p + 1].a <= v[now][t].a){
                    ++p;
                    fval = min(fval, v[lst][p].val);
                    //if(v[i-1][p].val == 0) printf("i-1 = %lld %lld %lld\n", i - 1, v[i-1][p].j, v[i-1][p].k);
                }
                //if(i == n && j == 0 && k == 0) printf("fval = %lld t = %lld tail[i] = %lld\n", fval, t, tail[i]);
                f[i][j][k] = v[now][t].val = min(f[i][j][k], fval + j + k);
            }
            //#undef v[i]
            //#undef v[i-1]
            //for(int t = 1; t <= tail[i]; ++t) printf("v[%lld][%lld].a = %lld v[i][t].val = %lld\n", i, t, v[i][t].a, v[i][t].val);
        }
        for(int i = 1; i <= n; ++i){
            for(int j = 0; j <= UP; ++j){
                h[i][j] = Cnt[i][j] = 0;
                for(int k = 0; k <= UP; ++k){
                    if(((a[i] >> j) << k) > MAXVAL){
                        h[i][j] = ((a[i] >> j) << k);
                        Cnt[i][j] = k;
                        break;
                    }
                }
            }
        }
        for(int j = 0; j <= UP; ++j){
            g[n][j] = inf;
            if(h[n][j] > MAXVAL){
                g[n][j] = j + Cnt[n][j];
            }
        }
        for(int i = n - 1; i >= 1; --i){
            for(int j = 0; j <= UP; ++j){
                g[i][j] = inf;
                if(h[i][j] <= MAXVAL) continue;
                for(int k = 0; k <= UP; ++k){
                    if(h[i + 1][k] <= MAXVAL) continue;
                    if(h[i + 1][k] >= h[i][j])
                        g[i][j] = min(g[i][j], g[i + 1][k] + j + Cnt[i][j]);
                    else 
                        g[i][j] = min(g[i][j], g[i + 1][k] + (n - i) + j + Cnt[i][j]); //不是乘2！！
                }
            }
        }
        int ans = inf;
        for(int j = 0; j <= UP; ++j)
            for(int k = 0; k <= UP; ++k){
                //printf("f[n][%lld][%lld] = %lld\n", j, k, f[n][j][k]);
                ans = min(ans, f[n][j][k]);
            }
        for(int i = 1; i <= n; ++i){
            for(int j = 0; j <= UP; ++j){
                if(h[i][j] <= MAXVAL) continue;
                int t = Cnt[i][j];
                ans = min(ans, f[i][j][t] + g[i][j] - (j + t));
            }
        }
        printf("%lld\n", ans);
	}
	return 0;
}