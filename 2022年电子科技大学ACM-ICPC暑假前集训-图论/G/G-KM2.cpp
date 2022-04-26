//ID: LRL52  Date: 2022.4.20-4.21
//#pragma GCC optimize(2)
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <algorithm>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 405; char ss[1 << 21], * A = ss, * B = ss, cc;
inline char gc() { return A == B && (B = (A = ss) + fread(ss, 1, 1 << 21, stdin), A == B) ? EOF : *A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
typedef long long LL;
const int _inf = 0xc1c1c1c1, inf = 0x3f3f3f3f; 
int n, delta;
LL a[N], b[N], c[N];
int w[N], sum[N], W[N][N], la[N], lb[N], va[N], vb[N], match[N];
struct Node{
    LL c; int w;
    Node(LL _c = 0, int _w = 0){
        c = _c, w = _w;
    }
    inline bool operator<(const Node&t)const{
        return c < t.c;
    }
}U[N];

int dfs(int x){
    va[x] = 1;
    rep(y, 1, n){
        if(!vb[y])
            if(la[x] + lb[y] - W[x][y] == 0){
                vb[y] = 1;
                if(!match[y] || dfs(match[y])){
                    match[y] = x;
                    return 1;
                }
            }
            //else delta = min(delta, la[x] + lb[y] - W[x][y]);
    }
    return 0;
}

int main() {
#ifdef LRL52
	freopen("G.in", "r", stdin);
#endif
    rd(n);
    rep(i, 1, n) rd(c[i]);
    rep(i, 1, n) rd(w[i]);
    rep(i, 1, n) rd(a[i]);
    rep(i, 1, n) rd(b[i]);
    rep(i, 1, n) U[i].c = c[i], U[i].w = w[i];
    sort(U + 1, U + n + 1);
    rep(i, 1, n) sum[i] = sum[i - 1] + U[i].w;
    memset(W, -0x3f, sizeof W);
    rep(i, 1, n){
        rep(j, 1, n){
            LL d = a[i] + b[j];
            //int W = 0;
            /*rep(k, 1, n){
                if(d > c[k])
                    W += w[k];
            }*/
            int pos = lower_bound(U + 1, U + n + 1, Node(d, 0)) - U - 1;
            W[i][j] = sum[pos];
            //Adde(i, j + n, 1, sum[pos]);
            //printf("%d -> %d w = %d\n", i, j + n, W);
        }
    }
    rep(i, 1, n){
        la[i] = _inf;
        lb[i] = 0;
        rep(j, 1, n)
            la[i] = max(la[i], W[i][j]);
    }
    rep(_i, 1, n){
        while(1){
            memset(va, 0, sizeof va);
            memset(vb, 0, sizeof vb);
            if(dfs(_i)) break;
            delta = inf;
            for (int i=1;i<=n;i++)
            {
                if (!va[i]) continue;
                for (int j=1;j<=n;j++)
                {
                    if (vb[j]) continue;
                    delta = min(delta, la[i] + lb[j] - W[i][j]);
                }
            }
            rep(j, 1, n){
                if(va[j]) la[j] -= delta;
                if(vb[j]) lb[j] += delta;
            }
            printf("delta = %d\n", delta);
        }
    }
    int ans = 0;
    rep(i, 1, n) ans += W[match[i]][i];
    printf("%d\n", ans);
	return 0;
}