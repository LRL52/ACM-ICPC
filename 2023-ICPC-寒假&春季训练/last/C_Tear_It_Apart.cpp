#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
using i64 = long long;
using pii = pair<int, int>;
const int N = 2e5 + 55, inf = 0x3f3f3f3f;
int n;
char s[N];
int lg[N];

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int Task; cin >> Task;
    lg[0] = -1; n = 2e5;
    for (int i = 1; i <= n; ++i) lg[i] = lg[i >> 1] + 1;
	while(Task--) { 
        cin >> (s + 1);
        n = strlen(s + 1);
        int ans = n;
        for (char c = 'a'; c <= 'z'; ++c) {
            int res = 0;
            for (int i = 1, j; i <= n; i = j + 1) {
                char now = s[i];
                j = i;
                if (now == c) continue;
                while (j < n && s[j + 1] != c) ++j;
                res = max(res, lg[j - i + 1] + 1);
            }
            ans = min(ans, res);
        }
        cout << ans << '\n';
	}
	return 0;
}