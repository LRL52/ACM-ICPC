//ID: LRL52  Date: 2022.8.2
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 105, M = 2055, inf = 0x3f3f3f3f; char Buf[1 << 21], *_A = Buf, *_B = Buf, cc;
inline char gc() { return _A == _B && (_B = (_A = Buf) + fread(Buf, 1, 1 << 21, stdin), _A == _B) ? EOF : *_A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
int vis[N][N][N], f[N][N][N];

int SG(int a, int b, int c){
    if(vis[a][b][c]) return f[a][b][c];
    vis[a][b][c] = 1;
    if(a + b <= c) return f[a][b][c] = 0;
    map<int, int> s;
    for(int i = 1; i < a; ++i){
        int na = a - i;
        if(na + b > c) s[SG(na, b, c)] = 1;
    }
    for(int i = 1; i < b; ++i){
        int nb = b - i;
        int ta = a;
        if(nb < ta) swap(nb, ta);
        if(ta + nb > c) s[SG(ta, nb, c)] = 1;
    }
    for(int i = 1; i < c; ++i){
        int nc = c - i;
        int ta = a, tb = b;
        if(nc < tb) swap(tb, nc);
        if(tb < ta) swap(tb, ta);
        if(ta + tb > nc) s[SG(ta, tb, nc)] = 1;
    }
    for(int i = 0;; ++i){
        if(s[i] == 0){
            f[a][b][c] = i;
            break;
        }
    }
    return f[a][b][c];
}

    

void init(){
    int MAXN = 100;
    for(int i = 1; i <= MAXN; ++i){
        for(int j = i; j <= MAXN; ++j){
            for(int k = j; k <= MAXN; ++k){
                SG(i, j, k);
                if(i + j > k && f[i][j][k] == 0) printf("f[%d][%d][%d] = %d  %d\n", i, j, k, f[i][j][k], (i-1)^(j-1)^(k-1));
            }
        }
    }
}

signed main() {
#ifdef LRL52
	freopen("H.in", "r", stdin);
#endif
    init();
	int Task; rd(Task);
    int a[3];
	while(Task--){
		rd(a[0]), rd(a[1]), rd(a[2]);
        sort(a, a + 3);
        f[a[0]][a[1]][a[2]] ? puts("Win") : puts("Lose");
	}
	return 0;
}