/*** 
 * @Author: LRL52
 * @Date: 2023-05-12 19:44:05
 * @LastEditTime: 2023-05-14 11:54:32
 */
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
using i64 = long long;
using pii = pair<int, int>;
const int N = 2e5 + 55, inf = 0x3f3f3f3f;
int n, Q;
int a[N], pre[N];

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> Q;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    sort(a + 1, a + n + 1);
    i64 sn = 0;
    for (int i = 1; i <= n; ++i) {
        sn += a[i] - i;
        if (i != 1) pre[i] = min(pre[i - 1], a[i] - i);
        else pre[i] = a[i] - i;        
    }
    for (int  _ = 1; _ <= Q; ++_) {
        int k, ans; cin >> k;
        if (k <= n) {
            if (k < n) ans = min(pre[k] + k + 1, a[k + 1]);
            else ans = pre[n] + k + 1;
        } else
        if ((k - n) % 2 == 0) {
            int t = (k - n) / 2, minv = pre[n] + k + 1;
            i64 more = sn + 1LL * (k + 1) * n - 1LL * minv * n;
            if (more >= t) ans = minv;
            else {
                auto y = t - more;
                ans = minv - (y + n - 1) / n;
            }
        } else {
            int t = (k - n + 1) / 2, minv = (n > 1) ? min(pre[n - 1] + k + 1, a[n]) : a[n];
            i64 more = sn - (a[n] - n) + 1LL * (k + 1) * (n - 1) + a[n] - 1LL * minv * n;
            if (more >= t) ans = minv;
            else {
                auto y = t - more;
                ans = minv - (y + n - 1) / n;
            }
        }
        cout << ans << " \n"[_ == Q];
    }
	return 0;
}