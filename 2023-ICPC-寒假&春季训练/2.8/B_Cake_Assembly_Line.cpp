//ID: LRL52  Date: 2023.2.5
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
using LL = long long;
using pii = pair<int, int>;
const int N = 1e5 + 55, M = 2e3 + 55, inf = 0x3f3f3f3f;
int a[N], b[N];

signed main() {
#ifdef LRL52
	freopen("D.in", "r", stdin);
#endif
	ios::sync_with_stdio(false); cin.tie(nullptr);
	int Task; cin >> Task;
	while(Task--) {
        int n, w, h;
		cin >> n >> w >> h;
        rep(i, 1, n) cin >> a[i];
        rep(i, 1, n) cin >> b[i];
        LL l = -1e18, r = 1e18;
        rep(i, 1, n) {
            l = max(l, (LL)a[i] - b[i] - w + h);
            r = min(r, (LL)a[i] - b[i] + w - h);
        }
        if(l <= r) puts("YES");
        else puts("NO");
	}
	return 0;
}