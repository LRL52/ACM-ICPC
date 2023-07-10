/*** 
 * @Author: LRL52
 * @Date: 2023-03-09 23:07:20
 * @LastEditTime: 2023-03-09 23:20:08
 */
//按ai为关键字排序，每次考虑ai为a中的最大值，计算答案即可
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
using i64 = long long;
using pii = pair<int, int>;
const int N = 500000 + 55, inf = 0x3f3f3f3f;
int n, suf[N];
pii a[N];

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int Task; cin >> Task;
	while(Task--) { 
		cin >> n;
        rep(i, 1, n) cin >> a[i].first >> a[i].second;
        sort(a + 1, a + n + 1);
        suf[n + 1] = -1;
        for(int i = n; i >= 1; --i) suf[i] = max(a[i].second, suf[i + 1]);
        int ans = inf;
        multiset<int> S;
        for(int i = 1, j = 0; i <= n; ++i) {
            auto [ai, bi] = a[i];
            while(j < n && a[j + 1].first <= ai) {
                ++j;
                S.insert(a[j].second);
            }
            if(j != n) ans = min(ans, abs(ai - suf[j + 1]));
            if(suf[j + 1] < ai) {
                auto it = S.find(bi);
                S.erase(it);
                it = S.lower_bound(ai);
                if(it != S.end()) ans = min(ans, *it - ai);
                if(it != S.begin()) ans = min(ans, ai - *prev(it));
                S.insert(bi);
            }
        }
        cout << ans << '\n'; 
	}
	return 0;
}