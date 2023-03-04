//ID: LRL52  Date: 2022.7.8
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 2055; char ss[1 << 21], * A = ss, * B = ss, cc;
inline char gc() { return A == B && (B = (A = ss) + fread(ss, 1, 1 << 21, stdin), A == B) ? EOF : *A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
int n, K, vis[N][N], f[N][N];
char s[N][N];
vector<pair<int, int> > q1, q2;
vector<char> Ans;

int main() {
#ifdef LRL52
	freopen("J.in", "r", stdin);
#endif
	scanf("%d%d", &n, &K);
    rep(i, 1, n) scanf("%s", s[i] + 1);
    f[1][1] = K + (s[1][1] == 'a');
    rep(i, 1, n){
        rep(j, 1, n){
            if(i == 1 && j == 1) continue;
            int res = max(f[i - 1][j], f[i][j - 1]);
            f[i][j] = res > 0 ? res - 1 + (s[i][j] == 'a') : -1;
        }
    }
    int maxstep = -1;
    rep(i, 1, n)
        rep(j, 1, n)
            if(f[i][j] == 0)
                maxstep = max(maxstep, i + j - 2);
    if(f[n][n] > 0){ //不是maxstep = -1，判断终止条件！！！
        rep(i, 1, 2 * n - 1) putchar('a');
        return 0;
    }
    rep(i, 1, n)
        rep(j, 1, n)
            if(f[i][j] == 0 && i + j - 2 == maxstep)
                q1.push_back(make_pair(i, j)), vis[i][j] = 1;
    while(q1.size() > 0){
        char res = 'z' + 1;
        for(int i = 0; i < q1.size(); ++i) res = min(res, s[q1[i].first][q1[i].second]);
        assert(res >= 'a' && res <= 'z');
        Ans.push_back(res);
        q2.clear();
        for(int i = 0; i < q1.size(); ++i){
            int x = q1[i].first, y = q1[i].second;
            if(s[x][y] == res){
                int nx = x, ny = y + 1;
                if(nx >= 1 && nx <= n && ny >= 1 && ny <= n && !vis[nx][ny]){
                    q2.push_back(make_pair(nx, ny));
                    vis[nx][ny] = 1;
                }
                nx = x + 1, ny = y;
                if(nx >= 1 && nx <= n && ny >= 1 && ny <= n && !vis[nx][ny]){
                    q2.push_back(make_pair(nx, ny));
                    vis[nx][ny] = 1;
                }
            }
        }
        q1.clear();
        for(int i = 0; i < q2.size(); ++i) q1.push_back(q2[i]);
    }
    int anscnt = 0;
    rep(i, 1, maxstep) putchar('a'), ++anscnt;
    for(int i = 0; i < Ans.size(); ++i) putchar(Ans[i]), ++anscnt;
    assert(anscnt == 2 * n - 1);
	return 0;
}
