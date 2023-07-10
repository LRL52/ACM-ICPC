/*** 
 * @Author: LRL52
 * @Date: 2023-07-01 20:05:15
 * @LastEditTime: 2023-07-01 20:08:21
 */
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using pii = pair<int, int>;
const int N = 1e3 + 55, inf = 0x3f3f3f3f, MOD = 1e9 + 7;
int num[N];

int check(int x) {
    int t = x, cnt = 0;
    while (t) {
        num[++cnt] = t % 10;
        t /= 10;
    }
    int res = 0;
    for (int i = 1; i <= cnt; ++i) 
        res = res * 10 + num[i];
    return (x % res == 0);
}

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n, ans = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) ans += check(i);
    cout << ans << '\n';
	return 0;
}