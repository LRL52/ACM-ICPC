/*** 
 * @Author: LRL52
 * @Date: 2023-05-19 22:45:49
 * @LastEditTime: 2023-05-19 22:49:31
 */
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
using i64 = long long;
using pii = pair<int, int>;
const int N = 2e5 + 55, inf = 0x3f3f3f3f, MOD = 1e9 + 7;
int n, K;
int a[N], b[N], Ans[N];

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int Task; cin >> Task;
	while(Task--) { 
		cin >> n >> K;
        vector<pii> c(n + 1);
        for (int i = 1; i <= n; ++i) cin >> a[i], c[i] = {a[i], i};
        for (int i = 1; i <= n; ++i) cin >> b[i];
        sort(c.begin() + 1, c.end());
        sort(b + 1, b + n + 1);
        for (int i = 1; i <= n; ++i) Ans[c[i].second] = b[i];
        for (int i = 1; i <= n; ++i) cout << Ans[i] << " \n"[i == n];
	}
	return 0;
}