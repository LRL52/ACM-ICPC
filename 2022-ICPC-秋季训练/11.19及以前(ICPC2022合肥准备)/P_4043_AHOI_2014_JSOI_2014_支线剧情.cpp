//ID: LRL52  Date: 2022.11.19
//有源上下界最小费用可行流
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
const int N = 355 + 55, M = 6e3 + 55, inf = 0x3f3f3f3f;
int n, S, T, et; long long Fee;
int head[N], vis[N], dis[N], cur[N], inq[N], c[N];
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

signed main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n; et = 1, S = 0, T = n + 2;
    int S_out = 0, Flow = 0, x, y, z;
    rep(i, 1, n) {
        cin >> z;
        rep(j, 1, z) {
            cin >> x >> y;
            Adde(i, x, inf, y);
            c[i]--, c[x]++, Fee += y;
        }
    }
    rep(i, 1, n) {
        if(c[i] > 0) Adde(S, i, c[i], 0), S_out += c[i];
        else if(c[i] < 0) Adde(i, T, -c[i], 0);
    }
    rep(i, 2, n) Adde(i, n + 1, inf, 0); //n+1作为一个虚拟汇点，收集流量，再流回1，保证流量守恒
    Adde(n + 1, 1, inf, 0);
    while(SPFA()) {
        rep(i, S, T) cur[i] = head[i];
        Flow += max_flow(S, inf);
    }
    assert(Flow == S_out);
    printf("%lld\n", Fee);
	return 0;
} 