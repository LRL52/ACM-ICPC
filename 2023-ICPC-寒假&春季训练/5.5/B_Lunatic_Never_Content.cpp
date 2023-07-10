#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
using i64 = long long;
using pii = pair<int, int>;
const int N = 1e5 + 55, inf = 0x3f3f3f3f;
int a[N], n;

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int Task; cin >> Task;
	while(Task--) { 
		cin >> n;
        rep(i, 1, n) cin >> a[i];
        int ans = abs(a[n] - a[1]);
        for (int i = 2, j = n - 1; i <= j; ++i, --j) {
            ans = gcd(ans, abs(a[i] - a[j]));
        }
        cout << ans << '\n';
	}
	return 0;
}