/*** 
 * @Author: LRL52
 * @Date: 2023-03-12 22:56:49
 * @LastEditTime: 2023-03-12 23:14:10
 */
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
using i64 = long long;
using pii = pair<int, int>;
const int N = 2e5 + 55, inf = 0x3f3f3f3f;
int L[N], R[N], q[N], f[N];

signed main() {
#ifdef LRL52
	freopen("B.in", "r", stdin);
#endif
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int Task; cin >> Task;
	while(Task--) { 
        int n, K, d, w;
		cin >> n >> K >> d >> w;
        for(int i = 1; i <= n; ++i) {
            cin >> L[i];
            R[i] = L[i] + w;
        }
        int ans = 0;
        for(int j = 1, i; j <= n; j = i + 1) {
            ans++;
            i = j;
            while(i < n && (i + 1) <= j + K - 1 && L[i + 1] <= R[j] + d) ++i;
        }
        cout << ans << '\n';
	}
	return 0;
}