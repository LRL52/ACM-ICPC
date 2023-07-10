/*** 
 * @Author: LRL52
 * @Date: 2023-05-06 00:17:27
 * @LastEditTime: 2023-05-06 00:17:28
 */
#include <bitsdc++.h>

#ifdef LOCAL_DEFINE
#include <dbg.h>
#else
#define dbg(...)
#endif

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 5005;
void Main(int cc) {
    int m, n; // city,model
    cin >> m >> n;
    vector<ll> f(n);
    for (auto &i : f) cin >> i;

    vector<bitset<N>> g(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            g[i][j] = true;
        }
    }
    for (int i = 0; i < m; i++) {
        vector<pii> f(n);
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            f[j] = {x, j};
        }
        sort(f.begin(), f.end());
        bitset<N> b;
        for (int i = 0; i < n; i++) {
            b[i] = 1;
        }

        for (int j = 0, k = 0; j < n; j++) {
            auto [h, id] = f[j];
            while (k < n && f[k].first <= h) {
                b[f[k].second] = 0;
                k++;
            }
            g[id] &= b;
        }
    }
    vector<vector<int>> G(n);
    vector<int> deg(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j || g[i][j] == false) continue;
            G[i].push_back(j);
            deg[j]++;
        }
    }
    vector<ll> dp(n);

    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (deg[i] == 0) {
            q.push((i));
            dp[i] = f[i];
        }
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : G[u]) {
            deg[v]--;
            if (deg[v] == 0) {
                q.push(v);
            }
            dp[v] = max(dp[v], dp[u] + f[v]);
        }
    }
    ll ans = dp[0];
    for (auto &i : dp) ans = max(ans, i);

    cout << ans << endl;
}

signed main() {
#ifndef ONLINE_JUDGE
    (void)!freopen("temp.in", "r", stdin);
#endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int o_o = 1;
    for (int j = 1; j <= o_o; j++) {
        Main(j);
    }
    return 0;
}
