/*** 
 * @Author: LRL52
 * @Date: 2023-05-15 00:16:24
 * @LastEditTime: 2023-05-15 00:17:58
 */
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
using i64 = long long;
using pii = pair<int, int>;
const int N = 1e3 + 55, inf = 0x3f3f3f3f, MOD = 1e9 + 7;
#define int long long

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int Task; cin >> Task;
	while(Task--) { 
		int n;
        cin >> n;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            int mi = a[i];
            vector<int> v;
            for (int j = i - 1; j >= 1; j--) {
                while (v.size() && a[j] > v.back())
                    v.pop_back();
                if (a[j] < mi) {
                    v.push_back(mi);
                    mi = a[j];
                }
                ans += i - j - v.size();
            }
        }
        cout << ans << endl;
    }
	return 0;
}