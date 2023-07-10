/*** 
 * @Author: LRL52
 * @Date: 2023-05-21 12:35:23
 * @LastEditTime: 2023-05-21 18:11:36
 */
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
using i64 = long long;
using pii = pair<int, int>;
const int N = 2e5 + 55, inf = 0x3f3f3f3f, MOD = 1e9 + 7;
int n, et = 0;
struct Edge{
    int v, nxt;
}e[N << 1];
int head[N], Size[N], fa[N], Num[N], tag[N];

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
}

signed main() {
#ifdef LRL52
	freopen("G.in", "r", stdin);
#endif
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int Task; cin >> Task;
	while(Task--) { 
		cin >> n; et = 0;
        for (int i = 1; i <= n; ++i) Size[i] = head[i] = fa[i] = Num[i] = tag[i] = 0;
        for (int i = 1; i < n; ++i) {
            int x, y; cin >> x >> y;
            adde(x, y), adde(y, x);
        }
        dfs(1);
        queue<int> q;
        for (int i = 1; i <= n; ++i)
            if (Size[i] == 3)
                q.push(i);
        vector<int> Ans; int tot = n;
        while (!q.empty()) {
            auto x = q.front(); q.pop();
            tot -= 3;
            if (x == 1) {
                assert(q.empty());
                assert(tot == 0);
                break;
            }
            Ans.push_back(Num[x]);
            // Size[fa[x]] -= Size[x];
            int last = x, s = 3 + tag[x];
            tag[x] = 0;
            for (int v = fa[x], i = 1; v && i <= 3; v = fa[v], ++i) {
                Size[v] -= s;
                if (Size[v] == 3) q.push(v);
                s += tag[v];
                tag[v] = 0;
                last = v;
            }
            tag[last] = s;
        }
        if (tot == 0) {
            printf("%d\n", (int)Ans.size());
            for (auto i : Ans) printf("%d ", i);
            puts("");
        } else {
            puts("-1");
        }
	}
	return 0;
}