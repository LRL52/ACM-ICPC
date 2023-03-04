//ID: LRL52  Date: 2022.8.20
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 2e3 + 55, M = 2055, inf = 0x3f3f3f3f; char Buf[1 << 21], *_A = Buf, *_B = Buf, cc;
inline char gc() { return _A == _B && (_B = (_A = Buf) + fread(Buf, 1, 1 << 21, stdin), _A == _B) ? EOF : *_A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
int n, m;
int Nxt[N][N][4], step[N][N], dis[N][N];
char s[N][N];
struct Node{
    int x, y, d;
    inline bool operator<(const Node&t)const{
        return d > t.d;
    }
};
queue<Node> q;
pair<int, int> Pre[N][N];
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
const int order[] = {2, 3, 1, 0};
const char Ans[] = {'U', 'R', 'D', 'L'};

void getans(int x, int y, int sx, int sy){
    if(x == sx && y == sy) return;
    int lstx = Pre[x][y].first, lsty = Pre[x][y].second;
    getans(lstx, lsty, sx, sy);
    char c = Ans[step[x][y]];
    putchar(c);
}
    
signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	scanf("%d%d", &n, &m);
    rep(i, 1, n) scanf("%s", s[i] + 1);
    int sx, sy, ex, ey;
    rep(i, 1, n){
        rep(j, 1, m){
            if(s[i][j] == 'S'){
                sx = i, sy = j;
                s[i][j] = '.';
            }
            if(s[i][j] == 'E'){
                ex = i, ey = j;
                s[i][j] = '.';
            }
        }
    }
    rep(j, 1, m){
        int lst = 0;
        for(int i = 1; i <= n; ++i){
            if(s[i][j] == 'X') Nxt[i][j][0] = lst;
            else lst = i;
        }
        lst = 0;
        for(int i = n; i >= 1; --i){
            if(s[i][j] == 'X') Nxt[i][j][2] = lst;
            else lst = i;
        }
    }
    rep(i, 1, n){
        int lst = 0;
        for(int j = 1; j <= m; ++j){
            if(s[i][j] == 'X') Nxt[i][j][3] = lst;
            else lst = j;
        }
        lst = 0;
        for(int j = m; j >= 1; --j){
            if(s[i][j] == 'X') Nxt[i][j][1] = lst;
            else lst = j;
        }
    }
    memset(dis, 0x3f, sizeof(dis));
    dis[sx][sy] = 0;
    q.push({sx, sy, 0});
    Pre[sx][sy] = make_pair(0, 0);
    while(!q.empty()){
        Node qu = q.front(); q.pop();
        int x = qu.x, y = qu.y;
        if(dis[x][y] != qu.d) continue;
        if(x == ex && y == ey){
            printf("%d\n", dis[x][y]);
            getans(ex, ey, sx, sy);
            return 0;
        }
        for(int t = 0; t < 4; ++t){
            int k = order[t];
            int nx = x + dx[k], ny = y + dy[k];
            if(nx < 0 || nx > n || ny < 0 || ny > m) continue;
            if(s[nx][ny] == 'X'){
                if(k & 1) ny = Nxt[nx][ny][k];
                else nx = Nxt[nx][ny][k];
            }
            if(nx == 0 || ny == 0) continue;
            if(dis[x][y] + 1 < dis[nx][ny]){
                dis[nx][ny] = dis[x][y] + 1;
                Pre[nx][ny] = make_pair(x, y);
                step[nx][ny] = k;
                q.push({nx, ny, dis[nx][ny]});
            }
        }
    }
    puts("-1");
	return 0;
}