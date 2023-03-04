//ID: LRL52  Date: 2023.2.8
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
using LL = long long;
using pii = pair<int, int>;
const int N = 1e5 + 55, M = 2e3 + 55, inf = 0x3f3f3f3f;
int n, m;
int a[N], b[N];
LL sum1[N], sum2[N];

signed main() {
#ifdef LRL52
	freopen("D.in", "r", stdin);
#endif
	ios::sync_with_stdio(false); cin.tie(nullptr);
	int Task, tcnt = 0; cin >> Task;
	while(Task--) {
		cin >> n >> m;
        rep(i, 1, n) cin >> a[i], sum1[i] = sum1[i - 1] + a[i];
        rep(i, 1, m) cin >> b[i], sum2[i] = sum2[i - 1] + b[i];
        int p1 = 0, p2 = 0, k = 0;
        LL ans = 0, cnt = 0;
        while(p1 < n && p2 < m) {
            ++cnt;
            if(sum1[k + 1] >= sum2[k + 1]) {
                ++p1, ans += cnt * a[p1];
            } else {
                ++p2, ans += cnt * b[p2];
            }
            k = max(p1, p2);
        }
        while(p1 < n) ans += (++cnt) * a[++p1];
        while(p2 < m) ans += (++cnt) * b[++p2];
        printf("Case %d: %lld\n", ++tcnt, ans);
	}
	return 0;
}