//ID: LRL52  Date: 2023.3.2
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
using i64 = long long;
using pii = pair<int, int>;
const int N = 2e5 + 55, M = 2e3 + 55, inf = 0x3f3f3f3f;
string s[N];
int Cnt[1 << 25][2];

signed main() {
#ifdef LRL52
	freopen("F.in", "r", stdin);
#endif
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	// int Task; cin >> Task;
    int n; cin >> n;
    for(int i = 1; i <= n; ++i) cin >> s[i];
    i64 ans = 0;
    for(int k = 0; k < 26; ++k) {
        memset(Cnt, 0, sizeof(Cnt));
        for(int i = 1; i <= n; ++i) {
            int sta = 0;
            int ok = 1;
            for(auto c : s[i]) {
                sta ^= 1 << (c - 'a');
                if('a' + k == c) {
                    ok = 0;
                }
            }
            if(ok) {
                sta = ((sta >> (k + 1)) << k) + (sta & ((1 << k) - 1));
                assert(sta < (1 << 25));
                Cnt[sta][s[i].size() & 1]++;
                ans += Cnt[sta ^ ((1 << 25) - 1)][(s[i].size() & 1) ^ 1];
                assert((sta ^ ((1 << 25) - 1)) < (1 << 25));
            }
        }
    }
    cout << ans << '\n';
	return 0;
}