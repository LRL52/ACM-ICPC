//ID: LRL52  Date: 2022.8.13
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 1e5 + 55, M = 1e5 + 55, inf = 0x3f3f3f3f; char Buf[1 << 21], *_A = Buf, *_B = Buf, cc;
inline char gc() { return _A == _B && (_B = (_A = Buf) + fread(Buf, 1, 1 << 21, stdin), _A == _B) ? EOF : *_A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
int n, m, K, bic, walk;
int dis[21][N], a[N], P[N];
double f[(1 << 18) + 55][21];
struct Edge{
    int v, nxt, w;
}e[M << 1];
int head[N];
struct Node{
    int v, d;
    inline bool operator<(const Node&t)const{
        return d > t.d;
    }
};
priority_queue<Node> q;

inline void adde(int from, int to, int w){
    static int et = 0;
    e[++et] = (Edge){to, head[from], w};
    head[from] = et;
}

void Dijkstra(int k, int s){
    rep(i, 1, n) dis[k][i] = inf;
    dis[k][s] = 0;
    q.push({s, 0});
    while(!q.empty()){
        Node qu = q.top(); q.pop();
        int now = qu.v;
        if(dis[k][now] != qu.d) continue;
        ee(i, now){
            int v = e[i].v;
            if(dis[k][now] + e[i].w < dis[k][v]){
                dis[k][v] = dis[k][now] + e[i].w;
                q.push({v, dis[k][v]});
            }
        }
    }
}

signed main() {
#ifdef LRL52
	freopen("G.in", "r", stdin);
#endif
	rd(walk), rd(bic);
    rd(n), rd(m); int x, y, z;
    rep(i, 1, m){
        rd(x), rd(y), rd(z);
        adde(x, y, z);
        adde(y, x, z);
    }
    rd(K);
    for(int i = 0; i < K; ++i)
        rd(a[i]), rd(P[i]);
    for(int i = 0; i < K; ++i)
        Dijkstra(i, a[i]);
    int S = K, T = K + 1;
    Dijkstra(S, 1);
    //Dijkstra(T, n);
    for(int s = (1 << K) - 1; s >= 1; --s){
        for(int i = 0; i < K; ++i){
            f[s][i] = 1e18;
            if((s >> i & 1) == 0) continue;
            double p = (100 - P[i]) / 100.0;
            if(dis[i][n] == inf) continue;
            f[s][i] = min(f[s][i], p * dis[i][n] / bic + (1.0 - p) * dis[i][n] / walk);
            for(int j = 0; j < K; ++j){
                if(s >> j & 1) continue;
                int ns = s | (1 << j);
                if(dis[i][a[j]] < inf && f[ns][j] < 1e16)
                    f[s][i] = min(f[s][i], p * dis[i][n] / bic + (1.0 - p) * ((double)dis[i][a[j]] / walk + f[ns][j]));
            }
        }
    }
    if(dis[S][n] == inf){
        puts("-1");
        return 0;
    }
    double ans = (double)dis[S][n] / walk;
    for(int i = 0; i < K; ++i)
        ans = min(ans, (double)dis[S][a[i]] / walk + f[1 << i][i]);
    printf("%.6lf\n", ans);
	return 0;
}