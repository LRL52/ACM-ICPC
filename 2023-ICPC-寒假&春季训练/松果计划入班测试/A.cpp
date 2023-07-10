/*** 
 * @Author: LRL52
 * @Date: 2023-07-01 19:15:36
 * @LastEditTime: 2023-07-01 19:20:23
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
	int n; cin >>n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    sort(a.begin() + 1, a.begin() + n + 1);
    i64 ans = 0;
    vector<int> b(n + 1); int p = 0;
    for (int i = 1, j = n; i <= j; ++i, --j) {
        b[++p] = a[i];
        if (i != j) b[++p] = a[j];
    }
    for (int i = 1; i < n; ++i) {
        ans += abs(b[i] - b[i + 1]);
    }
    ans += abs(b[n] - b[1]);
    i64 res = 0; p = 0;
    for (int i = 1, j = n; i <= j; ++i, --j) {
        b[++p] = a[j];
        if (i != j) b[++p] = a[i];
    }
    for (int i = 1; i < n; ++i) {
        res += abs(b[i] - b[i + 1]);
    }
    res += abs(b[n] - b[1]);
    ans = max(ans, res);
    cout << ans << '\n';
	return 0;
}