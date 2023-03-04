//ID: LRL52  Date: 2022.10.28
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5, inf = 0x3f3f3f3f;
int n;
int b[N];
double ans_t = -1e9, g[N], f[N];
struct Edge{
    int v, nxt;
}e[N << 1];
int head[N];

inline void adde(int from, int to){
    static int et = 0;
    e[++et] = (Edge){to, head[from]};
    head[from] = et;
}

void dfs(int x, int fa) {
    f[x] = g[x] = -inf;
    int fx = -inf, gx = -inf;
    for(int i = head[x]; i; i = e[i].nxt) {
        int v = e[i].v;
        if(v == fa) continue;
        dfs(v, x);
        if(b[v] > fx) {
            gx = fx;
            fx = b[v];
        } else
        if(b[v] > gx)
            gx = b[v];
        ans_t = max(ans_t, (b[x] + f[v]) / 3.0);
    }
    ans_t = max(ans_t, ((double)b[x] + fx + gx) / 3.0);
    if(fx != -inf) f[x] = fx + b[x];
    if(gx != -inf) g[x] = gx + b[x];
    ans_t = max(ans_t, f[x] / 2.0);
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n;
    for(int i = 1; i <= n; ++i) cin >> b[i];
    int x, y;
    for(int i = 1; i < n; ++i) {
        cin >> x >> y;
        adde(x, y), adde(y, x);
    }
    dfs(1, -1);
    double ans = ans_t * ans_t / 4.0;
    ans_t = -inf;
    for(int i = 1; i <= n; ++i) b[i] = -b[i];
    dfs(1, -1);
    ans = max(ans, ans_t * ans_t / 4.0);
    printf("%.6lf\n", ans);
	return 0;
}
