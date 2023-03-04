//ID: LRL52  Date: 2023.2.3
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
using LL = long long;
const int N = 2e5 + 55, M = 2e3 + 55, inf = 0x3f3f3f3f;
int cnt[N], f[N], g[N];

signed main() {
#ifdef LRL52
	freopen("D.in", "r", stdin);
#endif
	ios::sync_with_stdio(false); cin.tie(nullptr);
	int Task; cin >> Task;
    while(Task--) {
        int n;
        string s; cin >> n >> s;
        int tot = 0;
        for(int i = 0; i < 30; ++i) cnt[i] = 0;
        for(int i = 0; i < s.size(); ++i) {
            if(!cnt[s[i] - 'a']) {
                cnt[s[i] - 'a']++;
                ++tot;
            }
            f[i] = tot;
        }
        for(int i = 0; i < 30; ++i) cnt[i] = 0;
        tot = 0;
        for(int i = (int)s.size() - 1; i >= 0; --i) {
            if(!cnt[s[i] - 'a']) {
                cnt[s[i] - 'a']++;
                ++tot;
            }
            g[i] = tot;
        }
        int ans = 0;
        for(int i = 1; i < s.size(); ++i)
            ans = max(ans, f[i - 1] + g[i]);
        cout << ans << '\n';
    }
	return 0;
}