//ID: LRL52  Date: 2023.2.5
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
using LL = long long;
using pii = pair<int, int>;
const int N = 1e3 + 55, M = 2e3 + 55, inf = 0x3f3f3f3f;

pii operator+(const pii &t1, const pii &t2) {
    return {t1.first + t2.first, t1.second + t2.second};
}

signed main() {
#ifdef LRL52
	freopen("D.in", "r", stdin);
#endif
	ios::sync_with_stdio(false); cin.tie(nullptr);
	int Task; cin >> Task;
	while(Task--) {
		int n;
        cin >> n;
        int t = 1, r = 3, tot = 0;
        pii res1, res2;
        while(n > 0) {
            int dx = min(t, n);
            n -= dx;
            int now = tot + 1;
            tot += dx;
            pii d;
            if(now & 1) d = { (dx + 1) / 2, dx / 2 };
            else d = { dx / 2, (dx + 1) / 2 };
            if(r >= 2) res1 = res1 + d;
            else res2 = res2 + d;
            r = (r + 1) % 4;
            ++t;
        }
        printf("%d %d %d %d\n", res1.first, res1.second, res2.first, res2.second);
	}
	return 0;
}