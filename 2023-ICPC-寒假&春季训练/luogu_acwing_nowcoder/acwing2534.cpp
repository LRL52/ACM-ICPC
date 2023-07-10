//ID: LRL52  Date: 2023.1.15
//树上莫队模板题
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
const int N = 40000 + 55, M = 1e5 + 55, inf = 0x3f3f3f3f;
int n, m, tt, ans, seq[N << 1], a[N], first[N], last[N], status[N], Cnt[N];
int DFN, dep[N], fa[N], Top[N], Size[N], Ans[M];
vector<int> val;
struct Edge{
    int v, nxt;
}e[N << 1];
struct Query {
    int id, l, r, lca; //lca非0表示需要再添加lca进入最后的序列
}Q[M];
int head[N];

inline void adde(int from, int to){
    static int et = 0;
    e[++et] = (Edge){to, head[from]};
    head[from] = et;
}

void dfs(int x) {
    first[x] = ++DFN, seq[DFN] = x;
    Top[x] = x, Size[x] = 1; 
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
    last[x] = ++DFN, seq[DFN] = x;
}

int find(int x) { return Top[x] == x ? x : Top[x] = find(Top[x]); }

int LCA(int x, int y) {
    while(find(x) != find(y)) {
        if(dep[Top[x]] < dep[Top[y]]) swap(x, y);
        x = fa[Top[x]];
    }
    return dep[x] < dep[y] ? x : y;
}

void add(int x) {
    status[x] ^= 1; int col = a[x];
    if(status[x]) {
        if(!Cnt[col]) ++ans;
        ++Cnt[col];
    } else {
        --Cnt[col];
        if(!Cnt[col]) --ans;
    }
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n >> m; int x, y;
    rep(i, 1, n) cin >> a[i], val.push_back(a[i]);
    rep(i, 1, n - 1) {
        cin >> x >> y;
        adde(x, y), adde(y, x);
    }
    sort(val.begin(), val.end());
    val.erase(unique(val.begin(), val.end()), val.end());
    rep(i, 1, n) a[i] = lower_bound(val.begin(), val.end(), a[i]) - val.begin();
    dfs(1);
    // tt = sqrt(n);
    tt = max(int(2 * n / sqrt(m)), 1);
    rep(i, 1, m) {
        cin >> x >> y;
        if(first[x] > first[y]) swap(x, y); //注意这里
        int lca = LCA(x, y);
        if(lca == x) Q[i] = { i, first[x], first[y], 0 };
        else Q[i] = { i, last[x], first[y], lca };
    }
    auto cmp = [](const Query &t1, const Query &t2)->bool {
        auto al = t1.l / tt, bl = t2.l / tt;
        if(al != bl) return al < bl;
        return t1.r < t2.r;
    };
    sort(Q + 1, Q + m + 1, cmp);
    x = 1, y = 0;
    rep(i, 1, m) {
        int l = Q[i].l, r = Q[i].r, id = Q[i].id, lca = Q[i].lca;
        while(y < r) add(seq[++y]);
        while(y > r) add(seq[y--]);
        while(x < l) add(seq[x++]);
        while(x > l) add(seq[--x]);
        if(lca) add(lca);
        Ans[id] = ans;
        if(lca) add(lca);
    }
    rep(i, 1, m) printf("%d\n", Ans[i]);
	return 0;
}