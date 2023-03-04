//ID: LRL52  Date: 2022.10.6
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 2e3 + 55; char Buf[1 << 21], *_A = Buf, *_B = Buf, cc;
inline char gc() { return _A == _B && (_B = (_A = Buf) + fread(Buf, 1, 1 << 21, stdin), _A == _B) ? EOF : *_A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
long long Ans;
int n, dis[N], vis[N];
char s[N][N];
queue<int> q;
vector<int> G[N];
bitset<N> B[N], B_[N], V;

void BFS(int st) {
    //set<int> V; vector<int> T;
    rep(i, 1, n) dis[i] = n, vis[i] = 0, V[i] = 1, B[i] = B_[i]/*, V.insert(i)*/;
    dis[st] = 0, vis[st] = 1, V[st] = 0;
    q.push(st); //V.erase(st);
    // rep(i, 1, n) rep(j, 1, n) if(s[i][j] == '1') B[i][j] = 1;
    while(!q.empty()) {
        auto now = q.front(); q.pop();
        // if(G[now].size() <= V.size()) {
        //     for(auto &v : G[now]) {
        //         if(!vis[v] && s[now][v] == '1') {
        //             dis[v] = dis[now] + 1;
        //             vis[v] = 1; q.push(v);
        //             V.erase(v);
        //         }
        //     }
        // } else {
        //     for(auto &v : V) {
        //         if(!vis[v] && s[now][v] == '1') {
        //             dis[v] = dis[now] + 1;
        //             vis[v] = 1; q.push(v);
        //             //V.erase(v);
        //             T.push_back(v);
        //         }
        //     }
        //     for(auto &v : T) V.erase(v);
        // }
        B[now] = B[now] & V;
        for(int i = B[now]._Find_first(); i != B[now].size(); i = B[now]._Find_next(i)) {
            int v = i;
            if(!vis[v]) {
                dis[v] = dis[now] + 1;
                vis[v] = 1; q.push(v);
                V[v] = 0;
            }
        }
    }
    rep(i, 1, n) Ans += dis[i] * dis[i];
}
        

signed main() {
#ifdef LRL52
	freopen("B.in", "r", stdin);
#endif
	scanf("%d", &n);
    rep(i, 1, n) {
        scanf("%s", s[i] + 1);
        rep(j, 1, n)
            if(s[i][j] == '1') G[i].push_back(j), B_[i][j] = 1;
    }
    rep(i, 1, n) BFS(i);
    printf("%lld\n", Ans);
	return 0;
}