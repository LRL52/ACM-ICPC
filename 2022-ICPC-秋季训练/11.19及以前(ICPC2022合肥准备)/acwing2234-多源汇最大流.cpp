//ID: LRL52  Date: 2022.11.15
//只跑最大流还是用最大流的板子快一点
#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 10000 + 55, M = N * 2 + 100055, inf = 0x3f3f3f3f;
int n, S, T, et, Fee, m;
int head[N], vis[N], dis[N], cur[N], inq[N];
struct Edge {
    int v, nxt, w, fee;
}e[M << 1];
// deque<int> q;
queue<int> q;

inline void adde(int from, int to, int w, int fee) {
    e[++et] = (Edge){to, head[from], w, fee};
    head[from] = et;
}

// int SPFA() {
//     memset(dis, 0x3f, sizeof(dis));
//     dis[S] = 0; q.push_front(S);
//     while(!q.empty()) {
//         auto now = q.front(); q.pop_front();
//         inq[now] = 0;
//         for(int i = head[now]; i; i = e[i].nxt) {
//             int v = e[i].v;
//             if(e[i].w > 0 && dis[now] + e[i].fee < dis[v]) {
//                 dis[v] = dis[now] + e[i].fee;
//                 if(!inq[v]) {
//                     inq[v] = 1;
//                     if(!q.empty() && dis[v] <= dis[q.front()]) q.push_front(v);
//                     else q.push_back(v);
//                 }
//             }
//         }
//     }
//     return dis[T] != inf;
// }

// int max_flow(int now, int flow) {
//     if(now == T) return flow;
//     int t = flow; vis[now] = 1;
//     for(int &i = cur[now]; i; i = e[i].nxt) {
//         int v = e[i].v;
//         if(!vis[v] && e[i].w > 0 && dis[now] + e[i].fee == dis[v]) {
//             int dx = max_flow(v, min(flow, e[i].w));
//             flow -= dx, e[i].w -= dx;
//             e[i ^ 1].w += dx;
//             Fee += dx * e[i].fee;
//             if(flow == 0) break;
//         }
//     }
//     vis[now] = 0;
//     return t - flow;
// }

int BFS(){
	memset(dis,-1,sizeof(dis));
	dis[S]=0;q.push(S);
	while(!q.empty()){
		int now=q.front();q.pop();
		ee(i,now){
			int v=e[i].v;
			if(dis[v]==-1&&e[i].w>0){
				dis[v]=dis[now]+1;
				q.push(v);
			} 
		}
	} 
	return dis[T]!=-1;
}

int max_flow(int x,int flow){
	if(x==T)return flow;
	int tf=flow;
	for(int &i=cur[x];i;i=e[i].nxt){
		int v=e[i].v;
		if(dis[v]==dis[x]+1){
			int dx=max_flow(v,min(tf,e[i].w));
			e[i].w-=dx;e[i^1].w+=dx;
			tf-=dx;
			if(tf==0)break;
		}
	}
	return flow-tf;
}

void Adde(int from, int to, int w) {
    adde(from, to, w, 1);
    adde(to, from, 0, -1);
}

int Dinic() {
    int ret = 0;
    while(BFS()) {
        rep(i, S, T) cur[i] = head[i];
        ret += max_flow(S, inf);
    }
    return ret;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
    int Sc, Tc;
	cin >> n >> m >> Sc >>Tc; et = 1, S = 0, T = n + 1;
    int x, y, z;
    rep(i, 1, Sc) {
        cin >> x;
        Adde(S, x, inf);
    }
    rep(i, 1, Tc) {
        cin >> x;
        Adde(x, T, inf);
    }
    rep(i, 1, m) {
        cin >> x >> y >> z;
        Adde(x, y, z);
    }
    printf("%d\n", Dinic());
	return 0;
} 