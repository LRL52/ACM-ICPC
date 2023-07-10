#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
using i64 = long long;
using pii = pair<int, int>;
const int N = 1e3 + 55, inf = 0x3f3f3f3f;

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int Task; cin >> Task;
	while(Task--) { 
		int n;
        cin >> n;
        int ans = 0, know = 0, unknow = 0;
        rep(i, 1, n) {
            int x;
            cin >> x;
            if(x == 1) ++unknow;
            else know += unknow, unknow = 0;
            auto res = 0;
            if(know > 0) res = (know & 1) ? (know + 1) / 2 : know / 2 + 1;
            res += unknow;
            ans = max(ans, res);
        }
        cout << ans << '\n';
	}
	return 0;
}