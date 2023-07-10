/*** 
 * @Author: LRL52
 * @Date: 2023-05-12 19:44:05
 * @LastEditTime: 2023-05-13 00:25:40
 */
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
using i64 = long long;
using pii = pair<int, int>;
const int N = 1e3 + 55, inf = 0x3f3f3f3f;
#define int long long
int n, K;
int a[N], b[N];

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> K;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int _ = 1; _ <= K; ++_) {
        int m;
        cin >> m;
        for (int j = 1; j <= n; ++j) b[j] = a[j];
        int s, t;
        if (m <= n) s = 1, t = 0;
        else if ((m - n) % 2 == 0) {
            s = m - n + 1, t = (m - n) >> 1;
        } else {
            s = m - n + 2, t = (m - n + 1) >> 1;
        }
        int p = 1;
        for (int i = m; i >= s; --i) {
            b[p] += i;
            ++p;
        }
        int minv = 2e9;
        for (int i = 1; i <= n; ++i) minv = min(minv, b[i]);
        for (int i = 1; i <= n; ++i) {
            t -= b[i] - minv;
        }
        int ans;
        if (t > 0) ans = minv - t / n - (t % n != 0);
        else ans = minv;
        cout << ans << ' ';
    }
	return 0;
}