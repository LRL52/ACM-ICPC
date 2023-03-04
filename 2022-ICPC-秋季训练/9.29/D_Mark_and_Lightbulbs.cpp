//ID: LRL52  Date: 2022.9.24
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
constexpr int N = 2e5 + 55, inf = 0x3f3f3f3f;
char s1[N], s2[N];

signed main() {
#ifdef LRL52
	freopen("D.in", "r", stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(nullptr);
	int Task; cin >> Task;
    while(Task--) {
        int n; cin >> n;
        cin >> (s1 + 1) >> (s2 + 1);
        if (s1[1] != s2[1] || s1[n] != s2[n]) {
            puts("-1");
            continue;
        }
        vector<pair<int, int> > p1, p2;
        for(int i = 1, j; i <= n; i = j + 1) {
            j = i;
            if (s1[i] == '0') continue;
            while (j < n && s1[j + 1] == s1[i]) ++j;
            p1.emplace_back(make_pair(i, j));
        }
        for(int i = 1, j; i <= n; i = j + 1) {
            j = i;
            if (s2[i] == '0') continue;
            while (j < n && s2[j + 1] == s2[i]) ++j;
            p2.emplace_back(make_pair(i, j));
        }
        if (p1.size() != p2.size()) {
            puts("-1");
            continue;
        }
        long long  ans = 0;
        for (int i = 0; i < p1.size(); ++i) {
            ans += abs(p1[i].first - p2[i].first) + abs(p1[i].second - p2[i].second);
        }
        printf("%lld\n", ans);
    }
	return 0;
}