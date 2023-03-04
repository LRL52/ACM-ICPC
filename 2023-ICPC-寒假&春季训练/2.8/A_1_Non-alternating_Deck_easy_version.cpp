//ID: LRL52  Date: 2023.2.5
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
using LL = long long;
using pii = pair<int, int>;
const int N = 1e3 + 55, M = 2e3 + 55, inf = 0x3f3f3f3f;

signed main() {
#ifdef LRL52
	freopen("D.in", "r", stdin);
#endif
	ios::sync_with_stdio(false); cin.tie(nullptr);
	int Task; cin >> Task;
	while(Task--) {
        int n;
        cin >> n;
        int t = 1, r = 3;
        int res1 = 0, res2 = 0;
        while(n > 0) {
            int dx = min(t, n);
            n -= dx;
            if(r >= 2) res1 += dx;
            else res2 += dx;
            r = (r + 1) % 4;
            ++t;
        }
        printf("%d %d\n", res1, res2);
	}
	return 0;
}