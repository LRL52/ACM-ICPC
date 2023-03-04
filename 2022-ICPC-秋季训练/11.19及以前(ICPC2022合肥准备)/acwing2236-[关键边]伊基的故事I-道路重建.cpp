//ID: LRL52  Date: 2022.11.15
//POJ上过了，但我觉得yxc的代码有问题，Acwing上过不了
//#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <queue>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 500 + 55, M = 5000 + 55, inf = 0x3f3f3f3f;
int n, S, T, et, Fee, m;
int head[N], vis[N], dis[N], cur[N], inq[N], vis_s[N], vis_t[N];
struct Edge {
    int v, nxt, w;
}e[M << 1];
queue<int> q;

inline void adde(int from, int to, int w) {
    //e[++et] = (Edge){to, head[from], w};
    e[++et].v = to, e[et].nxt = head[from], e[et].w = w;
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
        rep(i, S, T) cur[i] = head[i];
        ret += max_flow(S, inf);
    }
    return ret;
}

void dfs(int x, int* vis, int sign) {
    vis[x] = 1;
    for(int i = head[x]; i; i = e[i].nxt) {
        if((i & 1) != sign) continue;
        int v = e[i].v;
        if(!vis[v] && e[i ^ sign].w > 0)
            dfs(v, vis, sign);
    }
}

signed main() {
    freopen("acwing2356.in", "r", stdin);
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m; et = 1, S = 0, T = n - 1;
    int x, y, z;
    for(int i = 0; i < m; ++i) {
        cin >> x >> y >> z;
        Adde(x, y, z);
    }
    Dinic();
    dfs(S, vis_s, 0);
    dfs(T, vis_t, 1);
    int ans = 0;
    for(int i = 2; i < et; i += 2)
        if(e[i].w == 0 && vis_s[e[i ^ 1].v] && vis_t[e[i].v])
            ++ans;
    printf("%d\n", ans);
	return 0;
} 