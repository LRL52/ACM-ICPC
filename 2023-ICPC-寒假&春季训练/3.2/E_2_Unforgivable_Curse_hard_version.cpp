//ID: LRL52  Date: 2023.3.2
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
using i64 = long long;
using pii = pair<int, int>;
const int N = 2e5 + 55, M = 2e3 + 55, inf = 0x3f3f3f3f;
char s[N], t[N];
int vis[N];

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int Task; cin >> Task;
	while(Task--) {
        int n, K;
		cin >> n >> K;
        cin >> (s + 1) >> (t + 1);
        rep(i, 1, n) vis[i] = 0;
        set<int> S;
        for(int i = 1; i + K <= n; ++i) {
            S.insert(i);
            if(i + K <= n) S.insert(i + K);
            if(i + K + 1 <= n) S.insert(i + K);
        }
        int ok = 1;
        vector<int> cnt1(26), cnt2(26);
        for(auto p : S) {
            vis[p] = 1;
            cnt1[s[p] - 'a']++;
            cnt2[t[p] - 'a']++;
        }
        if(cnt1 != cnt2) ok = 0;
        for(int i = 1; i <= n; ++i) {
            if(vis[i]) continue;
            if(s[i] != t[i]) ok = 0;
        }
        ok ? puts("YES") : puts("NO");
	}
	return 0;
}