/*** 
 * @Author: LRL52
 * @Date: 2023-05-08 20:40:44
 * @LastEditTime: 2023-05-08 21:02:30
 */
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
using i64 = long long;
using pii = pair<int, int>;
const int N = 1e3 + 55, inf = 0x3f3f3f3f;
int n, m;

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int Task; cin >> Task;
	while(Task--) { 
		cin >> n >> m;
        vector<int> a;
        int left = 0, right = 0;
        for (int i = 1; i <= n; ++i) {
            int x;
            cin >> x;
            if (x < 0) {
                if (x == -1) ++left;
                else ++right;
            } else {
                a.push_back(x);
            }
        }
        sort(a.begin(), a.end());
        a.erase(unique(a.begin(), a.end()), a.end());
        int ans = 0;
        // map<int, int> vis;
        // for (int i = 1; i <= min(right, m); ++i) {
        //     if (vis.find(i) == vis.end()) {
        //         vis[i] = 1;
        //         ++ans;
        //     }
        // }
        // for (int i = 1; i <= min(left, m); ++i) {
        //     int j = m - i + 1;
        //     if (vis.find(j) == vis.end()) {
        //         vis[j] = 1;
        //         ++ans;
        //     }
        // }
        // for (auto &x : a) {
        //     if (vis.find(x) == vis.end()) {
        //         vis[x] = 1;
        //         ++ans;
        //     }
        // }
        ans = 0;
        n = a.size();
        for (int i = 0; i < n; ++i) {
            // int x = a[i];
            auto res1 = min(a[i], left + i + 1);
            auto res2 = min(m - a[i], (n - 1) - (i + 1) + 1 + right);
            ans = max(ans, res1 + res2);
        }
        ans = max(ans, max(min(left + n, m), min(right + n, m))); 
        // int res = min(m, left + right + (int)a.size());
        // cout << max(res, ans) << endl;
        cout << ans << '\n';
	}
	return 0;
}