/*** 
 * @Author: LRL52
 * @Date: 2023-06-04 23:00:45
 * @LastEditTime: 2023-06-04 23:01:21
 */
#include <bits/stdc++.h>
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
		int n; cin >> n;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        sort(a.begin() + 1, a.begin() + n + 1);
        if (a[1] < 0) cout << a[1] << '\n';
        else cout << a[n] << '\n';
	}
	return 0;
}