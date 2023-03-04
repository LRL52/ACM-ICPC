//ID: LRL52  Date: 2022.7.21
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
int n, vis[N][N];
char s[N][N];
const int dx[] = {1, 1, 1, 2};
const int dy[] = {0, -1, 1, 0};

void ExitNo(){
    puts("NO");
    exit(0);
}

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	scanf("%d", &n);
    rep(i, 1, n){
        scanf("%s", s[i] + 1);
    }
    rep(i, 1, n){
        rep(j, 1, n){
            if(s[i][j] == '#' && !vis[i][j]){
                vis[i][j] = 1;
                for(int k = 0; k < 4; ++k){
                    int x = i + dx[k], y = j + dy[k];
                    if(x < 1 || x > n || y < 1 || y > n) ExitNo();
                    if(vis[x][y]) ExitNo();
                    if(s[x][y] != '#') ExitNo();
                    vis[x][y] = 1;
                }
            }
        }
    }
    puts("YES");
	return 0;
}