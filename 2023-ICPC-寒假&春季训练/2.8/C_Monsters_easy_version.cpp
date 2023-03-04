//ID: LRL52  Date: 2023.2.5
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
using LL = long long;
using pii = pair<int, int>;
const int N = 2e5 + 55, M = 2e3 + 55, inf = 0x3f3f3f3f;
int n;
int a[N];

signed main() {
#ifdef LRL52
	freopen("D.in", "r", stdin);
#endif
	ios::sync_with_stdio(false); cin.tie(nullptr);
	int Task; cin >> Task;
	while(Task--) {
		cin >> n;
        rep(i, 1, n) cin >> a[i];
        sort(a + 1, a + n + 1);
        LL ans = 0, now = 1;
        rep(i, 1, n) {
            ans += max(a[i] - now, 0LL);
            if(a[i] >= now) ++now;
        }
        printf("%lld\n", ans);
	}
	return 0;
}