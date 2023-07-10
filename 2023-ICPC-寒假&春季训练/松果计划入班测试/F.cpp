/*** 
 * @Author: LRL52
 * @Date: 2023-07-01 20:11:40
 * @LastEditTime: 2023-07-01 20:13:25
 */
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
using i64 = long long;
using pii = pair<int, int>;
const int N = 1e3 + 55, inf = 0x3f3f3f3f, MOD = 1e9 + 7;

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;
    unordered_map<string, int> H;
    for (int i = 1; i <= n; ++i) {
        string s;
        cin >> s;
        H[s]++;
    }
    int ans = 0;
    for (auto &[s, t] : H) {
        ans = max(ans, t);
    }
    cout << ans << '\n';
	return 0;
}