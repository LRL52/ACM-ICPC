//ID: LRL52  Date: 2023.2.10
//很有意思的Dij，多起点的Dij
//建图不难想到，考虑一个结点最早什么时候能有1到达，这是一个多起点的最短路，距离需要特殊定义
//这里的距离是用二元组(i, j)来定义的，i表示需要多少整数轮, j表示i轮后还需要多少次操作
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
using i64 = long long;
using pii = pair<int, int>;
const int N = (1 << 18) + 55, inf = 0x3f3f3f3f;
int n, L, X[N], head[N], Ans[N];
pii dis[N];
i64 T;
struct Edge{
    int v, nxt, w;
}e[N << 1];
struct Node {
    int v; pii d;
    friend bool operator<(const Node &t1, const Node &t2) {
        return t1.d > t2.d;
    }
};

pii operator+(const pii &t, int w) {
    pii ret = {t.first, w};
    if(w < t.second) ret.first++;
    if(ret.second == L) ret.first++, ret.second = 0;
    return ret;
}

inline void adde(int from, int to, int w){
    static int et = 0;
    e[++et] = (Edge){to, head[from], w};
    head[from] = et;
}

void Dijkstra(vector<int> &start) {
    rep(i, 1, n) dis[i] = {inf, inf};
    priority_queue<Node> q;
    for(auto s : start) {
        dis[s] = {0, 0};
        q.push({s, {0, 0}});
    }
    while(!q.empty()) {
        auto [now, d] = q.top(); q.pop();
        if(dis[now] != d) continue;
        for(int i = head[now]; i; i = e[i].nxt) {
            int v = e[i].v, w = e[i].w;
            if(dis[now] + e[i].w < dis[v]) {
                dis[v] = dis[now] + e[i].w;
                q.push({v, dis[v]});
            }
        }
    }
}

signed main() {
#ifdef LRL52
	freopen("D.in", "r", stdin);
#endif
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n >> L >> T;
    rep(i, 1, L) {
        int x, y;
        cin >> x >> y;
        adde(y, x, i);
    }
    rep(i, 1, n) cin >> X[i];
    for(int k = 0; k < 8; ++k) {
        vector<int> start;
        rep(i, 1, n)
            if(X[i] >> k & 1)
                start.push_back(i);
        Dijkstra(start);
        pii lim = {T / L, T % L};
        rep(i, 1, n)
            if(dis[i] <= lim)
                Ans[i] |= 1 << k;
    }
    rep(i, 1, n)
        cout << Ans[i] << " \n"[i == n];
	return 0;
}