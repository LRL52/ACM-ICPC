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
int n, m, f[N][N][4];
char s[N][N];
struct Node{
    int x, y, sta, d;
    inline bool operator<(const Node&t)const{
        return d > t.d;
    }
};
priority_queue<Node> q;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
const int Rev[] = {2, 3, 0, 1};

int check(int x, int y, int sta, int k){
    char z = s[x][y];
    if(z == '+') return 1;
    if(z == '-'){
        if(sta == 0 || sta == 2) return k == 3 || k == 1;
        else return k == 0 || k == 2;
    }
    if(z == '|'){
        if(sta == 0 || sta == 2) return k == 0 || k == 2;
        else return k == 3 || k == 1;
    }
    if(z == '^') return (0 + sta) % 4 == k;
    if(z == '>') return (1 + sta) % 4 == k;
    if(z == 'v') return (2 + sta) % 4 == k;
    if(z == '<') return (3 + sta) % 4 == k;
    if(z == 'L') return (3 + sta) % 4 != k;
    if(z == 'R') return (1 + sta) % 4 != k;
    if(z == 'U') return (0 + sta) % 4 != k;
    if(z == 'D') return (2 + sta) % 4 != k;
    return 0;
}

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	scanf("%d%d", &n, &m);
    rep(i, 1, n) scanf("%s", s[i] + 1);
    int sx, sy, ex, ey;
    scanf("%d%d%d%d", &sx, &sy, &ex, &ey);
    memset(f, 0x3f, sizeof(f));
    f[sx][sy][0] = 0;
    q.push((Node){sx, sy, 0, 0});
    while(!q.empty()){
        Node qu = q.top(); q.pop();
        int x = qu.x, y = qu.y, sta = qu.sta;
        if(f[x][y][sta] != qu.d) continue;
        if(x == ex && y == ey){
            printf("%d\n", qu.d);
            return 0;
        }
        for(int k = 0; k < 4; ++k){
            int nx = x + dx[k], ny = y + dy[k];
            if(nx < 1 || nx > n || ny < 1 || ny > m) continue;
            if(!check(x, y, sta, k) || !check(nx, ny, sta, Rev[k])) continue;
            if(f[x][y][sta] + 1 < f[nx][ny][sta]){
                f[nx][ny][sta] = f[x][y][sta] + 1;
                q.push((Node){nx, ny, sta, f[nx][ny][sta]});
            }
        }
        if(f[x][y][sta] + 1 < f[x][y][(sta + 1) % 4]){
            f[x][y][(sta + 1) % 4] = f[x][y][sta] + 1;
            q.push((Node){x, y, (sta + 1) % 4, f[x][y][(sta + 1) % 4]});
        }
    }
    puts("-1");
	return 0;
}