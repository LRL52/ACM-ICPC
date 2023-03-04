//ID: LRL52  Date: 2022.7.22
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 2e5 + 55, M = 2e5 + 55, inf = 0x3f3f3f3f; char Buf[1 << 21], *_A = Buf, *_B = Buf, cc;
inline char gc() { return _A == _B && (_B = (_A = Buf) + fread(Buf, 1, 1 << 21, stdin), _A == _B) ? EOF : *_A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
int n, m, Circle, f[N][2], instk[N][2], vis[N][2], upd[N], End[N][2];
struct Edge{
    int v, nxt;
}e[M << 1];
int head[N];

inline void adde(int from, int to){
    static int et = 0;
    e[++et] = (Edge){to, head[from]};
    head[from] = et;
}

/*void dfs(int x){
    instk[x] = vis[x] = 1; int flag = 0;
    ee(i, x){
        flag = 1;
        int v = e[i].v;
        if(!vis[v]){
            dfs(v);
        } else if(instk[v]) Circle = 1;
        if(!instk[v] && upd[v]){
            f[x][0] |= f[v][1];
            f[x][1] |= f[v][0];
            upd[x] = 1;
        }
    }
    if(!flag) f[x][0] = upd[x] = 1;
    instk[x] = 0;
}*/

void dfs(int x, int sta){
    f[x][sta] = instk[x][sta] = 1; int flag = 0;
    ee(i, x){
        flag = 1;
        int v = e[i].v;
        if(!f[v][sta ^ 1]){
            dfs(v, sta ^ 1);
        }
        else if(instk[v][sta ^ 1]) Circle = 1;
        End[x][sta] |= End[v][sta ^ 1];
    }
    if(!flag && sta == 1) End[x][sta] = 1;
    instk[x][sta] = 0;
    //printf("End[%d][%d] = %d\n", x, sta, End[x][sta]);
}

/*void getans(int x, int sta){
    instk[x] = 1; printf("%d ", x);
    ee(i, x){
        int v = e[i].v;
        if(!instk[v] && f[v][sta ^ 1]){
            getans(v, sta ^ 1);
            break;
        }
    }
    instk[x] = 0;
}*/

void getans(int x, int sta){
    vis[x][sta] = 1; printf("%d ", x);
    ee(i, x){
        int v = e[i].v;
        //printf("End[%d][%d] = %d vis[%d][%d] = %d\n", v, sta^1, End[v][sta^1], v, sta^1, vis[v][sta^1]);
        if(End[v][sta^1] && !vis[v][sta^1]){
            getans(v, sta^1);
            break;
        }
    }
}

signed main() {
#ifdef LRL52
	freopen("D.in", "r", stdin);
#endif
	rd(n), rd(m); int x;
    rep(i, 1, n){
        int cnt; rd(cnt);
        rep(j, 1, cnt){
            rd(x);
            adde(i, x);
        }
    }
    int sts; rd(sts);
    dfs(sts, 0);
    if(End[sts][0]){
        puts("Win");
        getans(sts, 0);
    } else
    if(Circle) puts("Draw");
    else puts("Lose");
	return 0;
}