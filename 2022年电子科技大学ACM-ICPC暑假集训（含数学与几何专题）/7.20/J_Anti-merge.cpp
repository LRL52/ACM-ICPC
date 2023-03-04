//ID: LRL52  Date: 2022.7.20
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 1e3 + 55, M = 2055, inf = 0x3f3f3f3f; char Buf[1 << 21], *_A = Buf, *_B = Buf, cc;
inline char gc() { return _A == _B && (_B = (_A = Buf) + fread(Buf, 1, 1 << 21, stdin), _A == _B) ? EOF : *_A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
int n, m, a[N][N], belong[N][N], col[N][N], col1, col2, Col[N*N];
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

void dfs(int x, int y, int bel, int co){
    belong[x][y] = bel, col[x][y] = co;
    if(co == 1) ++col1;
    else ++col2;
    for(int k = 0; k < 4; ++k){
        int nx = x + dx[k], ny = y + dy[k];
        if(nx < 1 || nx > n || ny < 1 || ny > m) continue;
        if(belong[nx][ny]) continue;
        if(a[nx][ny] != a[x][y]) continue;
        dfs(nx, ny, bel, 3 - co);
    }
}

signed main() {
#ifdef LRL52
	freopen("J.in", "r", stdin);
#endif
	rd(n), rd(m);
    rep(i, 0, n + 1) rep(j, 0, m + 1) a[i][j] = 0;
    rep(i, 1, n)
        rep(j, 1, m)
            rd(a[i][j]);
    int ok = 1;
    rep(i, 1, n){
        rep(j, 1, m){
            if(a[i][j] == a[i - 1][j] || a[i][j] == a[i + 1][j] ||
            a[i][j] == a[i][j + 1] || a[i][j] == a[i][j - 1]){
                ok = 0;
                break;
            }
        }
        if(!ok) break;
    }
    if(ok){
        puts("0 0");
        return 0;
    }
    /*int cnt1 = 0, cnt2 = 0;
    rep(i, 1, n){
        rep(j, 1, m){
            int adj = a[i][j] == a[i - 1][j] || a[i][j] == a[i + 1][j] ||
                    a[i][j] == a[i][j + 1] || a[i][j] == a[i][j - 1];
            if(((i + j) & 1) == 1 && adj) ++cnt1;
            if(((i + j) & 1) == 0 && adj) ++cnt2;
        }
    }
    int bit = 1;
    if(cnt2 < cnt1) swap(cnt1, cnt2), bit = 0;
    printf("1 %d\n", cnt1);
    rep(i, 1, n){
        rep(j, 1, m){
            int adj = a[i][j] == a[i - 1][j] || a[i][j] == a[i + 1][j] ||
                    a[i][j] == a[i][j + 1] || a[i][j] == a[i][j - 1];
            if(((i + j) & 1) == bit && adj){
                printf("%d %d 1\n", i, j);
            }
        }
    }*/
    int block = 0, res = 0;
    rep(i, 1, n){
        rep(j, 1, m){
            if(belong[i][j]) continue;
            col1 = col2 = 0;
            dfs(i, j, ++block, 1);
            if(col2 < col1) Col[block] = 2;
            else Col[block] = 1;
            res += min(col1, col2);
        }
    }
    printf("1 %d\n", res);
    rep(i, 1, n){
        rep(j, 1, m){
            int co = col[i][j];
            if(co == Col[belong[i][j]]){
                printf("%d %d 1\n", i, j);
            }
        }
    } 
	return 0;
}