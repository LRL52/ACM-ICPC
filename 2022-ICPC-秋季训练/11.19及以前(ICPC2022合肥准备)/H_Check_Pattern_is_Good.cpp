//ID: LRL52  Date: 2022.11.16
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
using LL = long long;
const int N = (1e4 + 55) * 2, M = 1e4 * 12 + 55, inf = 0x3f3f3f3f;
int n, S, T, et, m;
int head[N], vis[N], dis[N], cur[N], inq[N], vis_s[N], Ans[N];
char s[155][155];
//pair<int, int> Id[N];
struct Edge {
    int v, nxt, w;
}e[M << 1];
queue<int> q;

inline void adde(int from, int to, int w) {
    e[++et] = (Edge){to, head[from], w};
    head[from] = et;
}

int BFS() {
    //memset(dis, -1, sizeof(dis));
    rep(i, S, T) dis[i] = -1;
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

int max_flow(int now,int flow){
    if(now == T) return flow;
    int t = flow;
    for(int &i = cur[now]; i; i = e[i].nxt) {
        int v = e[i].v;
        if(dis[v] == dis[now] + 1) {
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

void dfs(int now, vector<int>& S1) {
    vis_s[now] = 1;
    S1.push_back(now);
    for(int i = head[now]; i; i = e[i].nxt) {
        int v = e[i].v;
        if(!vis_s[v] && e[i].w > 0)
            dfs(v, S1);
    }
}

signed main() {
    freopen("H.in", "r", stdin);
	ios::sync_with_stdio(false); cin.tie(nullptr);
	int Task; cin >> Task;
    while(Task--) {
        cin >> n >> m;
        rep(i, 1, n) cin >> (s[i] + 1);
        auto Rev = [](char c)->char { return c == 'B' ? 'W' : 'B'; };
        rep(i, 1, n)
            rep(j, 1, m) {
                if((i + j) % 2 == 1 && s[i][j] != '?')
                    s[i][j] = Rev(s[i][j]);
            }
        auto getid = [](int i, int j)->int { return (i - 1) * m + j; };
        S = 0, T = 2 * n * m + 1, et = 1;
        memset(head, 0, sizeof(head));
        //建图，左部(1~n*m)表示染成黑色，右部(n*m+1~2*n*m)表示染成白色
        for(int i = 1; i < n; ++i) {
            for(int j = 1; j < m; ++j) {
                auto now = getid(i, j);
                //Id[now] = make_pair(i, j);
                if(i > 1 && j > 1) Adde(now, getid(i - 1, j - 1) + n*m, inf);
                if(i > 1) Adde(now, getid(i - 1, j) + n*m, inf);
                if(i > 1 && j + 1 < m) Adde(now, getid(i - 1, j + 1) + n*m, inf);
                if(j > 1) Adde(now, getid(i, j - 1) + n*m, inf);
                Adde(now, getid(i, j) + n*m, inf);
                if(j + 1 < m) Adde(now, getid(i, j + 1) + n*m, inf);
                if(i + 1 < n && j > 1) Adde(now, getid(i + 1, j - 1) + n*m, inf);
                if(i + 1 < n) Adde(now, getid(i + 1, j) + n*m, inf);
                if(i + 1 < n && j + 1 < m) Adde(now, getid(i + 1, j + 1) + n*m, inf);
            }
        }
        auto check_no = [](int i, int j, char c)->int { return s[i][j] != c && s[i + 1][j] != c && s[i][j + 1] != c && s[i + 1][j + 1] != c; };
        int tot = 0;
        for(int i = 1; i < n; ++i) {
            for(int j = 1; j < m; ++j) {
                if(check_no(i, j, 'W'))
                    Adde(S, getid(i, j), 1), ++tot;
                else
                    Adde(S, getid(i, j), 0);
                if(check_no(i, j, 'B'))
                    Adde(getid(i, j) + n*m, T, 1), ++tot;
                else
                    Adde(getid(i, j) + n*m, T, 0);
            }
        }
        int ans = tot - Dinic();
        //下面开始构造(最小割的)一个解
        memset(vis_s, 0, sizeof(vis_s));
        memset(Ans, 0, sizeof(Ans));
        vector<int> S1; //残量网络上起点能到达的集合
        dfs(S, S1);
        for(auto x : S1) {
            for(int i = head[x]; i; i = e[i].nxt) {
                int v = e[i].v;
                if(!vis_s[v]) {
                    if(v <= n * m) Ans[v] = 1; //注意，这是最小点覆盖的解，还需要取补集才是最大独立集的解
                    else if(x > n * m) Ans[x] = 1;
                }
            }
        }
        rep(i, 1, 2 * n * m) Ans[i] = !Ans[i];
        for(int i = 1; i < n; ++i) {
            for(int j = 1; j < m; ++j) {
                auto now = getid(i, j);
                if(Ans[now] && check_no(i, j, 'W')) 
                    s[i][j] = s[i + 1][j] = s[i][j + 1] = s[i + 1][j + 1] = 'B';
                else if(Ans[now + n * m] && check_no(i, j, 'B')) 
                    s[i][j] = s[i + 1][j] = s[i][j + 1] = s[i + 1][j + 1] = 'W';
            }
        }
        rep(i, 1, n)
            rep(j, 1, m) {
                if((i + j) % 2 == 1) //复原被取反的格子
                    s[i][j] = Rev(s[i][j]);
                if(s[i][j] == '?') s[i][j] = 'B'; //把还有'?'的随便赋上答案就行了
            }
        printf("%d\n", ans);
        rep(i, 1, n) puts(s[i] + 1);
    }
	return 0;
} 
    