//ID: LRL52  Date: 2023.2.4
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
using LL = long long;
using pii = pair<int, int>;
const int N = 1e3 + 55, M = 2e3 + 55, inf = 0x3f3f3f3f;
int n, m;
string s[N];

signed main() {
#ifdef LRL52
	freopen("D.in", "r", stdin);
#endif
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n >> m;
    rep(i, 1, n) cin >> s[i];
    sort(s + 1, s + m + 1);
    rep(i, 1, m) cout << s[i] << '\n';
	return 0;
}
