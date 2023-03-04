//ID: LRL52  Date: 2023.2.3
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
using LL = long long;
const int N = 1e3 + 55, M = 2e3 + 55, inf = 0x3f3f3f3f;
int n;

signed main() {
#ifdef LRL52
	freopen("D.in", "r", stdin);
#endif
	ios::sync_with_stdio(false); cin.tie(nullptr);
	int Task; cin >> Task;
    while(Task--) {
        cin >> n;
        int cnt = 0, minval = inf;
        LL ans = 0LL;
        rep(i, 1, n) {
            int x;
            cin >> x;
            if(x < 0) ++cnt;
            minval = min(minval, abs(x));
            ans += abs(x);
        }
        if(cnt & 1) ans -= 2LL * minval;
        cout << ans << '\n';
    }
	return 0;
}