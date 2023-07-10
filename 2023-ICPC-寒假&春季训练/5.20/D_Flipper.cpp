/*** 
 * @Author: LRL52
 * @Date: 2023-05-19 23:11:13
 * @LastEditTime: 2023-05-19 23:22:43
 */
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
using i64 = long long;
using pii = pair<int, int>;
const int N = 2e5 + 55, inf = 0x3f3f3f3f, MOD = 1e9 + 7;
int n, a[N];

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int Task; cin >> Task;
	while(Task--) { 
		cin >> n;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        if (n == 1) {
            cout << "1" << '\n';
            continue;
        }
        vector<int> Ans;
        int maxv = 0, pos = 0;
        for (int i = 2; i <= n; ++i) {
            if (a[i] > maxv) {
                maxv = a[i];
                pos = i;
            }
        }
        for (int i = pos; i <= n; ++i) Ans.push_back(a[i]);
        if (pos != n) Ans.push_back(a[--pos]);
        --pos;
        for (int i = 1, j = pos; i <= j; ) {
            if (a[j] > a[i]) {
                Ans.push_back(a[j]);
                --j;
            } else {
                while (i <= j) Ans.push_back(a[i++]);
                break;
            }
        }
        for (auto x : Ans) cout << x << ' ';
        cout << '\n';
	}
	return 0;
}