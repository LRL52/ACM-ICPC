//ID: LRL52  Date: 2023.2.3
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
using LL = long long;
const int N = 2e5 + 55, M = 2e3 + 55, inf = 0x3f3f3f3f;
int n, K;
int a[N];

signed main() {
#ifdef LRL52
	freopen("D.in", "r", stdin);
#endif
	ios::sync_with_stdio(false); cin.tie(nullptr);
	int Task; cin >> Task;
    while(Task--) {
        cin >> n >> K;
        rep(i, 1, n) {
            cin >> a[i];
            a[i] += i;
        }
        sort(a + 1, a + n + 1);
        int ans = 0; LL sum = 0;
        for(int i = 1; i <= n; ++i) {
            if(sum + a[i] <= K) {
                sum += a[i];
                ++ans;
            } else
                break;
        }
        cout << ans << '\n';
    }
	return 0;
}