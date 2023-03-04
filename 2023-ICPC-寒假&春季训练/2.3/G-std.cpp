#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, c;
    std::cin >> n >> c;
    
    std::vector<std::pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        a[i] = {std::min(x + i + 1, x + n - i), x + i + 1};
    }
    std::sort(a.begin(), a.end());
    
    std::vector<i64> sum(n + 1);
    for (int i = 0; i < n; i++) {
        sum[i + 1] = sum[i] + a[i].first;
    }
    
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i].second <= c) {
            int lo = 0, hi = n;
            while (lo < hi) {
                int x = (lo + hi + 1) / 2;
                i64 val = sum[x];
                if (x > i) {
                    val -= a[i].first;
                }
                if (val + a[i].second <= c) {
                    lo = x;
                } else {
                    hi = x - 1;
                }
            }
            ans = std::max(ans, 1 + lo - (lo > i));
        }
    }
    std::cout << ans << "\n";
}

int main() {
#ifdef LRL52
	freopen("G.in", "r", stdin);
#endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}
