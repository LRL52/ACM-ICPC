//ID: LRL52  Date: 2022.7.17
//Atcoder 12连续AC就此打破
//誒，考试第一次复杂度算错了，T了，之后想出正解没时间写了
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 4e5 + 55, M = 3e5 + 55, inf = 0x3f3f3f3f; char Buf[1 << 21], *_A = Buf, *_B = Buf, cc;
inline char gc() { return _A == _B && (_B = (_A = Buf) + fread(Buf, 1, 1 << 21, stdin), _A == _B) ? EOF : *_A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
int S, T, m, vis[N];
struct Edge{
    int v, nxt;
}e[M << 1];
//map<int, int> G[N];
int head[N];
//vector<pair<int, int> > G[N];
vector<int> G[N];

inline void adde(int from, int to){
    static int et = 0;
    e[++et] = (Edge){to, head[from]};
    head[from] = et;
}

signed main() {
#ifdef LRL52
	freopen("F.in", "r", stdin);
#endif
	rd(S), rd(T), rd(m); int x, y;
    rep(i, 1, m){
        rd(x), rd(y);
        adde(y, x);
    }
    for(int i = S + 1; i <= S + T; ++i){
        /*ee(j, i){
            int v = e[j].v;
            vis[v] = i;
        }
        for(int j = i + 1; j <= S + T; ++j){
            int cnt = 0, v1 = 0, v2 = 0;
            ee(k, j){
                int v = e[k].v;
                if(vis[v] == i){
                    if(cnt == 0) ++cnt, v1 = v;
                    else if(cnt == 1){
                        v2 = v;
                        printf("%d %d %d %d\n", i, v1, j, v2);
                        return 0;
                    }
                }
            }
        }*/
        rep(j, S + 1, S + T) vis[j] = 0;
        ee(j, i){
            int v = e[j].v;
            for(int k = 0; k < G[v].size(); ++k){
                int x = G[v][k];
                if(!vis[x]){
                    vis[x] = v;
                } else{
                    printf("%d %d %d %d\n", x, vis[x], i, v);
                    return 0;
                }
            }
            G[v].push_back(i);
        }
    }
    puts("-1");
	return 0;
}