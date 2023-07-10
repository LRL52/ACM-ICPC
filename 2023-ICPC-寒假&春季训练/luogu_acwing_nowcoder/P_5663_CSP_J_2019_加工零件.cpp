/*** 
 * @Author: LRL52
 * @Date: 2023-05-20 11:45:29
 * @LastEditTime: 2023-05-20 12:04:34
 */
#include <array>
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
using i64 = long long;
using pii = pair<int, int>;
const int N = 1e3 + 55, inf = 0x3f3f3f3f, MOD = 1e9 + 7;

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n, m, Q;
    cin >> n >> m >> Q;
    vector<vector<int> > G(n + 1);
    for (int i = 1; i <= m; ++i) {
        int x, y; cin >> x >> y;    
        G[x].push_back(y), G[y].push_back(x);
    }
    queue<array<int, 2> > q;
    vector<array<int, 2> > dis(n + 1), vis(n + 1);
    q.push({1, 0}); vis[1][0] = 1;
    while (!q.empty()) {
        auto [now, sta] = q.front(); q.pop();
        for (auto v : G[now]) {
            if (!vis[v][sta ^ 1]) {
                dis[v][sta ^ 1] = dis[now][sta] + 1;
                vis[v][sta ^ 1] = 1;
                q.push({v, sta ^ 1});
            }
        }
    }
    for (int i = 1; i <= Q; ++i) {
        int x, y; cin >> x >> y;
        if (vis[x][y & 1] && dis[x][y & 1] <= y) cout << "Yes" << '\n';
        else cout << "No" << '\n'; 
    }
	return 0;
}