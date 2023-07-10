/*** 
 * @Author: LRL52
 * @Date: 2023-05-28 22:50:21
 * @LastEditTime: 2023-05-28 23:11:51
 */
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
using i64 = long long;
using pii = pair<int, int>;
const int N = 2e5 + 55, inf = 0x3f3f3f3f, MOD = 1e9 + 7;
int n;

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int Task; cin >> Task;
	while(Task--) { 
		cin >> n;
        vector<vector<int> > Pos(n + 1);
        vector<pii> e(n + 1);
        for (int i = 1; i < n; ++i) {
            int x, y;
            cin >> x >> y;
            Pos[x].push_back(i);
            Pos[y].push_back(i);
            e[i] = {x, y};
        }
        vector<vector<pii> > G(n + 1);
        for (int i = 1; i < n; ++i) {
            auto &[x, y] = e[i];
            for (auto j : Pos[x]) {
                if (j == i) continue;
                if (j > i) G[i].emplace_back(j, 0);
                if (j < i) G[i].emplace_back(j, 1);
            }
            for (auto j : Pos[y]) {
                if (j == i) continue;
                if (j > i) G[i].emplace_back(j, 0);
                if (j < i) G[i].emplace_back(j, 1);
            }
        }
        for (auto i : Pos[1])
            G[0].emplace_back(i, 0);
        vector<int> dis(n + 1, inf);
        dis[0] = 0;
        deque<int> q; q.push_front(0);
        while (!q.empty()) {
            auto x = q.front(); q.pop_front();
            for (auto &[y, z] : G[x]) {
                if (dis[x] + z < dis[y]) {
                    dis[y] = dis[x] + z;
                    if (z == 0) q.push_front(y);
                    else q.push_back(y);
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) ans = max(ans, dis[i]);
        cout << ans + 1 << '\n';   
	}
	return 0;
}