//ID: LRL52  Date: 2022.5.19
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 52; char ss[1 << 21], * A = ss, * B = ss, cc;
inline char gc() { return A == B && (B = (A = ss) + fread(ss, 1, 1 << 21, stdin), A == B) ? EOF : *A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
const int MOD = 10000;
int n, m, st, ed, T;
int G[N][N], Pos[N][14];
struct Mat{
    int c, r, a[52][52];
    Mat(){memset(a, 0, sizeof a); c = r = 0;}
    Mat(int x){
        c = r = x; memset(a, 0, sizeof a);
        for(int i = 0; i < x; ++i) a[i][i] = 1;
    }
    inline Mat operator*(const Mat&t)const{
        Mat ret; ret.c = c, ret.r = t.r;
        for(int i = 0; i < c; ++i)
            for(int j = 0; j < t.r; ++j)
                for(int k = 0; k < r; ++k)
                    ret.a[i][j] = (ret.a[i][j] + 1LL * a[i][k] * t.a[k][j] % MOD) % MOD;
        return ret;
    }
    friend Mat operator^(Mat A, long long k){
        Mat ret(A.c);
        while(k){
            if(k & 1) ret = ret * A;
            A = A * A;
            k >>= 1;
        }
        return ret;
    }
}Ans, g[14], P;

int main() {
#ifdef LRL52
	freopen("K.in", "r", stdin);
#endif
    rd(n), rd(m), rd(st), rd(ed), rd(T);
    int x, y;
    rep(i, 1, m){
        rd(x), rd(y);
        G[x][y] = G[y][x] = 1;
    }
    int K, per; rd(K);
    rep(i, 1, K){
        rd(per);
        for(int j = 0; j < per; ++j) rd(Pos[i][j]);
        for(int j = per; j <= 12; ++j) Pos[i][j] = Pos[i][j - per];
    }
    for(int i = 1; i <= 12; ++i){
        g[i].c = g[i].r = n;
        memcpy(g[i].a, G, sizeof G);
        rep(k, 1, K){
            x = Pos[k][i];
            for(int j = 0; j < n; ++j)
                g[i].a[j][x] = 0;
        }
    }
    P = Mat(n);
    for(int i = 1; i <= 12; ++i)
        P = P * g[i];
    int k = T / 12, r = T % 12;
    Ans.c = 1, Ans.r = n;
    Ans.a[0][st] = 1;
    Ans = Ans * (P ^ k);
    for(int i = 1; i <= r; ++i) Ans = Ans * g[i];
    printf("%d\n", Ans.a[0][ed]);
	return 0;
}