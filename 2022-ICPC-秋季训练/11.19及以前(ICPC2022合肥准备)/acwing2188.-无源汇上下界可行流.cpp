//ID: LRL52  Date: 2022.11.14
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
const int N = 1e3 + 55, M = (N * 2 + 10255), inf = 0x3f3f3f3f;
int n, S, T, et, Fee, m;
int head[N], vis[N], dis[N], cur[N], inq[N], c[N], L[M], R[M], id[M];
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

void Adde(int from, int to, int w) {
    static int cnt = 0;
    id[++cnt] = et + 1; //第i条正向边的编号，便于输出答案
    adde(from, to, w, 1);
    adde(to, from, 0, -1);
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n >> m; et = 1, S = 0, T = n + 1;
    int S_out = 0, Flow = 0, x, y;
    rep(i, 1, m) {
        cin >> x >> y >> L[i] >> R[i];
        Adde(x, y, R[i] - L[i]);
        c[x] -= L[i], c[y] += L[i];
    }
    rep(i, 1, n)
        if(c[i] > 0) Adde(S, i, c[i]), S_out += c[i];
        else if(c[i] < 0) Adde(i, T, -c[i]);
    while(SPFA()) {
        rep(i, S, T) cur[i] = head[i];
        Flow += max_flow(S, inf);
    }
    if(Flow != S_out) puts("NO");
    else {
        puts("YES");
        rep(i, 1, m) printf("%d\n", L[i] + e[id[i] ^ 1].w); //id[i]^1得到反向边(残量网络边的编号)
    }
	return 0;
} 