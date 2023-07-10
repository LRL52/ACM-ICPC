/*** 
 * @Author: LRL52
 * @Date: 2023-06-16 23:57:18
 * @LastEditTime: 2023-06-17 00:30:11
 */
#include <bits/stdc++.h>
#include <functional>
using namespace std;
using i64 = long long;
using pii = pair<int, int>;
const int MAXN = 1e5, inf = 0x3f3f3f3f, MOD = 1e9 + 7;

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n, Q;
    vector<int> lg(MAXN + 1);
    lg[0] = -1;
    for (int i = 1; i <= MAXN; ++i)
        lg[i] = lg[i >> 1] + 1; 
	while(cin >> n && n) { 
		cin >> Q;
        vector<int> a(n + 1), L(n + 1), R(n + 1), c(n + 1);
        for (int i = 1; i <= n; ++i) cin >> a[i];
        int tot = 0;
        for (int i = 1, j; i <= n; i = j + 1) {
            j = i;
            while (j < n && a[j + 1] == a[i]) ++j;
            ++tot;
            for (int k = i; k <= j; ++k) {
                a[k] = tot;
                L[k] = i, R[k] = j;
            }
            c[tot] = j - i + 1;
        }
        vector<vector<int> > f(tot + 1, vector<int>(20));
        for (int i = 1; i <= tot; ++i) f[i][0] = c[i];
        for (int k = 1; k <= lg[tot]; ++k) {
            for (int i = 1; i + (1 << k) - 1 <= tot; ++i) {
                f[i][k] = max(f[i][k - 1], f[i + (1 << (k - 1))][k - 1]);
            }
        }
        function<int(int, int)> query = [&](int l, int r) {
            if (l > r) return 0;
            int k = lg[r - l + 1];
            return max(f[l][k], f[r - (1 << k) + 1][k]);
        };  
        for (int _ = 1; _ <= Q; ++_) {
            int l, r, ans; cin >> l >> r;
            if (a[l] == a[r]) ans = r - l + 1; 
            else ans = max(query(a[l] + 1, a[r] - 1), max(R[l] - l + 1, r - L[r] + 1));
            cout << ans << '\n';
        }
	}
	return 0;
}