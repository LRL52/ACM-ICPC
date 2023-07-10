#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
using i64 = long long;
using pii = pair<int, int>;
const int N = 1e3 + 55, inf = 0x3f3f3f3f;
int n;

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int Task; cin >> Task;
	while(Task--) { 
        cin >> n;
        // vector<int> p(n + 1), c(n + 1);
        map<int, int> H;
        i64 cnt = 0;
        for (int i = 1; i <= n; ++i) {
            int x;
            cin >> x;
            for (int j = 2; j * j <= x; ++j) {
                if (x % j == 0) {
                    // ++H[j];
                    // p[i].push_back(j);
                    // c[i].push_back(0);
                    while(x % j == 0)
                        ++H[j], ++cnt, x /=j;
                        // c[i].back()++, x /= j; 
                }
            }
            if (x > 1) {
                ++H[x], ++cnt;
                // p[i].push_back(x);
                // c[i].push_back(1);
            }
        }
        i64 ans = 0;
        for (auto [x, y] : H) {
            ans += y / 2;
            cnt -= y / 2 * 2;
        }
        ans += cnt / 3;
        printf("%lld\n", ans);
	}
	return 0;
}