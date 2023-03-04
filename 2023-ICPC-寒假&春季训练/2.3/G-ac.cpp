//ID: LRL52  Date: 2023.2.4
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
using LL = long long;
using pii = pair<int, int>;
const int N = 2e5 + 55, M = 2e3 + 55, inf = 0x3f3f3f3f;
int n, K;
pii a[N];
LL sum[N];

signed main() {
#ifdef LRL52
	freopen("G.in", "r", stdin);
#endif
	ios::sync_with_stdio(false); cin.tie(nullptr);
	int Task; cin >> Task;
    while(Task--) {
        cin >> n >> K;
        rep(i, 1, n) {
            int x; cin >> x;
            a[i] = { x + min(i, n + 1 - i), x + i };
            // a[i] = make_pair(x + min(i, n + 1 - i), x + i);
        }
        sort(a + 1, a + n + 1);
        sum[0] = 0;
        rep(i, 1, n) sum[i] = sum[i - 1] + a[i].first;
        int ans = 0;
        for(int i = 1; i <= n; ++i) {
            LL c = K - a[i].second;
            if(c < 0) continue;
            int l = 0, r = n;
            while(l <= r) {
                int mid = (l + r) >> 1, flag = 1;
                LL cost = sum[mid];
                if(mid >= i) {
                    cost -= a[i].first;
                    flag = 0;
                }
                if(cost <= c) {
                    ans = max(ans, mid + flag);
                    l = mid + 1;
                } else 
                    r = mid - 1;
            }
        }
        cout << ans << '\n';
    }
	return 0;
}