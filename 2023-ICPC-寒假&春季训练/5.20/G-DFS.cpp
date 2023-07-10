/*** 
 * @Author: LRL52
 * @Date: 2023-05-21 12:35:23
 * @LastEditTime: 2023-05-21 19:04:18
 */
//直接 DFS，遇到大小为 3 的子树就切割，同时返回的 size 修改为 0，这样写最简单
#include <bits/stdc++.h>
#include <cstdio>
#include <vector>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
using i64 = long long;
using pii = pair<int, int>;
const int N = 2e5 + 55, inf = 0x3f3f3f3f, MOD = 1e9 + 7;
int n, et = 0, flag;
struct Edge{
    int v, nxt;
}e[N << 1];
int head[N], Size[N], fa[N], Num[N];
vector<int> Ans;

inline void adde(int from, int to){
    e[++et] = (Edge){to, head[from]};
    head[from] = et;
}

void dfs(int x) {
    Size[x] = 1;
    for (int i = head[x]; i; i = e[i].nxt) {
        int v = e[i].v;
        if (v == fa[x]) continue;
        fa[v] = x, Num[v] = (i + 1) / 2;
        dfs(v);
        Size[x] += Size[v];
    }
    if (Size[x] == 3) { 
        if (Num[x]) Ans.push_back(Num[x]);
        Size[x] = 0;
    }
    if (Size[x] > 3 || (x == 1 && Size[x] > 0)) flag = 1;
}

signed main() {
#ifdef LRL52
	freopen("G.in", "r", stdin);
#endif
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int Task; cin >> Task;
	while(Task--) { 
		cin >> n; et = 0;
        for (int i = 1; i <= n; ++i) Size[i] = head[i] = fa[i] = Num[i] = 0;
        for (int i = 1; i < n; ++i) {
            int x, y; cin >> x >> y;
            adde(x, y), adde(y, x);
        }
        Ans.clear(); flag = 0;
        dfs(1);
        if (flag) puts("-1");
        else {
            printf("%d\n", (int)Ans.size());
            for (auto i : Ans) printf("%d ", i);
            puts("");
        } 
	}
	return 0;
}