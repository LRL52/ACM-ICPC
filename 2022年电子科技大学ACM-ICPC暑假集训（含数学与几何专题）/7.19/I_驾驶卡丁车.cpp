//ID: LRL52  Date: 2022.7.18
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
int n, m;
char s[N][N], Q[N];
const int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
int Right(int i){return i < 7 ? i + 1 : 0;}
int Left(int i) {return i > 0 ? i - 1 : 7;}

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	scanf("%d%d", &n, &m);
    rep(i, 1, n) scanf("%s", s[i] + 1);
    int qs; scanf("%d%s", &qs, Q + 1);
    int sx = 0, sy = 0;
    rep(i, 1, n)
        rep(j, 1, m){
            if(s[i][j] == '*'){
                sx = i, sy = j;
                break;
            }
        }
    rep(i, 0, n + 1) s[i][0] = s[i][m + 1] = '#';
    rep(i, 0, m + 1) s[0][i] = s[n + 1][i] = '#';
    int v = 0, dir = 0;
    int x = sx, y = sy;
    for(int pp = 1; pp <= qs; ++pp){
        char op = Q[pp];
        if(op == 'L'){
            dir = Left(dir);
        } else
        if(op == 'R'){
            dir = Right(dir);
        } else
        if(op == 'U'){
            v = v + 1;
        } else
        if(op == 'D'){
            v = max(v - 1, 0);
        }
        for(int step = 1; step <= v; ++step){
            int nx = x + dx[dir], ny = y + dy[dir];
            if(s[nx][ny] == '#' || ((dir&1) && s[nx][y] == '#' && s[x][ny] == '#')){
                v = 0;
                printf("Crash! ");
                break;
            }
            x = nx, y = ny;
        }
        printf("%d %d\n", x, y);
    }
	return 0;
}