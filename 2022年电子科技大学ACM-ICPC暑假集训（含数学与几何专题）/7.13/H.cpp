//ID: LRL52  Date: 2022.7.13
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <algorithm>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 305; char ss[1 << 21], * A = ss, * B = ss, cc;
inline char gc() { return A == B && (B = (A = ss) + fread(ss, 1, 1 << 21, stdin), A == B) ? EOF : *A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
int n, m, f[N][N];
char s[N][N];
struct Node{
    int x, y, d;
    inline bool operator<(const Node&t)const{
        return d > t.d;
    }
};
priority_queue<Node> q;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

int main() {
#ifdef LRL52
	freopen("H.in", "r", stdin);
#endif
	scanf("%d%d", &n, &m);
    rep(i, 1, n) scanf("%s", s[i] + 1);
    memset(f, 0x3f, sizeof(f));
    int sx = 0, sy = 0;
    rep(i, 1, n)
        rep(j, 1, m){
            if(s[i][j] == '@'){
                sx = i, sy = j;
            }
        }
    f[sx][sy] = 0;
    q.push((Node){sx, sy, 0});
    while(!q.empty()){
        Node qu = q.top(); q.pop();
        int x = qu.x, y = qu.y;
        if(f[x][y] != qu.d) continue;
        if(s[x][y] == 'M'){
            printf("%d\n", f[x][y]);
            return 0;
        }
        for(int k = 0; k < 4; ++k){
            int nx = x + dx[k], ny = y + dy[k];
            if(nx < 1 || nx > n || ny < 1 || ny > m) continue;
            if(s[nx][ny] == '#') continue;
            int w = s[nx][ny] != 'G' ? 1 : 2;
            if(f[x][y] + w < f[nx][ny]){
                f[nx][ny] = f[x][y] + w;
                q.push((Node){nx, ny, f[nx][ny]});
            }
        }
    }
    puts("You can't save Mengxin");
	return 0;
}
