/*** 
 * @Author: LRL52
 * @Date: 2023-04-29 23:41:33
 * @LastEditTime: 2023-04-30 00:33:46
 */
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
using i64 = long long;
using pii = pair<int, int>;
const int N = 2e3 + 55, inf = 0x3f3f3f3f;
int n, m, et, flag, deg[N],vis[N], instk[N], pre[N], chose[N];
struct Edge{
    int v, nxt;
}e[N << 1];
int head[N];
vector<pii> Ans;

inline void adde(int from, int to){
    e[++et] = (Edge){to, head[from]};
    head[from] = et;
}

void getAns(int x) {
    for (int i = pre[x], j = x; ; j = i, i = pre[i]) {
        if (i == 0) break;
        Ans.emplace_back(i, j);
        chose[i] = chose[j] = 1;
    }
}

// void dfs(int x) {
//     instk[x] = vis[x] = 1;
//     for (int i = head[x]; i; i = e[i].nxt) {
//         int v = e[i].v;
//         if (instk[v]) continue;
//         else if(vis[v]) {
//             flag = 1;
//             getAns(x);
//             getAns(v);
//             Ans.emplace_back(x, v);
//             chose[x] = chose[v] = 1;
//             return;
//         }
//         pre[v] = x;
//         dfs(v);
//         if (flag) return;
//     }
//     instk[x] = 0;
// }

void BFS(int st) {
    queue<int> q;
    // q.push(st);
    int co = 0;
    for (int i = head[st]; i; i = e[i].nxt) {
        int v = e[i].v;
        pre[v] = st;
        vis[v] = ++co;
        q.push(v);
    }
    while (!q.empty()) {
        auto x = q.front(); q.pop();
        // vis[x] = 1;
        for (int i = head[x]; i; i = e[i].nxt) {
            int v = e[i].v;
            if (v == st) continue;
            if (!vis[v]) {
                pre[v] = x;
                vis[v] = vis[x];
                q.push(v);
            } else 
            if (vis[v] != vis[x]) {
                flag = 1;
                getAns(x);
                getAns(v);
                Ans.emplace_back(x, v);
                chose[x] = chose[v] = 1;
                return;
            }
        }
    }

}

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int Task; cin >> Task;
	while(Task--) { 
		cin >> n >> m; et = 0;
        for (int i = 1; i <= n; ++i) deg[i] = chose[i] = head[i] = 0;
        for (int i = 1; i <= m; ++i) {
            int x, y;
            cin >> x >> y;
            adde(x, y), adde(y, x);
            ++deg[x], ++deg[y];
        }
        flag = 0; Ans.clear();
        for (int i = 1; i <= n; ++i) {
            if (deg[i] >= 4) {
                for (int j = 1; j <= n; ++j) vis[j] = pre[j] = chose[j] = instk[j] = 0;
                //dfs(i);
                BFS(i);
                if (flag) {
                    int cnt = 0;
                    for (int j = head[i]; j ; j = e[j].nxt) {
                        int v = e[j].v;
                        // printf("v = %d, chose[%d] = %d\n", v, v, chose[v]);
                        if (!chose[v]) {
                            chose[v] = 1;
                            Ans.emplace_back(i, v);
                            if (++cnt == 2) break;
                        }
                    }
                    // assert(cnt == 2);
                    if (cnt < 2) {
                        flag = 0;
                        Ans.clear();
                    } else
                        break;
                }
            }
        }
        if (flag) {
            puts("YES");
            printf("%d\n", (int)Ans.size());
            for (auto &[x, y] : Ans)
                printf("%d %d\n", x, y);
        } else
            puts("NO");
	}
	return 0;
}