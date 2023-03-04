//ID: LRL52  Date: 2023.3.2
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
using i64 = long long;
using ui64 = unsigned long long;
using pii = pair<int, int>;
const int N = 2e5 + 55, M = 2e3 + 55, inf = 0x3f3f3f3f;
char s[N];
ui64 h1[N], h2[N], pow1[N], pow2[N];

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int Task; cin >> Task;
	while(Task--) {
		int n;
        cin >> n >> (s + 1);
        pow1[0] = pow2[0] = 1;
        for(int i = 1; i <= n; ++i) {
            h1[i] = h1[i - 1] * 131 + (s[i] - 'a' + 1);
            h2[i] = h2[i - 1] * 31 + (s[i] - 'a' + 1);
            pow1[i] = pow1[i - 1] * 131;
            pow2[i] = pow2[i - 1] * 31;
        }
        using puu = pair<ui64, ui64>;
        map<puu, int> Hash;
        int ans = 0;
        auto gethash = [](int i, int j)->puu {
            if(i > j) return {0, 0};
            auto v1 = h1[j] - h1[i - 1] * pow1[j - i + 1];
            auto v2 = h2[j] - h2[i - 1] * pow2[j - i + 1];
            return {v1, v2};
        };
        for(int i = 1; i + 1 <= n; ++i) {
            auto res1 = gethash(1, i - 1);
            auto res2 = gethash(i + 2, n);
            auto l = n - (i + 2) + 1;
            auto res = (puu){res1.first * pow1[l] + res2.first, res1.second * pow2[l] + res2.second};
            if(Hash.find(res) == Hash.end()) {
                Hash[res] = 1;
                ++ans;
            }
        }
        cout << ans << '\n';
	}
	return 0;
}