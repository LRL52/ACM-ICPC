/*** 
 * @Author: LRL52
 * @Date: 2023-03-09 19:39:19
 * @LastEditTime: 2023-03-09 20:33:27
 */
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
using i64 = long long;
using pii = pair<int, int>;
const int N = 500000 + 55, inf = 0x3f3f3f3f;
int n, suf[N];
pii a[N];

void Solve(int &ans) {
    // auto cmp = [](const int &t1, const int &t2) {
    //     auto r1 = max(a[t1], b[t1]);
    //     auto r2 = max(a[t2], b[t2]);
    //     return r1 < r2;
    // };
    // sort(order + 1, order + n + 1, cmp);
    auto cmp = [](const pii &t1, const pii &t2) {
        return max(t1.first, t1.second) > max(t2.first, t2.second);
    };
    sort(a + 1, a + n + 1, cmp);
    suf[n] = a[n].second, suf[n + 1] = -1;
    for(int i = n - 1; i >= 1; --i) suf[i] = max(suf[i + 1], a[i].second);
    int r1 = -1, r2 = -1;
    for(int i = 1; i <= n; ++i) {
        auto [ai, bi] = a[i];
        if(r1 > ai) goto TAG;
        // if(ai < bi) goto TAG;
        if(r2 != -1 || i != n) {
            auto t = max(r2, suf[i + 1]);
            if(ai >= t)
                ans = min(ans, ai - t);
        }
        TAG:
        if(bi <= ai) {
            r2 = max(r2, bi);
        } else {
            r1 = max(r1, ai);
        }
    }
}

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int Task; cin >> Task;
	while(Task--) { 
		cin >> n;
        rep(i, 1, n) cin >> a[i].first >> a[i].second;
        int ans = inf;
        Solve(ans);
        rep(i, 1, n) swap(a[i].first, a[i].second);
        Solve(ans);
        cout << ans << '\n';
	}
	return 0;
}