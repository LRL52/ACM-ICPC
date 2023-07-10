/*** 
 * @Author: LRL52
 * @Date: 2023-05-12 19:44:05
 * @LastEditTime: 2023-05-12 22:55:47
 */
#include <bits/stdc++.h>
#include <iostream>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
using i64 = long long;
using pii = pair<int, int>;
const int N = 2e5 + 55, inf = 0x3f3f3f3f;
int n, K;
int a[N];

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int Task; cin >> Task;
	while(Task--) { 
		cin >> n >> K;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        sort(a + 1, a + n + 1);
        // int i = 1, j = n, k = 1;
        // for (; k <= K; ++k) {
        //     if (a[i] + a[i + 1] <= a[j]) i += 2;
        //     else --j;
        // } 
        // i64 ans = 0;
        // for (int l = i; l <= j; ++l) ans += a[l];
        // cout << ans << '\n';
        i64 ans = 0;
        for (int i = 1; i <= n - K; ++i) ans += a[i];
        i64 res = ans;
        for (int i = n - K + 1, j = 1; i <= n; ++i) {
            res += a[i];
            res -= a[j];
            ++j;
            res -= a[j];
            ++j;
            ans = max(ans, res);
        }
        cout << ans << '\n';
	}
	return 0;
}