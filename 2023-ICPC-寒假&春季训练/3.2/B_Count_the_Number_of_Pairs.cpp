//ID: LRL52  Date: 2023.3.2
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
using i64 = long long;
using pii = pair<int, int>;
const int N = 2e5 + 55, M = 2e3 + 55, inf = 0x3f3f3f3f;
char s[N];

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int Task; cin >> Task;
	while(Task--) {
        int n, K;
		cin >> n >> K >> (s + 1);
        map<char, int> H;
        for(int i = 1; i <= n; ++i)
            H[s[i]]++;
        int ans = 0, cnt = 0;
        for(char c = 'a'; c <= 'z'; ++c) {
            int minv = H[c], maxv = H[toupper(c)];
            if(minv > maxv) swap(minv, maxv);
            ans += minv;
            cnt += (maxv - minv) / 2;
        }
        ans += min(K, cnt);
        cout << ans << '\n';
	}
	return 0;
}