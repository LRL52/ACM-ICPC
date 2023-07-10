/*** 
 * @Author: LRL52
 * @Date: 2023-06-03 23:19:49
 * @LastEditTime: 2023-06-03 23:22:47
 */
#include <bits/stdc++.h>
#include <functional>
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
	int Task; cin >> Task;
	while(Task--) {
        int n; 
		cin >> n;
        vector<vector<int> > a(n + 1);
        for (int i = 1; i <= n; ++i) {
            int x, y;
            cin >> x >> y;
            a[x].push_back(y);
        }
        i64 ans = 0;
        for (int i = 1; i <= n; ++i) {
            sort(a[i].begin(), a[i].end(), greater<int>());
            for (int j = 0; j < min(i, (int)a[i].size()); ++j) {
                ans += a[i][j];
            }
        }
        cout << ans << '\n';
	}
	return 0;
}