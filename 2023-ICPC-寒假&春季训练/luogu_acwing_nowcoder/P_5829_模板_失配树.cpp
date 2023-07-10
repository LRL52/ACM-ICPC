/*** 
 * @Author: LRL52
 * @Date: 2023-03-27 20:36:54
 * @LastEditTime: 2023-03-27 21:58:24
 */
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
using i64 = long long;
using pii = pair<int, int>;
const int N = 1e6 + 55, inf = 0x3f3f3f3f;
char s[N];
int Nxt[N], fa[N], Size[N], Top[N], dep[N];

struct Edge{
    int v, nxt;
}e[N << 1];
int head[N];

inline void adde(int from, int to){
    static int et = 0;
    e[++et] = (Edge){to, head[from]};
    head[from] = et;
}

void dfs(int x) {
    Size[x] = 1, Top[x] = x;
    int maxs = 0, tson = 0;
    for(int i = head[x]; i; i = e[i].nxt) {
        int v = e[i].v;
        if(v == fa[x]) continue;
        fa[v] = x, dep[v] = dep[x] + 1;
        dfs(v);
        Size[x] += Size[v];
        if(Size[v] > maxs) {
            maxs = Size[v];
            tson = v;
        }
    }
    if(tson) Top[tson] = x;
}

int find(int x) { return Top[x] == x ? x : Top[x] = find(Top[x]); }

int LCA(int x, int y) {
    while(find(x) != find(y)) {
        if(dep[Top[x]] < dep[Top[y]]) swap(x, y);
        x = fa[Top[x]];
    }
    return dep[x] < dep[y] ? x : y;
}

signed main() {
#ifdef LRL52
	freopen("P5829_1.in", "r", stdin);
#endif
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> (s + 1);
    //求next数组
    int n = strlen(s + 1);
    Nxt[1] = 0;
    for(int i = 2, j = 0; i <= n; ++i) {
        while(j > 0 && s[j + 1] != s[i]) j = Nxt[j];
        if(s[j + 1] == s[i]) ++j;
        Nxt[i] = j; 
        // cout << "Nxt[" << i << "] = " << Nxt[i] << '\n';
    } 
    //n+1个点, n条边的border树
    for(int i = 1; i <= n; ++i)
        adde(i, Nxt[i]), adde(Nxt[i], i);
    //LCA预处理
    dfs(0);
    //处理询问
    int m; cin >> m;
    for(int i = 1; i <= m; ++i) {
        int x, y;
        cin >> x >> y;
        x = fa[x], y = fa[y];
        // cout << "x = " << x << " y = " << y << '\n';
        cout << LCA(x, y) << '\n';
    }
	return 0;
}