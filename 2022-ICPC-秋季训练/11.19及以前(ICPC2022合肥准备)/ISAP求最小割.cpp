//ID: LRL52  Date: 2022.11.15
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 10000 + 55, M = 100000 + 55, inf = 0x3f3f3f3f;
int n, S, T, et, m;
int head[N], vis[N], dis[N], cur[N], inq[N];
struct Edge {
    int v, nxt, w;
}e[M << 1];
queue<int> q;

inline void adde(int from, int to, int w) {
    e[++et] = (Edge){to, head[from], w};
    head[from] = et;
}

int BFS() {
    memset(dis, -1, sizeof(dis));
    dis[S] = 0; q.push(S);
    while (!q.empty()) {
        int now = q.front();
        q.pop();
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

int max_flow(int x,int flow){
    if(x == T) return flow;
    int t = flow;
    for(int &i = cur[x]; i; i = e[i].nxt) {
        int v = e[i].v;
        if(dis[v] == dis[x] + 1) {
            int dx = max_flow(v, min(flow, e[i].w));
            e[i].w -= dx; e[i ^ 1].w += dx;
            flow -= dx;
            if(flow == 0) break;
        }
    }
    return t - flow;
}

void Adde(int from, int to, int w) {
    adde(from, to, w);
    adde(to, from, 0);
}

int Dinic() {
    int ret = 0;
    while(BFS()) {
        rep(i, 1, n) cur[i] = head[i];
        ret += max_flow(S, inf);
    }
    return ret;
}


signed main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n >> m >> S >> T ; et = 1;
    int x, y, z;
    for(int i = 1; i <= m; ++i) {
        cin >> x >> y >> z;
        Adde(x, y, z);
    }
    int ans = Dinic();
    printf("%d\n", ans);
	return 0;
} 