/*** 
 * @Author: LRL52
 * @Date: 2023-06-04 23:11:04
 * @LastEditTime: 2023-06-04 23:15:08
 */
#include <bits/stdc++.h>
#include <vector>
using namespace std;
using i64 = long long;
using pii = pair<int, int>;
const int N = 1e3 + 55, inf = 0x3f3f3f3f, MOD = 1e9 + 7;

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int Task; cin >> Task;
	while(Task--) { 
		int n; cin >> n;
        vector<int> a(n + 1), Pos(n + 1);
        for (int i = 1; i <= n; ++i) cin >> a[i], Pos[a[i]] = i;
        vector<pii> b;
        b.emplace_back(Pos[1], 1);
        b.emplace_back(Pos[2], 2);
        b.emplace_back(Pos[n], n);
        sort(b.begin(), b.end());
        int p = 0;
        for (int i = 0; i < (int)b.size(); ++i) {
            if (b[i].second == n) {
                p = i;
                break;
            }
        }
        if (p == 1) printf("%d %d\n", 1, 1);
        else printf("%d %d\n", b[p].first, b[1].first);
	}
	return 0;
}