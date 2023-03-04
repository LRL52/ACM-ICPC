//ID: LRL52  Date: 2022.8.5
//表示状态的话细节有点烦
//我的处理是在两个点中间加入新的点, 这样后面写代码会轻松很多
//优先队列 + 最短路
//注意把运算移到sqrt里面可以大大提高精度(雾~)
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 3e3 + 55, inf = 0x3f3f3f3f; char Buf[1 << 21], *_A = Buf, *_B = Buf, cc;
inline char gc() { return _A == _B && (_B = (_A = Buf) + fread(Buf, 1, 1 << 21, stdin), _A == _B) ? EOF : *_A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}

//void viewleft(int i, int h, int &ni, int &nh){
    

/*double dfs(int i, int j, int h){
    if(vis[i][j][k]) return f[i][j][k];
    vis[i][j][k] = 1;
    if(i == j) return f[i][j][k] = 0.0F;
    if(i + 1 == j && h[i] == h[j]) return f[i][j][k] = 1.0F;
    long double &F = f[i][j][k];
    F = 1e18;
    int ni, nh1, nj, nh2;
    viewleft(i, h, ni, nh1);*/
#define double long double
const double eps = 1e-8;
int n, H[N], vis[N][N];
double f[N][N], H2[N], L[N], R[N];
const int di[] = {1, 1, -1, -1, 1, -1, 0, 0};
const int dj[] = {-1, 1, -1, 1, 0, 0, 1, -1};
struct Node{
    int i, j;
    double d;
    inline bool operator<(const Node&t)const{
        return d > t.d;
    }
};

signed main() {
#ifdef LRL52
	freopen("C.in", "r", stdin);
#endif
	int Task; rd(Task);
	while(Task--){
		rd(n);
        rep(i, 0, n) rd(H[i]);
        int tot = 0;
        for(int i = 0; i < n; ++i){
            int t = max(1, abs(H[i + 1] - H[i]));
            double dh = (H[i + 1] - H[i]) / (double)t;
            double d = sqrt(((H[i + 1] - H[i]) * (H[i + 1] - H[i]) + 1.0F) / (double)(t*t));
            for(int j = 0; j < t; ++j){
                H2[++tot] = (double)H[i] + dh * j;
                R[tot] = d;
            }
        }
        H2[++tot] = 0.0;
        assert(tot < 3000);
        rep(i, 2, tot) L[i] = R[i - 1];
        rep(i, 1, tot)
            rep(j, 1, tot)
                vis[i][j] = 0, f[i][j] = 1e35;
        priority_queue<Node> q;
        f[1][tot] = 0.0F;
        q.push({1, tot, 0.0F}); int ok = 0;
        while(!q.empty()){
            Node qu = q.top(); q.pop();
            int i = qu.i, j = qu.j;
            if(vis[i][j]) continue;
            vis[i][j] = 1;
            /*if(i == j){
                printf("%.15Lf\n", f[i][j] * 2.0F);
                ok = 1;
                break;
            }
            if(i + 1 == j && abs(H2[i] - H2[j]) < eps){
                printf("%.15Lf\n", (f[i][j] + 1.0F) * 2.0F);
                ok = 1;
                break;
            }*/
            if(i == tot && j == 1){
                printf("%.15Lf\n", f[i][j]);
                ok = 1;
                break;
            }
            for(int k = 0; k < 8; ++k){
                int ni = i + di[k], nj = j + dj[k];
                if(ni < 1 || ni > tot || nj < 1 || nj > tot) continue;
                if(vis[ni][nj]) continue;
                if(abs(H2[ni] - H2[nj]) >= eps) continue;
                //vis[ni][nj] = 1;
                double d = 0.0F;
                if(ni < i) d += L[i];
                if(ni > i) d += R[i];
                if(nj < j) d += L[j];
                if(nj > j) d += R[j];
                if(f[i][j] + d < f[ni][nj] - eps){
                    f[ni][nj] = f[i][j] + d;
                    q.push({ni, nj, f[ni][nj]});
                }
            }
        }
        assert(ok);
        //printf("%.15Lf\n", f[1][tot]);
	}
	return 0;
}