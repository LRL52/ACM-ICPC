//ID: LRL52  Date: 2022.7.9
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 2e5 + 55, M = 2e5 + 55; char ss[1 << 21], * A = ss, * B = ss, cc;
inline char gc() { return A == B && (B = (A = ss) + fread(ss, 1, 1 << 21, stdin), A == B) ? EOF : *A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
int n, m, sts;
int head[N], vis[N], pre[N];
struct Edge{
    int v, nxt;
}e[M];
vector<int> Ans;

inline void adde(int from, int to){
    static int et = 0;
    e[++et] = (Edge){to, head[from]};
    head[from] = et;
}

void getans(int x){
    if(x == 0) return;
    getans(pre[x]);
    Ans.push_back(x);
}

void printans(int x, int v){
    puts("Possible");
    getans(v);
    printf("%d\n", Ans.size());
    for(int j = 0; j < Ans.size(); ++j)
        printf("%d ", Ans[j]);
    putchar('\n');
    Ans.clear();
    getans(x);
    Ans.push_back(v);
    printf("%d\n", Ans.size());
    for(int j = 0; j < Ans.size(); ++j)
        printf("%d ", Ans[j]);
    putchar('\n');
    exit(0);
}
void dfs(int x, int col){
    vis[x] = col;
    ee(i, x){
        int v = e[i].v;
        if(v == sts) continue;
        if(!vis[v]){
            pre[v] = x;
            dfs(v, col);
        }
        else if(vis[v] == col) continue;
        else{
            printans(x, v);
        }
    }
}

        

int main() {
#ifdef LRL52
	freopen("D.in", "r", stdin);
#endif
	rd(n), rd(m), rd(sts); int x, y;
    rep(i, 1, m){
        rd(x), rd(y);
        adde(x, y);
    }
    int co = 0;
    ee(i, sts){
        int v = e[i].v;
        if(!vis[v]){
            pre[v] = sts;
            dfs(v, ++co);
        } else{
            printans(sts, v);
        }
    }
    puts("Impossible");
	return 0;
}
