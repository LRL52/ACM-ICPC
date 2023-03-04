//ID: LRL52  Date: 2022.7.21
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 1e3 + 55, M = 1e4 + 55, inf = 0x3f3f3f3f; char Buf[1 << 21], *_A = Buf, *_B = Buf, cc;
inline char gc() { return _A == _B && (_B = (_A = Buf) + fread(Buf, 1, 1 << 21, stdin), _A == _B) ? EOF : *_A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
int n, m, OK, Ans[N];
vector<int> blo;
struct Edge{
    int v, nxt, w;
}e[M << 1];
int head[N];

inline void adde(int from, int to, int w){
    static int et = 0;
    e[++et] = (Edge){to, head[from], w};
    head[from] = et;
}

void dfs(int x, int sta){
    Ans[x] = sta; blo.push_back(sta);
    ee(i, x){
        int v = e[i].v, w = e[i].w;
        if(Ans[v] == -1) {
            dfs(v, 1 ^ sta ^ w);
            if(!OK) return;
        } else
        if(Ans[v] != (1 ^ sta ^ w)){
            OK = 0;
            return;
        }
    }
}

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	rd(n), rd(m); int x, y, z;
    rep(i, 1, m){
        rd(x), rd(y), rd(z);
        adde(x, y, z), adde(y, x, z);
    }
    memset(Ans, -1, sizeof(Ans));
    rep(i, 1, n){
        if(Ans[i] != -1) continue;
        blo.clear(); OK = 1;
        dfs(i, 0);
        if(OK) continue;
        for(int j = 0; j < blo.size(); ++j){
            int v = blo[j];
            Ans[v] = -1;
        }
        OK = 1; blo.clear();
        dfs(i, 1);
        if(!OK){
            puts("Impossible");
            return 0;
        }
    }
    int ans = 0;
    rep(i, 1, n) ans += Ans[i];
    printf("%d\n", ans);
    rep(i, 1, n){
        if(Ans[i])
            printf("%d ", i);
    }
	return 0;
}