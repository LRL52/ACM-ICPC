//ID: LRL52  Date: 2022.11.15
//0/1分数规划 + 无向图最小割
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
using LL = long long;
const int N = 1e3 + 55, M = 1e3 + 55, inf = (1LL << 31) - 1;
const double Eps = 1e-8;
int n, S, T, et, m;
int head[N], vis[N], dis[N], cur[N], inq[N], W[M << 1];
struct Edge {
    int v, nxt; double w;
}e[M << 1];
queue<int> q;

inline void adde(int from, int to, double w) {
    e[++et] = (Edge){to, head[from], w};
    head[from] = et;
}

int BFS() {
    memset(dis, -1, sizeof(dis));
    dis[S] = 0; q.push(S);
    while (!q.empty()) {
        int now = q.front(); q.pop();
        for(int i = head[now]; i; i = e[i].nxt) {
            int v = e[i].v;
            if (dis[v] == -1 && e[i].w > 0) {
                dis[v] = dis[now] + 1;
                q.push(v);
            }
        }
    }
    return dis[T] != -1;
}

double max_flow(int now,double flow){
    if(now == T) return flow;
    double t = flow;
    for(int &i = cur[now]; i; i = e[i].nxt) {
        int v = e[i].v;
        if(dis[v] == dis[now] + 1) {
            double dx = max_flow(v, min(flow, e[i].w));
            e[i].w -= dx; e[i ^ 1].w += dx;
            flow -= dx;
            if(flow == 0) break;
        }
    }
    return t - flow;
}

void Adde(int from, int to, double w) {
    adde(from, to, w);
    adde(to, from, 0);
}

double Dinic() {
    auto ret = 0.0;
    while(BFS()) {
        rep(i, 1, n) cur[i] = head[i];
        ret += max_flow(S, inf);
    }
    return ret;
}

int check(double K) {
    double res = 0.0;
    for(int i = 2; i < et; i += 2) {
        int j = i >> 1;
        if(W[j] - K <= 0.0)
            e[i].w = e[i ^ 1].w = 0, res += W[j] - K;
        else
            e[i].w = e[i ^ 1].w = W[j] - K; //无向边建图，正向边和反向边初始流量相同
    }
    res += Dinic();
    return res <= 0.0;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n >> m >> S >> T ; et = 1;
    int x, y, z;
    for(int i = 1; i <= m; ++i) {
        cin >> x >> y >> z;
        Adde(x, y, z);
        W[i] = z;
    }
    double l = 0.0, r = 1e7;
    while(r - l > Eps) {
        double mid = (l + r) / 2.0;
        if(check(mid)) r = mid;
        else l = mid;
    }
    printf("%.2lf\n", l);
	return 0;
} 