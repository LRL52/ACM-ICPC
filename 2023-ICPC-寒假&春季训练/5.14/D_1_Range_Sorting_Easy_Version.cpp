/*** 
 * @Author: LRL52
 * @Date: 2023-05-14 23:10:54
 * @LastEditTime: 2023-05-15 00:13:57
 */
#include <algorithm>
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
using i64 = long long;
using pii = pair<int, int>;
const int N = 1e3 + 55, inf = 0x3f3f3f3f, MOD = 1e9 + 7;
int n, a[N], val[N], b[N];
tuple<int, int, int> c[N];

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int Task; cin >> Task;
	while(Task--) { 
		cin >> n;
        for (int i = 1; i <= n; ++i) cin >> a[i], val[i] = a[i];
        sort(val + 1, val + n + 1);
        for (int i = 1; i <= n; ++i) a[i] = lower_bound(val + 1, val + n + 1, a[i]) - val;
        i64 ans = 0;
        for (int i = 1; i <= n; ++i) {
            // int cnt = 0;
            // for (int j = i; j <= n; ++j) val[++cnt] = a[j];
            // sort(val + 1, val + cnt + 1);
            // set<pii> s;
            // i64 res = 0;
            // for (int j = i; j <= n; ++j) {
            //     auto it = s.upper_bound({a[j], 0});
            //     auto cnt = 0;
            //     for (; it != s.end() ; it = next(it)) {
            //         cnt += it->second;
            //     }
                
            // }
            int tail = 0; i64 res = 0;
            for (int j = i; j <= n; ++j) {
                int l = min(j, a[j]), r = max(j, a[j]);
                i64 s = 1;
                while (tail > 0) {
                    auto &[x, y, z] = c[tail];
                    if (y >= l) {
                        l = min(l, x);
                        r = max(r, y);
                        res -= (z - 1);
                        s += z;
                        --tail;
                    } else
                        break;
                }
                c[++tail] = {l, r, s};
                res += s - 1;
                ans += res;
                cout << "i = " << i << " j = " << j <<  " res = " <<  res << '\n';
            }
        }
        cout << ans << '\n';
	}
	return 0;
}