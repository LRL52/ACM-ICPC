/*** 
 * @Author: LRL52
 * @Date: 2023-06-09 17:26:45
 * @LastEditTime: 2023-06-09 17:44:52
 */
#include <algorithm>
#include <bits/stdc++.h>
#include <mutex>
using namespace std;
using i64 = long long;
using pii = pair<int, int>;
const int N = 1e3 + 55, M = 2e5, inf = 0x3f3f3f3f, MOD = 1e9 + 7;

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n, Q; cin >> n >> Q;
    vector<int> a(n + 1), Cnt(M + 1), Ans(M + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i], Cnt[a[i]]++;
    sort(a.begin() + 1, a.begin() + n + 1);
    a.erase(unique(a.begin() + 1, a.end()), a.end());
    n = (int)a.size() - 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; a[i] * j <= M; ++j) {
            auto t = a[i] * j;
            if ((t == a[i] && Cnt[a[i]] > 1) || (t != a[i] && Cnt[t] > 0)) {
                Ans[j] = 1;
            }
        }
    }
    for (int _ = 1; _ <= Q; ++_) {
        int x; cin >> x;
        cout << ((Ans[x] || (n == 1 && x == 1)) ? "YES" : "NO") << '\n';
    }
	return 0;
}