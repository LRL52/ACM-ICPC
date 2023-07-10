#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    std::vector<std::vector<std::pair<int, int>>> adj(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        adj[u].emplace_back(v, i);
        adj[v].emplace_back(u, i);
    }
    
    std::vector<int> ans;
    std::function<int(int, int)> dfs = [&](int x, int p) {
        int cnt1 = 0, cnt2 = 0;
        for (auto [y, i] : adj[x]) {
            if (y == p) {
                continue;
            }
            int v = dfs(y, x);
            if (v == -1) {
                return -1;
            }
            if (!v) {
                ans.push_back(i);
            } else if (v == 1) {
                cnt1++;
            } else {
                cnt2++;
            }
        }
        if (!cnt1 && !cnt2) {
            return 1;
        } else if (cnt2 == 1 && !cnt1) {
            return 0;
        } else if (cnt2) {
            return -1;
        } else if (cnt1 == 1) {
            return 2;
        } else if (cnt1 == 2) {
            return 0;
        } else {
            return -1;
        }
    };
    if (dfs(0, -1) != 0) {
        std::cout << -1 << "\n";
        return;
    }
    std::cout << ans.size() << "\n";
    // for (int i = 0; i < ans.size(); i++) {
    //     std::cout << ans[i] << " \n"[i == ans.size() - 1];
    // }
}

int main() {
#ifdef LRL52
	freopen("G.in", "r", stdin);
#endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    int t;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}