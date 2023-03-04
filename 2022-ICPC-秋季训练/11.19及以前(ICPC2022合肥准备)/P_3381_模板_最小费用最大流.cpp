//ID: LRL52  Date: 2022.11.15
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
const int N = 5e3 + 55, M = 5e4 + 55, inf = 0x3f3f3f3f;
int n, S, T, et, m, Fee;
int head[N], vis[N], dis[N], cur[N], inq[N];
struct Edge {
    int v, nxt, w, fee;
}e[M << 1];
deque<int> q;

inline void adde(int from, int to, int w, int fee) {
    e[++et] = (Edge){to, head[from], w, fee};
    head[from] = et;
}
int SPFA() {
    memset(dis, 0x3f, sizeof(dis));
    dis[S] = 0; q.push_front(S);
    while(!q.empty()) {
        auto now = q.front(); q.pop_front();
        inq[now] = 0;
        for(int i = head[now]; i; i = e[i].nxt) {
            int v = e[i].v;
            if(e[i].w > 0 && dis[now] + e[i].fee < dis[v]) {
                dis[v] = dis[now] + e[i].fee;
                if(!inq[v]) {
                    inq[v] = 1;
                    if(!q.empty() && dis[v] <= dis[q.front()]) q.push_front(v);
                    else q.push_back(v);
                }
            }
        }
    }
    return dis[T] != inf;
}

int max_flow(int now, int flow) {
    if(now == T) return flow;
    int t = flow; vis[now] = 1;
    for(int &i = cur[now]; i; i = e[i].nxt) {
        int v = e[i].v;
        if(!vis[v] && e[i].w > 0 && dis[now] + e[i].fee == dis[v]) {
            int dx = max_flow(v, min(flow, e[i].w));
            flow -= dx, e[i].w -= dx;
            e[i ^ 1].w += dx;
            Fee += dx * e[i].fee;
            if(flow == 0) break;
        }
    }
    vis[now] = 0;
    return t - flow;
}

void Adde(int from, int to, int w, int fee) {
    adde(from, to, w, fee);
    adde(to, from, 0, -fee);
}

int Dinic() {
    int ret = 0;
    while(SPFA()) {
        rep(i, 1, n) cur[i] = head[i];
        ret += max_flow(S, inf);
    }
    return ret;
}


signed main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n >> m >> S >> T ; et = 1;
    int x, y, z, w;
    for(int i = 1; i <= m; ++i) {
        cin >> x >> y >> z >> w;
        Adde(x, y, z, w);
    }
    int ans = Dinic();
    printf("%d %d\n", ans, Fee);
	return 0;
} 