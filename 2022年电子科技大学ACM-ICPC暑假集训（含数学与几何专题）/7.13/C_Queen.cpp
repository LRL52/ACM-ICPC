//ID: LRL52  Date: 2022.7.13
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 1e5 + 55; char ss[1 << 21], * A = ss, * B = ss, cc;
inline char gc() { return A == B && (B = (A = ss) + fread(ss, 1, 1 << 21, stdin), A == B) ? EOF : *A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
int n, root, head[N], c[N];
vector<int> Ans;
struct Edge{
    int v, nxt;
}e[N << 1];

inline void adde(int from, int to){
    static int et = 0;
    e[++et] = (Edge){to, head[from]};
    head[from] = et;
}

void dfs(int x){
    int ok = 1;
    ee(i, x){
        int v = e[i].v;
        if(c[v] == 0) ok = 0;
        dfs(v);
    }
    if(c[x] && ok) Ans.push_back(x);
}
        

int main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	rd(n); int x, y;
    rep(i, 1, n){
        rd(x), rd(c[i]);
        if(x != -1) adde(x, i);
        else root = i;
    }
    dfs(root);
    sort(Ans.begin(), Ans.end());
    if(Ans.size() == 0) puts("-1");
    else{
        for(int i = 0; i < Ans.size(); ++i)
            printf("%d ", Ans[i]);
    }
	return 0;
}
